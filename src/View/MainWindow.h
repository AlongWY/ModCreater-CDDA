#ifndef MODCREATER_CDDA_MAINWINDOW_H
#define MODCREATER_CDDA_MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

namespace cdda {

    class MainWindow : public QMainWindow {
    Q_OBJECT
    public:
        MainWindow(QString title, int min_w, int min_h);

        ~MainWindow();

    public slots:

        void OnExit();

    private:
        Ui::MainWindow *ui;
    };
}

#endif //MODCREATER_CDDA_MAINWINDOW_H
