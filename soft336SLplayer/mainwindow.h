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
  //  void on_playBtn_clicked();

    void on_openBtn_clicked();

    void on_playBtn2_clicked();

    void on_stopBtn_clicked();



    void on_muteBtn_clicked();


   // void on_positionSdr_valueChanged(int value);

    void on_volumeVerticalSlider_valueChanged(int value);

    void on_pushButton_clicked();
    void mouseDoubleClickEvent(QMouseEvent* e);

     void mediaplayerPositionChanged(qint64 position);


     void timeupdate();

     void on_settingsbtn_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *mymediaPLayer;
   // QVideoWidget *myVideowidget;
    QSlider *mySlider;

public:
    // QVideoWidget *myVideowidget;
     customVWidget *myVideowidget;

};



#endif // MAINWINDOW_H
