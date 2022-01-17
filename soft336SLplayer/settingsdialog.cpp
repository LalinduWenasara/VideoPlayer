#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include "mainwindow.h"

settingsdialog::settingsdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settingsdialog)
{
    ui->setupUi(this);

}

settingsdialog::~settingsdialog()
{
    delete ui;
}

void settingsdialog::on_horizontalSlider_valueChanged(int value)
{
  QString v1= QString::number(value);
  ui->label1->setText(v1);

  //MainWindow.myvideoplayer
  //myVideowidget->setContrast(value);

}

