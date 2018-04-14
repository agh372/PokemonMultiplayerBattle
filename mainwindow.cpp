#include "mainwindow.h"
#include "ui_mainwindow.h"
 #include <QtDebug>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "waiting.h"
#include <QMovie>
#include <QSignalMapper>


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
    movie = new QMovie(":/pokemon/GIFs/pikachu/pikachu.gif");
    QPixmap title(":/Images/logo.png");
    ui->title->setPixmap((title));
    ui->title->setScaledContents( true );
    ui->title->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    ui->processLabel->setMovie(movie);
    ui->processLabel->setScaledContents( true );
    ui->processLabel->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    movie->start();
    QSignalMapper* signalMapper = new QSignalMapper (this) ;
    connect (ui->BulbasaurRB, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
    connect (ui->PikachuRB, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
    connect (ui->SquirtleRB, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
    connect (ui->CharmandarRB, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
    connect (ui->GeodudeRB, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
    connect (ui->PidgeotRB, SIGNAL(clicked()), signalMapper, SLOT(map())) ;

    signalMapper -> setMapping (ui->BulbasaurRB,"bulbasaur") ;
    signalMapper -> setMapping (ui->PikachuRB,"pikachu") ;
    signalMapper -> setMapping (ui->SquirtleRB,"squirtle") ;
    signalMapper -> setMapping (ui->CharmandarRB,"charmander") ;
    signalMapper -> setMapping (ui->GeodudeRB,"geodude") ;

    signalMapper -> setMapping (ui->PidgeotRB,"pidgeot") ;
    ui->PikachuRB->setChecked((true));
    connect (signalMapper, SIGNAL(mapped(QString)), this, SLOT(onClickRadioButton(QString))) ;
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
        flag1 = "pikachu";
    else if(ui->BulbasaurRB->isChecked())
        flag1 = "bulbasaur";
    else if(ui->CharmandarRB->isChecked())
        flag1 = "charmander";
    else if(ui->PidgeotRB->isChecked())
        flag1 = "pidgeot";
    else if(ui->GeodudeRB->isChecked())
        flag1 = "geodude";
    else
        flag1 = "squirtle";

    QString s = "7 " + flag1;
    s.append(QChar(23));
    thread->sendMess(s);
}

void MainWindow::nameAccepted()
{
    waiting *w = new waiting(flag1, thread, this->t);
   // this->music->stop();
    w->show();
    this->close();
}

void MainWindow::onClickRadioButton(QString str)
{
     movie = new QMovie(":/pokemon/GIFs/"+str+"/"+str+".gif");
     ui->processLabel->setMovie(movie);
     movie->start();
}
