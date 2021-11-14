#pragma once
#include "common.hpp"

namespace ellohim
{
	extern LPCSTR TargetProcess;
	extern bool ShowMenu;
	extern bool ImGui_Initialised;
	extern bool CreateConsole;

	class renderer
	{
	public:
		static void render_gui();
		static void input_handler();
		static void draw_overlay();
		static void rendering();
		static bool dx_init();
		static LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
		static void setup_window();
		static DWORD WINAPI process_check(LPVOID lpParameter);
	};
}

namespace ellohim::Process
{
	extern DWORD ID;
	extern HANDLE Handle;
	extern HWND Hwnd;
	extern WNDPROC WndProc;
	extern int WindowWidth;
	extern int WindowHeight;
	extern int WindowLeft;
	extern int WindowRight;
	extern int WindowTop;
	extern int WindowBottom;
	extern LPCSTR Title;
	extern LPCSTR ClassName;
	extern LPCSTR Path;
}

namespace ellohim::OverlayWindow
{
	extern WNDCLASSEX WindowClass;
	extern HWND Hwnd;
	extern LPCSTR Name;
}

namespace ellohim::DirectX9Interface
{
	extern IDirect3D9Ex* Direct3D9;
	extern IDirect3DDevice9Ex* pDevice;
	extern D3DPRESENT_PARAMETERS pParams;
	extern MARGINS Margin;
	extern MSG Message;
}

