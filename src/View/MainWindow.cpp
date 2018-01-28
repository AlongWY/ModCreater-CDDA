#include "MainWindow.h"
#include "ui_Window.h"

cdda::MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->ExitButton, SIGNAL(clicked()), this, SLOT(OnExit()));
    connect(ui->SaveButton, SIGNAL(clicked()), this, SLOT(OnSave()));
}

cdda::MainWindow::~MainWindow() {
    delete ui;
}

void cdda::MainWindow::OnExit() {
    close();
}

void cdda::MainWindow::OnSave() {
}
