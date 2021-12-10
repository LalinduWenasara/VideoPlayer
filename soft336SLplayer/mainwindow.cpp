#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QVideoWidget>
#include <QKeyEvent>
#include <QMouseEvent>

int dur1;
bool f1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mymediaPLayer= new QMediaPlayer(this);
    myVideowidget= new QVideoWidget(this);

   mymediaPLayer->setVideoOutput(myVideowidget);
   myVideowidget->setGeometry(100,100,300,400);
   ui->verticalLayout->insertWidget(0,myVideowidget);

    connect(mymediaPLayer, &QMediaPlayer::positionChanged, [&](qint64 pos){
     ui->playProgress->setValue(pos);

    });
    connect(mymediaPLayer, &QMediaPlayer::durationChanged, [&](qint64 durrr){
     ui->playProgress->setMaximum(durrr);


     dur1=durrr;
   /*

     connect(this->mediaPlayer, &QMediaPlayer::durationChanged, this->currentContentSlider, &QSlider::setMaximum);
     connect(this->mediaPlayer, &QMediaPlayer::positionChanged, this, &MainWindow::positionChanged);
     connect(this->currentContentSlider, &QSlider::sliderMoved, this->mediaPlayer, &QMediaPlayer::setPosition);

    */

    });
  /*  connect(mymediaPLayer, &QMediaPlayer::durationChanged, [&](qint64 r){
     ui->positionSdr->setValue(r);
    });
*/

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_playBtn_clicked()
{

  QMediaPlayer* player=new QMediaPlayer;
        QVideoWidget* videowidget=new QVideoWidget;

        player->setVideoOutput(videowidget);
        player->setMedia(QUrl::fromLocalFile("C:/Users/lalin/Downloads/ʜawkeye.mkv"));
        videowidget->setGeometry(100,100,300,400);
        videowidget->show();
        player->play();


}








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


void MainWindow::on_playBtn2_clicked()
{
    mymediaPLayer->play();
}


void MainWindow::on_stopBtn_clicked()
{
    mymediaPLayer->stop();
}


void MainWindow::on_pauseBtn_clicked()
{
    mymediaPLayer->pause();
}



void MainWindow::on_muteBtn_clicked()
{
    if(ui->muteBtn->text()=="Mute"){
        mymediaPLayer->setMuted(true);
        ui->muteBtn->setText("Unmute");
    }
    else{
        mymediaPLayer->setMuted(false);
        ui->muteBtn->setText("Mute");
    }

}



void MainWindow::on_positionSdr_valueChanged(int value)
{

    mymediaPLayer->setPosition(mymediaPLayer->duration()/100*value);

}





void MainWindow::on_volumeVerticalSlider_valueChanged(int value)
{
    mymediaPLayer->setVolume(value);
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
}
*/
void MainWindow::mouseDoubleClickEvent(QMouseEvent* )
{

     myVideowidget->setFullScreen(false);

}
