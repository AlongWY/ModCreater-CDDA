#include "ModInfo.h"
#include "Utils/macro.h"

using json = nlohmann::json;
using namespace cdda;

void cdda::to_json(json &j, const ModInfo &m) {
    j["type"] = "MOD_INFO";
    J_GET_CHECK(j, m, name);
    J_GET_CHECK(j, m, category);
    J_GET_CHECK(j, m, description);
    J_GET_CHECK_DIF(j, m, id, ident);

    J_GET_VEC(j, m, authors);
    J_GET_VEC(j, m, maintainers);
    J_GET_VEC(j, m, dependencies);

    J_GET_STRING(j, m, path);
    J_GET_STRING(j, m, legacy);
    J_GET_OPTIONAL(j, m, core, false);
    J_GET_OPTIONAL(j, m, obsolete, false);
}

void cdda::from_json(const json &j, ModInfo &m) {
    assert(!j.is_array() && j["type"] == "MOD_INFO");

    D_GET_CHECK(j, m, core);
    D_GET_CHECK(j, m, name);
    D_GET_CHECK(j, m, path);
    D_GET_CHECK(j, m, legacy);
    D_GET_CHECK(j, m, category);
    D_GET_CHECK(j, m, obsolete);
    D_GET_CHECK(j, m, description);
    D_GET_CHECK_DIF(j, m, id, ident);
    D_GET_VEC_CHECK(j, m, authors);
    D_GET_VEC_CHECK(j, m, maintainers);
    D_GET_VEC_CHECK(j, m, dependencies);
}

bool ModInfo::operator<(const ModInfo &rhs) const {
    if (name < rhs.name)
        return true;
    if (rhs.name < name)
        return false;
    return id < rhs.id;
}

bool ModInfo::operator>(const ModInfo &rhs) const {
    return rhs < *this;
}

bool ModInfo::operator<=(const ModInfo &rhs) const {
    return !(rhs < *this);
}

bool ModInfo::operator>=(const ModInfo &rhs) const {
    return !(*this < rhs);
}
