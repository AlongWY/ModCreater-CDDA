#include <QApplication>
#include <QtCore/QTranslator>
#include <iostream>
#include "Model/ModInfo.h"
#include "View/MainWindow.h"

using json = nlohmann::json;
using namespace cdda;
using namespace std;

int main(int argv, char **argc) {
    QApplication app(argv, argc);
    app.setWindowIcon(QIcon(":ICON"));
    QTranslator translator;
    translator.load("lang_zh");
    app.installTranslator(&translator);
    MainWindow window;
    window.show();
    return app.exec();
}
