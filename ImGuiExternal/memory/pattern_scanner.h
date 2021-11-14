#pragma once

namespace ellohim
{
	class pattern_scan
	{
	public:
		pattern_scan(const char* sig, const char* mask);
	public:
		DWORD64 address = 0;
		DWORD pid = 0;
		HANDLE handle = NULL;
		pattern_scan add(int offset);
		pattern_scan sub(int offset);
		pattern_scan rip();
		DWORD64 scan();
	};
}