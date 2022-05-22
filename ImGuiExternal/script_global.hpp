#pragma once
#include "common.hpp"

namespace ellohim
{
	class script_global
	{
	public:
		explicit script_global(std::size_t index);

		script_global at(std::ptrdiff_t index);
		script_global at(std::ptrdiff_t index, std::size_t size);

		template <typename T>
		T as()
		{
			auto a = (8 * (m_index & 0x3FFFF);
			auto b = g_pointers->m_script_globals + (8 * (m_index >> 0x12 & 0x3F));
			auto result = g_process->read<uint64_t>(global_index) + a) + b;
			return static_cast<T>(g_process->read<T>(result));
		}

		template <typename T>
		void as(T value = NULL)
		{
			auto a = (8 * (m_index & 0x3FFFF);
			auto b = g_pointers->m_script_globals + (8 * (m_index >> 0x12 & 0x3F));
			auto result = g_process->read<uint64_t>(global_index) + a) + b;
			g_process->write(result, value)
		}
	private:
		void* get();
		std::size_t m_index;
	};
}
