#ifndef MODCREATER_CDDA_MODSCONTROLLER_H
#define MODCREATER_CDDA_MODSCONTROLLER_H

#include <map>
#include <string>
#include <boost/filesystem.hpp>
#include <Model/ModInfo.h>

namespace cdda {

    class ModsController {
        friend class MainWindow;

    public:
        // 从某个路径载入所有的mod的modinfo
        void load_mods_info(boost::filesystem::path &path);

        // 把一个mod的文件全部载入
        void load_mod_file(boost::filesystem::path &path);

        // 按照modinfo序列的信息载入一个mod，并把上一个载入mod的信息清除
        void load_mod(int index);

        // 按照id更新一个表项
        void update_item(std::string id);

    private:
        void clear();

    private:
        std::vector<ModInfo> mods;

        // For other uses
        /** id to filename */
        std::map<std::string, std::string> file;
        /** file name to path */
        std::map<std::string, boost::filesystem::path> path;
        /** file name to json */
        std::map<std::string, nlohmann::json> json_data;
    };

}
#endif //MODCREATER_CDDA_MODSCONTROLLER_H
