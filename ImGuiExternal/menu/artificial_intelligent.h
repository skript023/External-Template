#pragma once

namespace ellohim
{
	class bot_menu
	{
	public:
		static void render_bot_menu();
	private:
		static inline int current_area = 0;
		static inline const char* const area_list[] = { "Planar Gate", "Ancient Dragon", "Reverse Theater" , "Purification Ops" , "Busan" };
		static inline bool test = false;
	};

	inline static bot_menu g_bot;
}