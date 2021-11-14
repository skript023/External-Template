#pragma once

namespace ellohim
{
	class enhancement_menu
	{
	public:
		static void render_enhacement_menu();
	public:
		static inline bool enhancement_success = false;
		static inline bool no_fuel = false;
		static inline bool no_vaccine = false;
	};

	inline static enhancement_menu g_enhancement;
}