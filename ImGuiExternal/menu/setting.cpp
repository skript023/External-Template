#include "setting.h"
#include "../ImGui/imgui.h"
#include "../bot_function.hpp"


namespace ellohim
{
    void setting::render_setting_menu()
    {
        if (ImGui::BeginTabItem("Setting"))
        {
            if (ImGui::Button("Quit"))
            {
                exit(0);
            }

            ImGui::EndTabItem();
        }
    }
}