#include "pointers.hpp"
#include "memory/pattern.hpp"

namespace ellohim
{
	pointers::pointers():
		m_enhancement_transfer(pattern("Enhancement Transfer", "4C 8D 05 ? ? ? ? BA ? ? ? ? 48 8D 4C 24 ? FF 15 ? ? ? ? 45 32 ED").add(3).rip())

	{
		g_pointers = this;
	}

	pointers::~pointers()
	{
		g_pointers = nullptr;
	}
}