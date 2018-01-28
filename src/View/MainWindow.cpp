#include "MainWindow.h"
#include "ui_Window.h"
#include <iostream>

cdda::MainWindow::MainWindow(QString title, int min_w, int min_h) :
        QMainWindow(), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->ExitButton, SIGNAL(clicked()), this, SLOT(OnExit()));
    setWindowTitle(title);
    setMinimumSize(min_w, min_h);
}

cdda::MainWindow::~MainWindow() {
    delete ui;
}

void cdda::MainWindow::OnExit() {
    std::cout << "OnExit()" << std::endl;
    close();
}
