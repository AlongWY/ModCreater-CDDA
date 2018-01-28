#ifndef MODCREATER_CDDA_MATERIAL_H
#define MODCREATER_CDDA_MATERIAL_H

#include <Utils/json.hpp>
#include <string>
#include <vector>

namespace cdda {

    struct mat_burn_data {
        /** If this is true, an object will not burn or be destroyed by fire. */
        bool immune = false;
        /** Chance of burning per unit volume of the object, per turn. 0 for 100% chance */
        int chance_in_volume = 0;
        /** Fuel contributed per tick when this material burns. */
        float fuel = 0.0f;
        /** Smoke produced per tick when this material burns. */
        float smoke = 0.0f;
        /** Volume of material destroyed per tick when this material burns. */
        float burn = 0.0f;
    };

    struct Material {
    public:
        std::string id;
        std::string name;
        std::string salvaged_into = "null";
        std::string repaired_with = "null";
        bool edible = false;
        bool soft = false;
        int bash_resist = 0;                         // negative integers means susceptibility
        int cut_resist = 0;
        int acid_resist = 0;
        int elec_resist = 0;
        int fire_resist = 0;
        int chip_resist = 0;                         // Resistance to physical damage of the item itself
        int density = 1;                             // relative to "powder", which is 1
        std::string cut_dmg_verb;
        std::string bash_dmg_verb;
        std::vector<std::string> dmg_adj;
        std::vector<mat_burn_data> burn_data;
        std::map<std::string, double> vitamins;

    };

    void to_json(nlohmann::json &j, const Material &m);

    void from_json(const nlohmann::json &j, Material &m);

    void to_json(nlohmann::json &j, const mat_burn_data &m);

    void from_json(const nlohmann::json &j, mat_burn_data &m);

}
#endif //MODCREATER_CDDA_MATERIAL_H
