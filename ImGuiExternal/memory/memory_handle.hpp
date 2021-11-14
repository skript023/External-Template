#pragma once
//#include "../common.hpp"

struct module
{
	DWORD64 dwBase, dwSize;
};

namespace ellohim::memory
{
	DWORD64 Base;
	DWORD pid;
	HANDLE pHandle;
	uintptr_t FindPointer(HANDLE hproc, uintptr_t ptr, std::vector<unsigned int> offsets)
	{
		uintptr_t addr = ptr;
		for (unsigned int i = 0; i < offsets.size(); i++)
		{
			ReadProcessMemory(hproc, (BYTE*)addr, &addr, sizeof(addr), 0);
			addr += offsets[i];
		}
		return addr;
	}

	INT64 readPointer(HANDLE hproc, DWORD64 Address)
	{
		INT64 value;
		ReadProcessMemory(hproc, (INT64*)Address, &value, sizeof(value), 0);
		return value;
	}

	int readInteger(HANDLE hproc, DWORD64 Address)
	{
		int value;
		ReadProcessMemory(hproc, (BYTE*)Address, &value, sizeof(value), 0);
		return value;
	}

	struct module
	{
		DWORD64 dwBase, dwSize;
	};

	module TargetModule;
	HANDLE TargetProcess;
	DWORD64  TargetId;

	HANDLE GetProcess(const wchar_t* processName)
	{
		HANDLE handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
		PROCESSENTRY32W entry;
		entry.dwSize = sizeof(entry);

		do
			if (!_wcsicmp(entry.szExeFile, processName))
			{
				TargetId = entry.th32ProcessID;
				CloseHandle(handle);
				TargetProcess = OpenProcess(PROCESS_ALL_ACCESS, false, TargetId);
				return TargetProcess;
			}
		while (Process32NextW(handle, &entry));

		return NULL;
	}

	template <typename var>
	bool WriteMemory(DWORD64 Address, var Value)
	{
		return WriteProcessMemory(TargetProcess, (LPVOID)Address, &Value, sizeof(var), 0);
	}

	template <typename var>
	var ReadMemory(DWORD64 Address)
	{
		var value;
		ReadProcessMemory(TargetProcess, (LPCVOID)Address, &value, sizeof(var), NULL);
		return value;
	}

	bool MemoryCompare(const BYTE* bData, const BYTE* bMask, const char* szMask)
	{
		for (; *szMask; ++szMask, ++bData, ++bMask)
		{
			if (*szMask == 'x' && *bData != *bMask)
			{
				return false;
			}
		}
		return (*szMask == NULL);
	}

	uintptr_t GetModuleBaseAddress(DWORD procId, const wchar_t* modName)
	{
		uintptr_t modBaseAddr = 0;
		HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);
		if (hSnap != INVALID_HANDLE_VALUE)
		{
			MODULEENTRY32W modEntry;
			modEntry.dwSize = sizeof(modEntry);
			if (Module32FirstW(hSnap, &modEntry))
			{
				do
				{
					if (!_wcsicmp(modEntry.szModule, modName))
					{
						modBaseAddr = (uintptr_t)modEntry.modBaseAddr;
						break;
					}
				} while (Module32NextW(hSnap, &modEntry));
			}
		}
		CloseHandle(hSnap);
		return modBaseAddr;
	}

	module GetModule(const wchar_t* moduleName) {
		HANDLE hmodule = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, TargetId);
		MODULEENTRY32W mEntry;
		mEntry.dwSize = sizeof(mEntry);

		do {
			if (!_wcsicmp(mEntry.szModule, moduleName)) {//_tcscmp
				CloseHandle(hmodule);

				TargetModule = { (DWORD64)mEntry.hModule, mEntry.modBaseSize };
				return TargetModule;
			}
		} while (Module32NextW(hmodule, &mEntry));

		module mod = { (DWORD64)false, (DWORD64)false };
		return mod;
	}
}