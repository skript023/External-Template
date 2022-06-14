#pragma once
#include "pointer.hpp"

namespace ellohim
{
	class pointers
	{
	public:
		explicit pointers();
		~pointers();
	public:
		pointer<uint64_t> m_enhancement_transfer;
	};

	inline pointers* g_pointers;
}