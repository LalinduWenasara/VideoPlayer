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
    mySlider=new QSlider(this);

    mySlider->setStyleSheet("QSlider::groove:horizontal { background-color: transparent;height: 5px;; }QSlider {background-color: transparent; } QSlider::sub-page:horizontal {background-color: #41cd52;}QSlider::add-page:horizontal {background-color: #a9a9aa;}QSlider::handle:horizontal {background-color: #41cd52;width: 14px;margin-top: -6px;margin-bottom: -6px;border-radius: 3px;}QSlider::handle:horizontal:hover {background-color: #22af00;border-radius: 3px;}QSlider::sub-page:horizontal:disabled {background-color: #bbb;border-color: #999;}QSlider::add-page:horizontal:disabled {background-color: #eee;border-color: #999;}");



    mySlider->setOrientation(Qt::Horizontal);


   mymediaPLayer->setVideoOutput(myVideowidget);
   myVideowidget->setGeometry(100,100,300,400);
   ui->verticalLayout->insertWidget(0,myVideowidget);
   ui->verticalLayout->insertWidget(1,mySlider);



   connect(this->mymediaPLayer, &QMediaPlayer::durationChanged, MainWindow::mySlider, &QSlider::setMaximum);
   connect(this->mymediaPLayer, &QMediaPlayer::positionChanged, this, &MainWindow::mediaplayerPositionChanged);
   connect(this->mySlider, &QSlider::sliderMoved, this->mymediaPLayer, &QMediaPlayer::setPosition);


 }

/*
    connect(mymediaPLayer, &QMediaPlayer::positionChanged, [&](qint64 pos){
     ui->playProgress->setValue(pos);

    });
    connect(mymediaPLayer, &QMediaPlayer::durationChanged, [&](qint64 durrr){
     ui->playProgress->setMaximum(durrr);


     dur1=durrr;


     connect(this->mediaPlayer, &QMediaPlayer::durationChanged, this->currentContentSlider, &QSlider::setMaximum);
     connect(this->mediaPlayer, &QMediaPlayer::positionChanged, this, &MainWindow::positionChanged);
     connect(this->currentContentSlider, &QSlider::sliderMoved, this->mediaPlayer, &QMediaPlayer::setPosition);



    }); */
  /*  connect(mymediaPLayer, &QMediaPlayer::durationChanged, [&](qint64 r){
     ui->positionSdr->setValue(r);
    });
*/

/*

   connect(this->mymediaPLayer, &QMediaPlayer::durationChanged, ui->positionSdr, &QSlider::setMaximum);
   connect(this->mymediaPLayer, &QMediaPlayer::positionChanged,[&](qint64 pos){ui->positionSdr->setValue(pos);});
   connect(ui->positionSdr, &QSlider::sliderMoved, this->mymediaPLayer, &QMediaPlayer::setPosition);

*/




//mymediaPLayer->duration()/100*value



MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::mediaplayerPositionChanged(qint64 position)
{
    this->mySlider->setValue(position);
  //  this->updateDurationInfo();
}


/*
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
*/



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

/*

void MainWindow::on_positionSdr_valueChanged(int value)
{

    mymediaPLayer->setPosition(mymediaPLayer->duration()/100*value);

}
*/




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
