#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMediaPlayer>
#include <QFileDialog>
#include <QVideoWidget>
int dur1;

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
    });
    /*connect(mymediaPLayer, &QMediaPlayer::durationChanged, [&](qint64 r){
     ui->positionSdr->setValue(r);
    });*/

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
      mymediaPLayer->setVolume(ui->volumeSdr->value());
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


void MainWindow::on_volumeSdr_valueChanged(int value)
{

   mymediaPLayer->setVolume(value);
}


void MainWindow::on_positionSdr_valueChanged(int value)
{
    mymediaPLayer->setPosition(dur1/value);
}


void MainWindow::on_positionSdr_sliderMoved(int position)
{
    mymediaPLayer->setPosition(position);
}

