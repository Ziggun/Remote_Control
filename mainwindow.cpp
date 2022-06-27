#include "mainwindow.h"
#include "ui_mainwindow.h"

int all_numbers;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->p0,SIGNAL(clicked()),this,SLOT(digits_num()));
    connect(ui->p1,SIGNAL(clicked()),this,SLOT(digits_num()));
    connect(ui->p2,SIGNAL(clicked()),this,SLOT(digits_num()));
    connect(ui->p3,SIGNAL(clicked()),this,SLOT(digits_num()));
    connect(ui->p4,SIGNAL(clicked()),this,SLOT(digits_num()));
    connect(ui->p5,SIGNAL(clicked()),this,SLOT(digits_num()));
    connect(ui->p6,SIGNAL(clicked()),this,SLOT(digits_num()));
    connect(ui->p7,SIGNAL(clicked()),this,SLOT(digits_num()));
    connect(ui->p8,SIGNAL(clicked()),this,SLOT(digits_num()));
    connect(ui->p9,SIGNAL(clicked()),this,SLOT(digits_num()));
    connect(ui->pV1,SIGNAL(clicked()),this,SLOT(PVP()));
    connect(ui->pV2,SIGNAL(clicked()),this,SLOT(PVM()));
    connect(ui->pCH1,SIGNAL(clicked()),this,SLOT(CHP()));
    connect(ui->pCH2,SIGNAL(clicked()),this,SLOT(CHM()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_num()
{
   QPushButton *button = (QPushButton* )sender();
   all_numbers;
   QString new_label;
   all_numbers = (ui->label_2->text()+button->text()).toInt();
   if(all_numbers > 999){
       all_numbers = 0;
       new_label = QString::number(all_numbers,'g',15);
       ui->label_2->setText(new_label);
   } else {
   new_label = QString::number(all_numbers,'g',15);
   ui->label_2->setText(new_label);
   }
}


void MainWindow::on_pV_clicked()
{
   int all_numbers;
   QString new_label;
   all_numbers = ui->label_4->text().toInt();

   if(ui->pV1->isChecked()) {
       if(all_numbers < 100) {
       all_numbers += 10;
       new_label = QString::number(all_numbers,'g',15);
       ui->label_4->setText(new_label);
       } else {
            ui->pV1->setChecked(false);
       }
    } else {
       all_numbers -= 10;
       new_label = QString::number(all_numbers,'g',15);
       ui->label_4->setText(new_label);
   }
}

void MainWindow::PVP()
{
   QPushButton *button = (QPushButton* )sender();
   int vol = 10;
    QString new_label;
    vol = ui->label_4->text().toInt();
    if(vol < 100) {
        vol+=10;
    }
    new_label = QString::number(vol,'g',3);
   ui->label_4->setText(new_label);
}

void MainWindow::PVM()
{
   QPushButton *button = (QPushButton* )sender();
   int vol = 10;
    QString new_label;
    vol = ui->label_4->text().toInt();
    if(vol > 0) {
        vol-=10;
    }
    new_label = QString::number(vol,'g',3);
   ui->label_4->setText(new_label);
}


void MainWindow::CHM()
{
    QPushButton *button = (QPushButton* )sender();
    QString new_label;
    all_numbers = ui->label_2->text().toInt();
    if(all_numbers > 0) {
        all_numbers --;
    }
    new_label = QString::number(all_numbers,'g',3);
   ui->label_2->setText(new_label);
}

void MainWindow::CHP(){
    QPushButton *button = (QPushButton* )sender();
    QString new_label;
    all_numbers = ui->label_2->text().toInt();
    if(all_numbers < 999) {
        all_numbers ++;
    }
    new_label = QString::number(all_numbers,'g',3);
   ui->label_2->setText(new_label);
}
