#include <iostream>
#include <fstream>
#include "ModsController.h"

using namespace std;
using namespace boost;
using namespace nlohmann;

void cdda::ModsController::load_mods_info(boost::filesystem::path &path) {
    mods.clear();
    filesystem::directory_iterator end;
    for (filesystem::directory_iterator iter(path); iter != end; ++iter)
        if (filesystem::is_directory(iter->path()) && filesystem::exists(iter->path() / "modinfo.json")) {
            ModInfo modInfo;
            string mod_path = iter->path().string();
            ifstream file(mod_path + "/modinfo.json");
            json jsonData;
            file >> jsonData;
            if (jsonData.is_array()) {
                for (const auto &elements:jsonData)
                    if (elements["type"] == "MOD_INFO") {
                        modInfo = elements;
                    }
            } else if (jsonData["type"] == "MOD_INFO")
                modInfo = jsonData;
            modInfo.mod_path = mod_path;
            mods.push_back(modInfo);
        }
    sort(mods.begin(), mods.end());
}

void cdda::ModsController::load_mod_file(filesystem::path &path) {
    //todo 载入一个json文件,注意分类别载入进入不同的模型
}

void cdda::ModsController::update_item(string id) {
    //todo 根据id --> filename --> json : model >> json >> file(filename)
}

void cdda::ModsController::load_mod(int index) {
    clear();
    filesystem::path path = filesystem::path(mods[index].mod_path);
    cout << "-----------" << mods[index].name << "-----------" << endl;
    if (filesystem::exists(path)) {
        filesystem::recursive_directory_iterator end;
        for (filesystem::recursive_directory_iterator iter(path); iter != end; ++iter) {
            // todo 对文件的后缀名做判断而后将文件路径和文件名载入
            std::cout << iter->path() << endl;
        }
    }
}

void cdda::ModsController::clear() {
    file.clear();
    path.clear();
    json_data.clear();
}
