#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE





class QMediaPlayer;//define a class name Qmediaplayer
class QVideoWidget;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_playBtn_clicked();

    void on_openBtn_clicked();

    void on_playBtn2_clicked();

    void on_stopBtn_clicked();

    void on_pauseBtn_clicked();

    void on_muteBtn_clicked();

    void on_volumeSdr_valueChanged(int value);

    void on_positionSdr_valueChanged(int value);



private:
    Ui::MainWindow *ui;
    QMediaPlayer *mymediaPLayer;
    QVideoWidget *myVideowidget;
};
#endif // MAINWINDOW_H
