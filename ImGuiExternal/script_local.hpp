#pragma once
#include "common.hpp"
#include "utility/joaat.hpp"

namespace ellohim
{
	class script_local
	{
	public:
		explicit script_local(uint64_t stack, std::size_t index);

		script_local at(std::ptrdiff_t index);
		script_local at(std::ptrdiff_t index, std::size_t size);

		template <typename T>
		std::enable_if_t<std::is_pointer_v<T>, T> as()
		{
			auto result = g_process->read<uintptr_t>(m_stack) + (0x8 * m_index);
			return g_process->read<T>(result);
		}

		template <typename T>
		std::enable_if_t<std::is_lvalue_reference_v<T>, T> as(T value = NULL)
		{
			auto result = g_process->read<uintptr_t>(m_stack) + (0x8 * m_index);
			return g_process->write(result, value);
		}
	private:
		void* get();
		std::size_t m_index;
		uint64_t m_stack;
	};
}
