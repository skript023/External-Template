#include "pattern_scanner.h"
#include "memory_handle.hpp"

namespace ellohim
{
	pattern_scan::pattern_scan(const char* sig, const char* mask)
	{
		SIZE_T bytesRead;
		HWND hWnd = FindWindowA(0, "Grand Theft Auto V");
		GetWindowThreadProcessId(hWnd, &pid);
		handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
		
		auto mod = memory::GetModule(L"GTA5.exe");

		BYTE* data = new BYTE[mod.dwSize];

		if (HANDLE TargetProcess = memory::GetProcess(L"GTA5.exe"))
		{
			ReadProcessMemory(TargetProcess, (LPVOID)mod.dwBase, data, mod.dwSize, &bytesRead);

			for (DWORD64 i = 0; i < mod.dwSize; i++)
			{
				if (ellohim::memory::MemoryCompare((const BYTE*)(data + i), (const BYTE*)sig, mask))
				{
					pattern_scan::address = mod.dwBase + i;
				}
			}
			delete[] data;
		}
	}

	pattern_scan pattern_scan::add(int offset)
	{
		pattern_scan::address += offset;
	}

	pattern_scan pattern_scan::sub(int offset)
	{
		pattern_scan::address -= offset;
	}

	pattern_scan pattern_scan::rip()
	{
		add(memory::readInteger(handle, pattern_scan::address) + 4);
	}

	DWORD64 pattern_scan::scan()
	{
		return pattern_scan::address;
	}

	
}