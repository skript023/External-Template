#include "pointers.hpp"
#include "memory/pattern.hpp"

namespace ellohim
{
	pointers::pointers():
		m_is_session_started(pattern("Is Session Started", "40 38 35 ? ? ? ? 75 0E 4C 8B C3 49 8B D7 49 8B CE").add(3).rip()),
		m_ped_factory(pattern("Ped Factory", "48 8B 05 ? ? ? ? 48 8B 48 08 48 85 C9 74 52 8B 81").add(3).rip()),
		m_script_globals(pattern("Script Globals", "4C 8D 05 ? ? ? ? 4D 8B 08 4D 85 C9 74 11").add(3).rip()),
		m_blip_list(pattern("Blip List", "4C 8D 05 ? ? ? ? 0F B7 C1").add(3).rip()),
		m_network_player_mgr(pattern("Network player manager", "48 8B 0D ? ? ? ? E8 ? ? ? ? 48 8B C8 E8 ? ? ? ? 48 8B CF").add(3).rip()),
		m_script_local(pattern("Script Locals", "48 8B 05 ? ? ? ? 8B CF 48 8B 0C C8 39 59 68").add(3).rip()),
		m_replay_interface(pattern("Replay Interface", "48 8D 0D ? ? ? ? 48 8B D7 E8 ? ? ? ? 48 8D 0D ? ? ? ? 8A D8 E8 ? ? ? ? 84 DB 75 13 48 8D 0D ? ? ? ?")),
		m_blackout(pattern("Blackout", "48 8B D7 48 8B CB E8 ? ? ? ? 40 38 35 ? ? ? ? 74 40").add(14).rip()),
		m_game_state(pattern("Game State", "48 85 C9 74 4B 83 3D").add(7).rip()),
		m_cutscene_mgr(pattern("Cutscene Manager", "48 8B 0D ? ? ? ? 48 8B 01 48 FF 60 28").add(3).rip())
	{
		g_pointers = this;
	}

	pointers::~pointers()
	{
		g_pointers = nullptr;
	}
}