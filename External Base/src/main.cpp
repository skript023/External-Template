#include "renderer.hpp"
#include "Functions.h"
#include "memory/process.hpp"
#include "pointers.hpp"
#include "common.hpp"
#include "file_manager.hpp"

//int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)

inline uint32_t find_game_id() 
{
	auto win = ellohim::functions::GetProcessId(ellohim::TargetProcess); //::FindWindowA("grcWindow", nullptr);
	if (!win) 
	{
		LOG(INFO) << "Cannot find game window" << std::endl;
	}

	//DWORD a;
	//::GetWindowThreadProcessId(win, &a);

	return win;
}

int main()
{
	using namespace ellohim;
	if (CreateConsole == false)
		ShowWindow(GetConsoleWindow(), SW_HIDE);

	bool WindowFocus = false;
	while (WindowFocus == false)
	{
		DWORD ForegroundWindowProcessID;
		GetWindowThreadProcessId(GetForegroundWindow(), &ForegroundWindowProcessID);
		if (functions::GetProcessId(TargetProcess) == ForegroundWindowProcessID)
		{
			Process::ID = GetCurrentProcessId();
			Process::Handle = GetCurrentProcess();
			Process::Hwnd = GetForegroundWindow();

			RECT TempRect;
			GetWindowRect(Process::Hwnd, &TempRect);
			Process::WindowWidth = TempRect.right - TempRect.left;
			Process::WindowHeight = TempRect.bottom - TempRect.top;
			Process::WindowLeft = TempRect.left;
			Process::WindowRight = TempRect.right;
			Process::WindowTop = TempRect.top;
			Process::WindowBottom = TempRect.bottom;

			char TempTitle[MAX_PATH];
			GetWindowText(Process::Hwnd, TempTitle, sizeof(TempTitle));
			Process::Title = TempTitle;

			char TempClassName[MAX_PATH];
			GetClassName(Process::Hwnd, TempClassName, sizeof(TempClassName));
			Process::ClassName = TempClassName;

			char TempPath[MAX_PATH];
			GetModuleFileNameEx(Process::Handle, NULL, TempPath, sizeof(TempPath));
			Process::Path = TempPath;

			WindowFocus = true;
		}
	}

	OverlayWindow::Name = "Ellohim Template";//RandomString(10).c_str();

	std::filesystem::path base_dir = std::getenv("appdata");
	base_dir /= "External";

	auto file_manager_instance = std::make_unique<file_manager>(base_dir);

	auto logger_instance = std::make_unique<logger>(
		"Ellohim Template",
		file_manager_instance->get_project_file("./cout.log")
		);

	//auto process_instance = std::make_unique<process>(find_game_id());
	LOG(INFO) << "Process initalized.";

	//auto pointers_instance = std::make_unique<pointers>();
	LOG(INFO) << "Pointers initialized.";

	auto renderer_instance = std::make_unique<renderer>();
	LOG(INFO) << "Renderer Initialized.";
	//CreateThread(0, 0, renderer::process_check, 0, 0, 0);
	while (g_running)
	{
		renderer::process_check(0);

		g_renderer->rendering();

		Sleep(0);
	}

	renderer_instance.reset();
	LOG(INFO) << "Renderer Uninitialized";

	//process_instance.reset();
	LOG(INFO) << "Process initalized.";

	//pointers_instance.reset();
	LOG(INFO) << "Pointers initialized.";
	exit(0);
}