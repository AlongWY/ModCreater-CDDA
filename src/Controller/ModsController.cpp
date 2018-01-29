#include "ModsController.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace boost;
using namespace nlohmann;

void cdda::ModsController::load_mods(boost::filesystem::path &path) {
    filesystem::directory_iterator end;
    for (filesystem::directory_iterator iter(path); iter != end; ++iter) {
        if (filesystem::exists(iter->path() / "modinfo.json")) {
            ifstream file(iter->path().string() + "/modinfo.json");
            json jsonData;
            file >> jsonData;
            if (jsonData.is_array()) {
                for (const auto &elements:jsonData) {
                    if (elements["type"] == "MOD_INFO") {
                        ModInfo modInfo = elements;
                        mods.push_back(modInfo);
                    }
                }
            } else {
                ModInfo modInfo = jsonData;
                mods.push_back(modInfo);
            }
        }
    }
    sort(mods.begin(), mods.end());
}
