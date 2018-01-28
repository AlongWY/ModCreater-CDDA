#ifndef MODCREATER_CDDA_BIONICS_H
#define MODCREATER_CDDA_BIONICS_H

#include "Utils/json.hpp"
#include <string>
#include <vector>
#include <map>

namespace cdda {

    struct Bionics {
    public:
        std::string id;
        std::string name;
        std::string description;
        /** Power cost on activation */
        int power_activate = 0;
        /** Power cost on deactivation */
        int power_deactivate = 0;
        /** Power cost over time, does nothing without a non-zero charge_time */
        int power_over_time = 0;
        /** How often a bionic draws power while active in turns */
        int charge_time = 0;
        /** Power bank size **/
        int capacity = 0;
        /** True if a bionic is a "faulty" bionic */
        bool faulty = false;
        bool power_source = false;
        /** Is true if a bionic is an active instead of a passive bionic */
        bool activated = false;
        /** If true, then the bionic only has a function when activated, else it causes
         *  it's effect every turn.
         */
        bool toggled = false;
        /**
         * If true, this bionic is a gun bionic and activating it will fire it.
         * Prevents all other activation effects.
         */
        bool gun_bionic = false;
        /**
         * If true, this bionic is a weapon bionic and activating it will
         * create (or destroy) bionic's fake_item in user's hands.
         * Prevents all other activation effects.
         */
        bool weapon_bionic = false;
        /**
         * If true, this bionic can provide power to powered armor.
         */
        bool armor_interface = false;
        /**
         * Body part slots used to install this bionic, mapped to the amount of space required.
         */
        std::map<std::string, size_t> occupied_bodyparts;
        /**
         * Fake item created for crafting with this bionic available.
         * Also the item used for gun bionics.
         */
        std::string fake_item;
        /**
         * Mutations/trait that are removed upon installing this CBM.
         * E.g. enhanced optic bionic may cancel HYPEROPIC trait.
         */
        std::vector<std::string> canceled_mutations;
        /**
         * Additional bionics that are installed automatically when this
         * bionic is installed. This can be used to install several bionics
         * from one CBM item, which is useful as each of those can be
         * activated independently.
         */
        std::vector<std::string> included_bionics;
    };

    void to_json(nlohmann::json &j, const Bionics &b);

    void from_json(const nlohmann::json &j, Bionics &b);
}

#endif //MODCREATER_CDDA_BIONICS_H
