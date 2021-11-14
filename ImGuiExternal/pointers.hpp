#pragma once
#include "memory/pattern_scanner.h"
#include "memory/memory_handle.hpp"

namespace ellohim
{
	class pointers
	{
	public:
		explicit pointers();
		~pointers();
	public:
		DWORD64 m_ped_factory;
		DWORD64 m_script_global;
		DWORD64 m_blip_list;
		DWORD64 m_network_player_mgr;
		DWORD64 m_local_script;
		DWORD64 m_replay_interface;
		DWORD64 m_blackout;
		DWORD64 m_is_session_started;
		DWORD64 m_game_state;
		DWORD64 m_cutscene_mgr;
		DWORD64 m_script_local;
	};
}