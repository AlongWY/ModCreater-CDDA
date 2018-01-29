#ifndef MODCREATER_CDDA_MAINWINDOW_H
#define MODCREATER_CDDA_MAINWINDOW_H

#include <QMainWindow>
#include "Controller/ModsController.h"

namespace Ui {
    class MainWindow;
}

namespace cdda {

    class MainWindow : public QMainWindow {
    Q_OBJECT
    public:
        explicit MainWindow(QWidget *parent = nullptr);

        ~MainWindow();

    public slots:

        void OnExit();

        void OnSave();

        void UpdateModInfo(int index);

        void GetModInfo(int index);

        void UpdateModList();

    private:
        ModsController modsMgr;
        Ui::MainWindow *ui;
    };
}

#endif //MODCREATER_CDDA_MAINWINDOW_H
