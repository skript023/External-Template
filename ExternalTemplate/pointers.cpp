//#include "pointers.hpp"

namespace ellohim
{
	pointers::pointers()
	{
		LPCSTR ped_factory_sig = "\x48\x8b\x05\x00\x00\x00\x00\x45\x00\x00\x00\x00\x48\x8b\x48\x08\x48\x85\xc9\x74\x07";
		LPCSTR pad_factory_mask = "xxx????x????xxxxxxxxx";

		LPCSTR blip_list_sig = "\x4c\x8d\x05\x00\x00\x00\x00\x0f\xb7\xc1";
		LPCSTR blip_list_mask = "xxx????xxx";

		LPCSTR m_network_player_mgr_sig = "\x48\x8b\x0d\x00\x00\x00\x00\xe8\x00\x00\x00\x00\x48\x8b\xc8\xe8\x00\x00\x00\x00\x48\x8b\xcf";
		LPCSTR m_network_player_mgr_mask = "xxx????x????xxxx????xxx";

		LPCSTR script_global_sig = "\x4c\x8d\x05\x00\x00\x00\x00\x4d\x8b\x08\x4d\x85\xc9\x74\x11";
		LPCSTR script_global_mask = "xxx????xxxxxxxx";

		LPCSTR local_script_sig = "\x48\x8B\x05\x00\x00\x00\x00\x8B\xCF\x48\x8B\x0C\xC8\x39\x59\x68";
		LPCSTR local_script_mask = "xxx????xxxxxxxxx";

		m_ped_factory = pattern_scan(ped_factory_sig, pad_factory_mask).add(3).rip().scan();
		m_blip_list = pattern_scan(ped_factory_sig, pad_factory_mask).add(3).rip().scan();
		m_network_player_mgr = pattern_scan(ped_factory_sig, pad_factory_mask).add(3).rip().scan();
		m_script_global = pattern_scan(ped_factory_sig, pad_factory_mask).add(3).rip().scan();
		m_ped_factory = pattern_scan(ped_factory_sig, pad_factory_mask).add(3).rip().scan();
		m_script_local = pattern_scan(local_script_sig, local_script_mask).add(3).rip().scan();
	}
}