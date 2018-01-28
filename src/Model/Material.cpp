#include "Material.h"
#include "Utils/macro.h"

using json = nlohmann::json;
using namespace cdda;

void cdda::to_json(json &j, const Material &m) {
    j["type"] == "material";

    J_GET_CHECK(j, m, name);
    J_GET_CHECK(j, m, bash_resist);
    J_GET_CHECK(j, m, cut_resist);
    J_GET_CHECK(j, m, elec_resist);
    J_GET_CHECK(j, m, fire_resist);
    J_GET_CHECK(j, m, chip_resist);
    J_GET_CHECK(j, m, density);
    J_GET_CHECK(j, m, bash_dmg_verb);
    J_GET_CHECK(j, m, cut_dmg_verb);

    J_GET_VEC(j, m, dmg_adj);
    J_GET_VEC(j, m, burn_data);
    J_GET_MAP(j, m, vitamins);

    J_GET_OPTIONAL(j, m, salvaged_into, "null");
    J_GET_OPTIONAL(j, m, repaired_with, "null");
    J_GET_OPTIONAL(j, m, edible, false);
    J_GET_OPTIONAL(j, m, soft, false);
}

void cdda::from_json(const json &j, Material &m) {
    assert(!j.is_array() && j["type"] == "material");

    D_GET_CHECK(j, m, name);
    D_GET_CHECK(j, m, bash_resist);
    D_GET_CHECK(j, m, cut_resist);
    D_GET_CHECK(j, m, elec_resist);
    D_GET_CHECK(j, m, fire_resist);
    D_GET_CHECK(j, m, chip_resist);
    D_GET_CHECK(j, m, density);

    D_GET_CHECK(j, m, salvaged_into);
    D_GET_CHECK(j, m, repaired_with);
    D_GET_CHECK(j, m, edible);
    D_GET_CHECK(j, m, soft);
    D_GET_CHECK(j, m, bash_dmg_verb);
    D_GET_CHECK(j, m, cut_dmg_verb);

    D_GET_VEC_CHECK(j, m, dmg_adj);
    D_GET_VEC_CHECK(j, m, burn_data);
    D_GET_MAP_CHECK(j, m, vitamins);
}

void cdda::to_json(nlohmann::json &j, const mat_burn_data &m) {
    J_GET_OPTIONAL(j, m, fuel, 0.0f);
    J_GET_OPTIONAL(j, m, burn, 0.0f);
    J_GET_OPTIONAL(j, m, smoke, 0.0f);
    J_GET_OPTIONAL(j, m, immune, false);
    J_GET_OPTIONAL_DIF(j, m, chance_in_volume, chance, 0);
}

void cdda::from_json(const nlohmann::json &j, mat_burn_data &m) {
    D_GET_CHECK(j, m, fuel);
    D_GET_CHECK(j, m, burn);
    D_GET_CHECK(j, m, smoke);
    D_GET_CHECK(j, m, immune);
    D_GET_CHECK_DIF(j, m, chance_in_volume, chance);
}
