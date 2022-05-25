#include "bot_function.hpp"
#include "artificial_intelligent.h"
#include "imgui.h"
#include "bot_function.hpp"

namespace ellohim
{
	void bot_menu::render_bot_menu()
	{
        if (ImGui::BeginTabItem("Bot Option"))
        {
            ImGui::Text("Auto Play");
            ImGui::Combo("##Auto Area", &current_area, area_list, IM_ARRAYSIZE(area_list));
            if (ImGui::Button("Set Auto Play"))
            {
                bot::run_bot_through_map(area_list[current_area], true);
            }
            ImGui::SameLine();
            if (ImGui::Button("Disable Auto Play"))
            {
                bot::run_bot_through_map(area_list[current_area], false);
            }
            
            ImGui::Checkbox("Bypass Captcha", &test);

            ImGui::EndTabItem();
        }
	}
}