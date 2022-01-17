#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class settingsdialog;
}

class settingsdialog : public QDialog
{
    Q_OBJECT

public:
    explicit settingsdialog(QWidget *parent = nullptr);
    ~settingsdialog();

private slots:
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::settingsdialog *ui;
};

#endif // SETTINGSDIALOG_H
