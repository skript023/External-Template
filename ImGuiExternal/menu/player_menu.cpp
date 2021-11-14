#include "player_menu.h"
#include "../ImGui/imgui.h"
#include "../bot_function.hpp"

namespace ellohim
{
    void player_menu::render_player_tab()
    {
        if (ImGui::BeginTabItem("Player Option"))
        {
            ImGui::Checkbox("Godmode", &godmode);
            ImGui::SameLine(150);
            ImGui::Checkbox("Infinite MP", &infinite_mp);
            ImGui::SameLine(300);
            ImGui::Checkbox("Auto Heal", &auto_heal);

            ImGui::Checkbox("No Cooldown", &no_cooldown);
            ImGui::SameLine(150);
            ImGui::Checkbox("Infinite Buff", &infinite_buff);
            ImGui::SameLine(300);
            ImGui::Checkbox("Freeze Enemy", &freeze_enemy);

            ImGui::Checkbox("One Hitkill", &one_hit);
            ImGui::SameLine(150);
            ImGui::Checkbox("Infinite Potion", &infinite_potion);
            ImGui::SameLine(300);
            ImGui::Checkbox("No Clip", &no_clip);

            ImGui::SliderInt("Physical Attack Power", &physical_attack, 0, INT32_MAX);
            ImGui::SliderInt("Magical Attack Power", &magical_attack, 0, INT32_MAX);

            ImGui::SliderFloat("Critical Damage Multiplier (Physics)", &crit_damage_p, 0.0f, 1000000.f);
            ImGui::SliderFloat("Critical Damage Multiplier (Magic)", &crit_damage_m, 0.0f, 1000000.f);
            ImGui::SliderFloat("Critical Damage Multiplier (Aerial)", &crit_damage_a, 0.0f, 1000000.f);
            ImGui::SliderFloat("Critical Damage Multiplier (Back)", &crit_damage_b, 0.0f, 1000000.f);
            ImGui::SliderFloat("Critical Damage Multiplier (Chase)", &crit_damage_c, 0.0f, 1000000.f);


            ImGui::SliderInt("Physical Raw Defense", &physical_deff, 0, INT32_MAX);
            ImGui::SliderInt("Magical Raw Defense", &magical_deff, 0, INT32_MAX);


            ImGui::EndTabItem();
        }
    }
}