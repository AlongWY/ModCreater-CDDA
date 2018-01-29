#include <QMessageBox>
#include <iostream>
#include "MainWindow.h"
#include "ui_Window.h"

using namespace boost;

cdda::MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    filesystem::path path(filesystem::current_path() / "mods");
    if (filesystem::exists(path)) {
        modsMgr.load_mods_info(path);
        UpdateModList();
    } else {
        QMessageBox::warning(this, tr("LoadError"), tr("No \"mods\" Directory Exists"));
    }
    connect(ui->ExitButton, SIGNAL(clicked()), this, SLOT(OnExit()));
    connect(ui->SaveButton, SIGNAL(clicked()), this, SLOT(OnSave()));
    connect(ui->ModsListWidget, SIGNAL(currentRowChanged(int)), this, SLOT(GetModInfo(int)));
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

void cdda::MainWindow::UpdateModInfo(int index) {
    modsMgr.mods[index].id = ui->InfoIDEdit->text().toStdString();
    modsMgr.mods[index].name = ui->InfoNameEdit->text().toStdString();
    modsMgr.mods[index].description = ui->InfoDescriptionEdit->text().toStdString();
    modsMgr.mods[index].path = ui->InfoPathEdit->text().toStdString();
    modsMgr.mods[index].category = ui->InfoCategoryEdit->text().toStdString();
    modsMgr.mods[index].legacy = ui->InfoLegacyEdit->text().toStdString();

    modsMgr.mods[index].core = ui->InfoIsCore->isChecked();
    modsMgr.mods[index].obsolete = ui->InfoIsObsolete->isChecked();

    // Mod列表是按照name排序的，如果name有变动，就更新一下列表
    if (modsMgr.mods[index].name != ui->InfoNameEdit->text().toStdString()) {
        std::sort(modsMgr.mods.begin(), modsMgr.mods.end());
        UpdateModList();
    }
}

void cdda::MainWindow::GetModInfo(int index) {
    ui->InfoIDEdit->setText(QString::fromStdString(modsMgr.mods[index].id));
    ui->InfoNameEdit->setText(QString::fromStdString(modsMgr.mods[index].name));
    ui->InfoDescriptionEdit->setText(QString::fromStdString(modsMgr.mods[index].description));
    ui->InfoPathEdit->setText(QString::fromStdString(modsMgr.mods[index].path));
    ui->InfoCategoryEdit->setText(QString::fromStdString(modsMgr.mods[index].category));
    ui->InfoLegacyEdit->setText(QString::fromStdString(modsMgr.mods[index].legacy));

    ui->InfoIsCore->setChecked(modsMgr.mods[index].core);
    ui->InfoIsObsolete->setChecked(modsMgr.mods[index].obsolete);
    modsMgr.load_mod(index);
}

void cdda::MainWindow::UpdateModList() {
    ui->ModsListWidget->clear();
    for (const auto &mod:modsMgr.mods) {
        ui->ModsListWidget->addItem(QString::fromStdString(mod.name));
    }
}
