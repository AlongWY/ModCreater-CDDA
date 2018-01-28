#include <QApplication>
#include <QtCore/QTranslator>
#include "Model/ModInfo.h"
#include "View/MainWindow.h"

using json = nlohmann::json;
using namespace cdda;

int main(int argv, char **argc) {
    QApplication app(argv, argc);
    app.setWindowIcon(QIcon(":ICON"));
    QTranslator translator;
    if (translator.load(QLocale(), QLatin1String("lang"), QLatin1String("_"), QLatin1String("lang"))) {
        app.installTranslator(&translator);
    }
    MainWindow window;
    window.show();
    return app.exec();
}
