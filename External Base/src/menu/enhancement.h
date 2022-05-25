#pragma once
#include <script_global.hpp>

namespace ellohim
{
	class enhancement_menu
	{
	public:
		static void render_enhacement_menu();
	private:
		static void change_session(int sessionId)
		{
			if (sessionId == -1)
			{
				script_global(1574589).at(2).as(-1);
				script_global(1574589).as(1);
				Sleep(200);
				script_global(1574589).as(0);
				script_global(2676084).as(false);
			}
			else if (sessionId == 13)
			{
				script_global(1575012).as(sessionId);
				script_global(1574589).as(1);
				Sleep(200);
				script_global(1574589).as(0);
				script_global(2676084).as(true);
			}
			else
			{
				script_global(1575012).as(sessionId);
				script_global(1574589).as(1);
				Sleep(200);
				script_global(1574589).as(0);
				script_global(2676084).as(false);
			}
		}
		static inline bool enhancement_success = false;
		static inline bool no_fuel = false;
		static inline bool no_vaccine = false;

		static inline int current_enhancement = 0;
		static inline const char* const enhancement_list[] = { "+1", "+2", "+3" , "+4" , "+5", "+6", "+7", "+8", "+9", "+10", "+11", "+12", "+13", "+14", "+15", "+16", "+17", "+18", "+19", "+20", "+21", "+22"};
	};

	inline static enhancement_menu g_enhancement;
}