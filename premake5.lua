workspace "External Base"
  architecture "x64"
  startproject "External Base"

  configurations
  {
    "Debug",
    "Release",
    "Dist"
  }

  outputdir = "%{cfg.buildcfg}"

  IncludeDir = {}
  IncludeDir["ImGui"] = "vendor/ImGui"
  IncludeDir["g3log"] = "vendor/g3log/src"
  
  CppVersion = "C++20"
  MsvcToolset = "v143"
  WindowsSdkVersion = "10.0"
  
  function DeclareMSVCOptions()
    filter "system:windows"
    staticruntime "Off"
	  floatingpoint "Fast"
	  vectorextensions "AVX2"
    systemversion (WindowsSdkVersion)
    toolset (MsvcToolset)
    cppdialect (CppVersion)
    characterset("MBCS")
    warnings "Off"

    defines
    {
      "_CRT_SECURE_NO_WARNINGS",
      "NOMINMAX",
      "WIN32_LEAN_AND_MEAN",
      "_WIN32_WINNT=0x601" -- Support Windows 7
    }
    
    disablewarnings
    {
      "4100", -- C4100: unreferenced formal parameter
      "4201", -- C4201: nameless struct/union
      "4307",  -- C4307: integral constant overflow
      "4996"  -- C4996: deprecated in C++17
    }
  end
  
  function file_exists(name)
   local f=io.open(name,"r")
   if f~=nil then io.close(f) return true else return false end
  end
   
  function DeclareDebugOptions()
    filter "configurations:Debug"
      defines { "_DEBUG" }
      symbols "On"
    filter "not configurations:Debug"
      defines { "NDEBUG" }
  end
   
  project "ImGui"
    location "vendor/%{prj.name}"
    kind "StaticLib"
    language "C++"

    targetdir ("bin/lib/" .. outputdir)
    objdir ("bin/lib/int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
      "vendor/%{prj.name}/imgui.cpp",
      "vendor/%{prj.name}/imgui_demo.cpp",
      "vendor/%{prj.name}/imgui_draw.cpp",
      "vendor/%{prj.name}/imgui_tables.cpp",
      "vendor/%{prj.name}/imgui_widgets.cpp",
      "vendor/%{prj.name}/backends/imgui_impl_dx9.cpp",
      "vendor/%{prj.name}/backends/imgui_impl_win32.cpp",
      "vendor/%{prj.name}/backends/imgui_impl_dx9.h",
      "vendor/%{prj.name}/backends/imgui_impl_win32.h"
    }

    includedirs
    {
      "vendor/%{prj.name}"
    }

    DeclareMSVCOptions()
    DeclareDebugOptions()
	
  project "g3log"
    location "vendor/%{prj.name}"
    kind "StaticLib"
    language "C++"

    targetdir ("bin/lib/" .. outputdir)
    objdir ("bin/lib/int/" .. outputdir .. "/%{prj.name}")
	
	  includedirs
    {
      "vendor/%{prj.name}/src"
    }

	  if(file_exists("vendor\\g3log\\src\\g3log\\generated_definitions.hpp") == false) then
		  file = io.open("vendor\\g3log\\src\\g3log\\generated_definitions.hpp", "w")
		  if(file == nil) then
			  premake.error("Failed to locate vendor directories. Try doing git pull --recurse-submodules.")
		  end
		  file:write("// AUTO GENERATED MACRO DEFINITIONS FOR G3LOG\n\n\n/* ==========================================================================\n*2015 by KjellKod.cc. This is PUBLIC DOMAIN to use at your own risk and comes\n* with no warranties. This code is yours to share, use and modify with no\n\n*strings attached and no restrictions or obligations.\n* \n* For more information see g3log/LICENSE or refer refer to http://unlicense.org\n\n*============================================================================*/\n#pragma once\n\n\n// CMake induced definitions below. See g3log/Options.cmake for details.");
	  end
	
    files
     {
       "vendor/%{prj.name}/src/**.hpp",
       "vendor/%{prj.name}/src/**.cpp"
     }
	
	  removefiles
	  {
  	  "vendor/%{prj.name}/src/crashhandler_unix.cpp"
  	}

    DeclareMSVCOptions()
    DeclareDebugOptions()

  project "External Base"
    location "External Base"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir)
    objdir ("bin/int/" .. outputdir .. "/%{prj.name}")

    PrecompiledHeaderInclude = "common.hpp"
    PrecompiledHeaderSource = "%{prj.name}/src/common.cpp"
 
    files
    {
      "%{prj.name}/src/**.hpp",
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp",
      "%{prj.name}/src/**.asm",
      "%{prj.name}/src/**.rc"
    }

    includedirs
    {
      "%{IncludeDir.ImGui}",
      "%{IncludeDir.g3log}",
      "%{prj.name}/src"
    }

    libdirs
    {
      "bin/lib"
    }

    links
    {
      "ImGui",
      "g3log"
    }

    pchheader "%{PrecompiledHeaderInclude}"
    pchsource "%{PrecompiledHeaderSource}"
    targetname "External Base"

    forceincludes
    {
      "%{PrecompiledHeaderInclude}"
    }

    DeclareMSVCOptions()
    DeclareDebugOptions()

    flags { "NoImportLib", "Maps" }

    filter "configurations:Debug"
	  flags { "LinkTimeOptimization", "MultiProcessorCompile" }
	  editandcontinue "Off"
      defines { "EXTERNAL_DEBUG" }

    filter "configurations:Release"
	  flags { "LinkTimeOptimization", "NoManifest", "MultiProcessorCompile" }
      defines { "EXTERNAL_RELEASE" }
      optimize "speed"
    filter "configurations:Dist"
      flags { "LinkTimeOptimization", "FatalWarnings", "NoManifest", "MultiProcessorCompile" }
      defines { "EXTERNAL_DIST" }
      optimize "speed"
