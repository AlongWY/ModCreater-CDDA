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
        void load_mods(boost::filesystem::path &path);

    private:
        std::vector<ModInfo> mods;
    };

}
#endif //MODCREATER_CDDA_MODSCONTROLLER_H
