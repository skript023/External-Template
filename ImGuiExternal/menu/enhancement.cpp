#include "enhancement.h"
#include "../ImGui/imgui.h"
#include "../bot_function.hpp"


namespace ellohim
{
    void enhancement_menu::render_enhacement_menu()
    {
        if (ImGui::BeginTabItem("Enhancement"))
        {
            static int current_area = 0;
            static const char* const area_list[] = { "+1", "+2", "+3" , "+4" , "+5", "+6", "+7", "+8", "+9", "+10", "+11", "+12", "+13", "+14", "+15", "+16", "+17", "+18", "+19", "+20" };
            ImGui::Text("Enhancement Effect Changer");
            ImGui::Combo("##Auto Area", &current_area, area_list, IM_ARRAYSIZE(area_list));
            if (ImGui::Button("Change Effect"))
            {
                bot::run_bot_through_map(area_list[current_area], true);
            }
            ImGui::SameLine();
            if (ImGui::Button("Disable Effect"))
            {
                bot::run_bot_through_map(area_list[current_area], false);
            }

            ImGui::Checkbox("Add 100% enhancement rate", &enhancement_success);
            ImGui::SameLine(150);
            ImGui::Checkbox("Infinite Fuel", &no_fuel);
            ImGui::SameLine(300);
            ImGui::Checkbox("Infinite Vaccine", &no_vaccine);

            ImGui::Button("Add Super Grade 100%");

            ImGui::EndTabItem();
        }
    }
}