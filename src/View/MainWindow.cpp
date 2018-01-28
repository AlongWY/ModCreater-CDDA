#include "MainWindow.h"
#include "ui_Window.h"
#include <iostream>

cdda::MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->ExitButton, SIGNAL(clicked()), this, SLOT(OnExit()));
    connect(ui->SaveButton, SIGNAL(clicked()), this, SLOT(OnSave()));
}

cdda::MainWindow::~MainWindow() {
    delete ui;
}

void cdda::MainWindow::OnExit() {
    std::cout << tr("OnExit()").toStdString() << std::endl;
    close();
}

void cdda::MainWindow::OnSave() {
    std::cout << tr("OnSave()").toStdString() << std::endl;
}
