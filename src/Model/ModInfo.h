#ifndef MODCREATER_CDDA_MODINFO_H
#define MODCREATER_CDDA_MODINFO_H

#include "Utils/json.hpp"
#include <string>
#include <vector>

namespace cdda {

    struct ModInfo {
    public:
        std::string id;
        std::string name;
        std::string category;
        std::string description;

        bool core = false;
        bool obsolete = false;

        /** Directory to load JSON and Lua from relative to directory containing modinfo.json */
        std::string path;

        /** If set load legacy migrations from this location dependent upon save version */
        std::string legacy;

        /** All authors who have added content to the mod (excluding maintenance changes) */
        std::vector<std::string> authors;

        /**
         *  Assigned maintainers responsible for maintaining compatibility with core
         *  @note these should be verbatim GH account names
         */
        std::vector<std::string> maintainers;

        /** What other mods must be loaded prior to this one? */
        std::vector<std::string> dependencies;
    };

    void to_json(nlohmann::json &j, const ModInfo &m);

    void from_json(const nlohmann::json &j, ModInfo &m);

}
#endif //MODCREATER_CDDA_MODINFO_H
