#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customvwidget.h"
#include <iostream>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QVideoWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTime>


int dur1;
bool f1;
bool a=false;
bool playstatus=false;
QString timestring;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //create QMedia Player object
    mymediaPLayer= new QMediaPlayer(this);
    //create QMedia Player object
    myVideowidget= new customVWidget(this);

    connect(myVideowidget, &customVWidget::exitFromFS, this, &MainWindow::enterF);
    connect(myVideowidget, &customVWidget::useFS, this, &MainWindow::exitF);
    //create Qslider Player object
    mySlider=new QSlider(this);
    //add styles for the slider
    mySlider->setStyleSheet("QSlider::groove:horizontal { background-color: transparent;height: 5px;; }QSlider {background-color: transparent; } QSlider::sub-page:horizontal {background-color: #41cd52;}QSlider::add-page:horizontal {background-color: #a9a9aa;}QSlider::handle:horizontal {background-color: #41cd52;width: 14px;margin-top: -6px;margin-bottom: -6px;border-radius: 3px;}QSlider::handle:horizontal:hover {background-color: #22af00;border-radius: 3px;}QSlider::sub-page:horizontal:disabled {background-color: #bbb;border-color: #999;}QSlider::add-page:horizontal:disabled {background-color: #eee;border-color: #999;}");
    mySlider->setOrientation(Qt::Horizontal);


   mymediaPLayer->setVideoOutput(myVideowidget);
   myVideowidget->setGeometry(100,100,300,400);
   ui->verticalLayout->insertWidget(0,myVideowidget);
   ui->verticalLayout->insertWidget(1,mySlider);
   ui->pushButton->setIcon(QIcon(":/img/yellow/full.png"));
   ui->playBtn2->setIcon(QIcon(":/img/yellow/play.png"));
   ui->stopBtn->setIcon(QIcon(":/img/yellow/stop.png"));
   ui->muteBtn->setIcon(QIcon(":/img/yellow/s2.png"));
   ui->openBtn->setIcon(QIcon(":/img/yellow/all.png"));
   ui->settingsbtn->setIcon(QIcon(":/img/yellow/setting.png"));


   connect(this->mymediaPLayer, &QMediaPlayer::durationChanged, MainWindow::mySlider, &QSlider::setMaximum);
   connect(this->mymediaPLayer, &QMediaPlayer::positionChanged, this, &MainWindow::mediaplayerPositionChanged);
   connect(this->mySlider, &QSlider::sliderMoved, this->mymediaPLayer, &QMediaPlayer::setPosition);


 }




MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::mediaplayerPositionChanged(qint64 position)
{
    this->mySlider->setValue(position);
    this->timeupdate();
}



//allows to open video files from the storage
void MainWindow::on_openBtn_clicked()
{
      QString fname;
      fname=QFileDialog::getOpenFileName(this,"open");
      if(fname.isEmpty()){
          return;
      }
      mymediaPLayer->setMedia(QUrl::fromLocalFile(fname));
      mymediaPLayer->setVolume(ui->volumeVerticalSlider->value());
      on_playBtn2_clicked();

}

//provides play and pause functionalities
void MainWindow::on_playBtn2_clicked()
{

    if(playstatus == false){
        playstatus=true;
        mymediaPLayer->play();

        ui->playBtn2->setIcon(QIcon(":/img/yellow/pause.png"));
    }
    else{
        playstatus=false;
        mymediaPLayer->pause();
        ui->playBtn2->setIcon(QIcon(":/img/yellow/play.png"));

    }
}

//provides stop  function
void MainWindow::on_stopBtn_clicked()
{
    mymediaPLayer->stop();
}



//provides mute  function

void MainWindow::on_muteBtn_clicked()
{


    if(a == false){
        a=true;
        mymediaPLayer->setMuted(true);
        //change icon according to mute status
        ui->muteBtn->setIcon(QIcon(":/img/yellow/mute.png"));

    }
    else{
        a=false;

        mymediaPLayer->setMuted(false);
        //change icon according to mute status
        ui->muteBtn->setIcon(QIcon(":/img/yellow/s2.png"));
    }


}



//changes volume according to the valuchange of volume slider

void MainWindow::on_volumeVerticalSlider_valueChanged(int value)
{
    mymediaPLayer->setVolume(value);

    if(value<50){
        ui->muteBtn->setIcon(QIcon(":/img/yellow/s2.png"));
    }
    if(value<100 and value >50){
        ui->muteBtn->setIcon(QIcon(":/img/yellow/s1.png"));
    }

}

//changes the time lable according to the current position of the video and show the duration

void MainWindow::timeupdate()
{
    const qint64 duration = mymediaPLayer->duration()/1000;
    const qint64 currentPosition = mymediaPLayer->position()/1000;

    if (currentPosition)
    {
        QTime tTime((duration / 3600) % 60,(duration / 60) % 60,(duration % 60),(duration * 1000) % 1000);
        QTime cTime((currentPosition / 3600) %60,(currentPosition / 60) % 60,(currentPosition % 60),(currentPosition * 1000) % 1000);
        QString format = "mm:ss";
        if (duration > 3600)format = "hh:mm:ss";
        timestring = cTime.toString(format) + " || " + tTime.toString(format);
    }

    ui->timeLbl->setText(timestring);
}





void MainWindow::on_pushButton_clicked()
{
    myVideowidget->setFullScreen(true);
   // f1=true;
}

/*
void MainWindow::keyPressEvent( QKeyEvent * event )
{
    if( event->key() == Qt::Key_A )
    {
        // do your stuff here
    }
}*/


void MainWindow::mouseDoubleClickEvent(QMouseEvent* )
{

myVideowidget->showNormal();

}
















void MainWindow::on_settingsbtn_clicked()
{

    settingsdialog *test1=new settingsdialog(this);
    test1->show();
}


void MainWindow::showFullScreen()
{
    myVideowidget->setFullScreen(true);

}

void MainWindow::enterF()
{
    myVideowidget->setFullScreen(true);
}

void MainWindow::exitF()
{
    myVideowidget->setFullScreen(false);
}




