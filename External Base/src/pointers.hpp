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
		pointer<bool> m_is_session_started;
		pointer<uint64_t> m_ped_factory;
		pointer<uint64_t> m_script_globals;
		pointer<uint64_t> m_blip_list;
		pointer<uint64_t> m_network_player_mgr;
		pointer<uint64_t> m_script_local;
		pointer<uint64_t> m_replay_interface;
		pointer<uint64_t> m_blackout;
		pointer<uint64_t> m_game_state;
		pointer<uint64_t> m_cutscene_mgr;
	};

	inline pointers* g_pointers;
}