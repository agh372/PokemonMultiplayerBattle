#include "mainwindow.h"
#include "ui_mainwindow.h"
 #include <QtDebug>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "waiting.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->start->setText("Start");
    QPixmap bkgnd(":/Images/bg.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    ui->welcomeL->setStyleSheet("QLabel { background-color : white;}");
    ui->ql->setStyleSheet("QLabel { background-color : white;}");
    connect(ui->start,SIGNAL(clicked(bool)),this,SLOT(on_start_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_start_clicked()
{
    qInfo() << "Check";
    thread = new SocketThread(ui->ipAddress->text());
    connect(thread, SIGNAL(nameAccepted()), this, SLOT(nameAccepted()));

    if(ui->PikachuRB->isChecked())
        flag1 = "Pikachu";
    else if(ui->BulbasaurRB->isChecked())
        flag1 = "Bulbasaur";
    else if(ui->CharmandarRB->isChecked())
        flag1 = "Charmandar";
    else if(ui->PidgeotRB->isChecked())
        flag1 = "Pidgeot";
    else if(ui->GeodudeRB->isChecked())
        flag1 = "Geodude";
    else
        flag1 = "Squirtle";
    QString s = "7 " + flag1;
    s.append(QChar(23));
    thread->sendMess(s);
}

void MainWindow::nameAccepted()
{
    qInfo() << "Server";

    waiting *w = new waiting(flag1, thread, this->t);
    this->music->stop();
    w->show();
    this->close();

}

