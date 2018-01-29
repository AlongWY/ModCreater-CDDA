#include <QMessageBox>
#include <iostream>
#include "MainWindow.h"
#include "ui_Window.h"

using namespace boost;

cdda::MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    filesystem::path path(filesystem::current_path() / "mods");
    if (filesystem::exists(path)) {
        modsMgr.load_mods(path);
        for (const auto &mod:modsMgr.mods) {
            ui->ModsListWidget->addItem(QString::fromStdString(mod.name));
        }
    } else {
        QMessageBox::warning(this, tr("LoadError"), tr("No \"mods\" Directory Exists"));
    }
    connect(ui->ExitButton, SIGNAL(clicked()), this, SLOT(OnExit()));
    connect(ui->SaveButton, SIGNAL(clicked()), this, SLOT(OnSave()));
    connect(ui->ModsListWidget, SIGNAL(currentRowChanged(int)), this, SLOT(OnUpdate(int)));
}

cdda::MainWindow::~MainWindow() {
    delete ui;
}

void cdda::MainWindow::OnExit() {
    close();
}

void cdda::MainWindow::OnSave() {
    int index = ui->ModsListWidget->currentIndex().row();
    std::cout << index << std::endl;
}

void cdda::MainWindow::OnUpdate(int index) {
    std::cout << index << std::endl;
    ui->InfoIDEdit->setText(QString::fromStdString(modsMgr.mods[index].id));
    ui->InfoNameEdit->setText(QString::fromStdString(modsMgr.mods[index].name));
    ui->InfoDescriptionEdit->setText(QString::fromStdString(modsMgr.mods[index].description));
    ui->InfoPathEdit->setText(QString::fromStdString(modsMgr.mods[index].path));
    ui->InfoCategoryEdit->setText(QString::fromStdString(modsMgr.mods[index].category));
    ui->InfoLegacyEdit->setText(QString::fromStdString(modsMgr.mods[index].legacy));
    ui->InfoIsCore->setChecked(modsMgr.mods[index].core);
    ui->InfoIsObsolete->setChecked(modsMgr.mods[index].obsolete);
}
