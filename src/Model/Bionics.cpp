#include "Bionics.h"
#include "Utils/macro.h"

using json = nlohmann::json;
using namespace cdda;

void cdda::to_json(json &j, const Bionics &b) {
    j["type"] = "bionic";
    J_GET_CHECK(j, b, id);
    J_GET_CHECK(j, b, name);
    J_GET_CHECK(j, b, faulty);
    J_GET_CHECK(j, b, toggled);
    J_GET_CHECK(j, b, capacity);
    J_GET_CHECK(j, b, fake_item);
    J_GET_CHECK(j, b, gun_bionic);
    J_GET_CHECK(j, b, power_source);
    J_GET_CHECK(j, b, weapon_bionic);
    J_GET_CHECK(j, b, armor_interface);
    J_GET_CHECK_DIF(j, b, activated, active)
    J_GET_CHECK_DIF(j, b, charge_time, time);
    J_GET_CHECK_DIF(j, b, power_activate, act_cost);
    J_GET_CHECK_DIF(j, b, power_over_time, react_cost);
    J_GET_CHECK_DIF(j, b, power_deactivate, deact_cost);
    J_GET_VEC(j, b, included_bionics);
    J_GET_VEC(j, b, canceled_mutations);
    J_GET_MAP(j, b, occupied_bodyparts);
}

void cdda::from_json(const json &j, Bionics &b) {
    assert(!j.is_array() && j["type"] == "bionic");
    D_GET_CHECK(j, b, id);
    D_GET_CHECK(j, b, name);
    D_GET_CHECK(j, b, faulty);
    D_GET_CHECK(j, b, toggled);
    D_GET_CHECK(j, b, capacity);
    D_GET_CHECK(j, b, fake_item);
    D_GET_CHECK(j, b, gun_bionic);
    D_GET_CHECK(j, b, power_source);
    D_GET_CHECK(j, b, weapon_bionic);
    D_GET_CHECK(j, b, armor_interface);
    D_GET_CHECK_DIF(j, b, activated, active)
    D_GET_CHECK_DIF(j, b, charge_time, time);
    D_GET_CHECK_DIF(j, b, power_activate, act_cost);
    D_GET_CHECK_DIF(j, b, power_over_time, react_cost);
    D_GET_CHECK_DIF(j, b, power_deactivate, deact_cost);
    D_GET_VEC_CHECK(j, b, included_bionics);
    D_GET_VEC_CHECK(j, b, canceled_mutations);
    D_GET_MAP_CHECK(j, b, occupied_bodyparts);
}
