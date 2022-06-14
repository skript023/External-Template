#pragma once
#include <windows.h>
#include <psapi.h>
#include <tlhelp32.h>
#include <iostream>
#include <dwmapi.h>
#include <d3d9.h>
#include <time.h>
#include <vector>
#include <thread>
#include <stack>

#include <chrono>
#include <atomic>
#include <optional>
#include <filesystem>
#include <fstream>
#include <map>

#include <regex>

#include <logger.hpp>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "dwmapi.lib")

namespace ellohim
{
	using namespace std::chrono_literals;
	inline std::atomic_bool g_running{ true };

	constexpr inline LPCSTR TargetProcess = "CW.EXE";
	inline bool ImGui_Initialised = false;
	inline bool CreateConsole = true;

	namespace Process
	{
		inline DWORD ID;
		inline HANDLE Handle;
		inline HWND Hwnd;
		inline WNDPROC WndProc;
		inline int WindowWidth;
		inline int WindowHeight;
		inline int WindowLeft;
		inline int WindowRight;
		inline int WindowTop;
		inline int WindowBottom;
		inline LPCSTR Title;
		inline LPCSTR ClassName;
		inline LPCSTR Path;
	}

	namespace OverlayWindow
	{
		inline WNDCLASSEX WindowClass;
		inline HWND Hwnd;
		inline LPCSTR Name;
	}

	namespace DirectX9Interface
	{
		inline IDirect3D9Ex* Direct3D9 = NULL;
		inline IDirect3DDevice9Ex* pDevice = NULL;
		inline D3DPRESENT_PARAMETERS pParams = { NULL };
		inline MARGINS Margin = { -1 };
		inline MSG Message = { NULL };
	}
}