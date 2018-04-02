#include "mainwindow.h"
#include "ui_mainwindow.h"
 #include <QtDebug>
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
}
