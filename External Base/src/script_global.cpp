#include "common.hpp"
#include "pointers.hpp"
#include "script_global.hpp"

namespace ellohim
{
	script_global::script_global(std::size_t index) :
		m_index(index)
	{
	}

	script_global script_global::at(std::ptrdiff_t index)
	{
		return script_global(m_index + index);
	}

	script_global script_global::at(std::ptrdiff_t index, std::size_t size)
	{
		return script_global(m_index + 1 + (index * size));
	}

	uintptr_t script_global::get()
	{
		//auto global_index = g_pointers->m_script_globals + (8 * (m_index >> 0x12 & 0x3F));
		//auto global_address = g_process->read<uint64_t>(global_index) + (8 * (m_index & 0x3FFFF));
		return 0;
	}
}
