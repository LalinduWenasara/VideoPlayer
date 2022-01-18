#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include "settingsdialog.h"
#include "customvwidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class QMediaPlayer;
//define a class name Qmediaplayer
class QVideoWidget;
class QSlider;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showFullScreen();
    void enterF();
    void exitF();

private slots:

    //allows to open video files from the storage
    void on_openBtn_clicked();  
    //provides play and pause functionalities
    void on_playBtn2_clicked();
    //provides stop  function
    void on_stopBtn_clicked();
    //provides mute  function
    void on_muteBtn_clicked();
    //changes volume according to the valuchange of volume slider
    void on_volumeVerticalSlider_valueChanged(int value);
    //change normal size to full screen
    void on_pushButton_clicked();

    void mouseDoubleClickEvent(QMouseEvent* e);

     void mediaplayerPositionChanged(qint64 position);

     void keyPressEvent(QKeyEvent *event);
     void timeupdate();

     void on_settingsbtn_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *mymediaPLayer;
    QSlider *mySlider;

public:
     customVWidget *myVideowidget;

};



#endif // MAINWINDOW_H
