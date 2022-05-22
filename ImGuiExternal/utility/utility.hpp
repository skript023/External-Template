#pragma once
#include <pointers.hpp>
#include <utility/joaat.hpp>

namespace ellohim::utility
{
	inline auto get_local_script(rage::joaat_t scriptHash) -> uint64_t
	{
		auto a = g_pointers->m_script_local;
		for (int i = 0; i <= 52; i++)
		{
			auto p = g_process->read<uint64_t>(g_process->read<uint64_t>(a) + (i * 0x8));
			int m_stack = g_process->read<int>(p + 0xB0);
			uint32_t m_hash = g_process->read<uint32_t>(p + 0xC);
			if (m_hash == NULL)
				continue;
			else if (m_hash == scriptHash && m_stack != 0)
				return p + 0xB0;
			return false;
		}
	}


}