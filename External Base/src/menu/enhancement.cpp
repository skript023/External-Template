#include "enhancement.h"
#include "imgui.h"
#include "bot_function.hpp"


namespace ellohim
{
    void enhancement_menu::render_enhacement_menu()
    {
        if (ImGui::BeginTabItem("Enhancement"))
        {
            ImGui::Text("Enhancement Effect Changer");
            ImGui::Combo("##Auto Area", &current_enhancement, enhancement_list, IM_ARRAYSIZE(enhancement_list));
            if (ImGui::Button("Change Effect"))
            {
                change_session(11);
            }
            ImGui::SameLine();
            if (ImGui::Button("Disable Effect"))
            {

            }

            ImGui::Checkbox("Add 100% enhancement rate", &enhancement_success);
            ImGui::Checkbox("No Fuel Required", &no_fuel);
            ImGui::Checkbox("Always Protected", &no_vaccine);

            if (ImGui::Button("Add 100% Enhancement Buff"))
            {

            }

            ImGui::EndTabItem();
        }
    }
}