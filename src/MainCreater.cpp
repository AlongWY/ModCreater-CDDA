#include <QApplication>
#include <iostream>
#include "Model/ModInfo.h"
#include "View/MainWindow.h"

using json = nlohmann::json;
using namespace cdda;
using namespace std;

const char *WINDOW_TITLE = "Mod-Creator";
const int MIN_WINDOW_WIDTH = 400;
const int MIN_WINDOW_HEIGHT = 300;

int main(int argv, char **argc) {
    QApplication app(argv, argc);
    app.setWindowIcon(QIcon(":ICON"));

    MainWindow window(WINDOW_TITLE, MIN_WINDOW_WIDTH, MIN_WINDOW_HEIGHT);
    window.show();
    return app.exec();
}
