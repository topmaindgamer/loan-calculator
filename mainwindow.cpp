#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSpinBox>
#include <math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sum_num->setValidator( new QIntValidator(0, 999999999, this) );
    ui->interest_num->setValidator( new QIntValidator(0, 999, this) );
    ui->years_num->setValidator( new QIntValidator(0, 99, this) );
}

MainWindow::~MainWindow()
{

    delete ui;
}




void MainWindow::on_res_clicked()
{

    if (!ui->sum_num->text().isEmpty() && !ui->interest_num->text().isEmpty() && !ui->years_num->text().isEmpty()) {

        double sum = ui->sum_num->text().toDouble();
        double pr = ui->interest_num->text().toDouble();
        int year = ui->years_num->text().toInt();

        double p = pr/100/12;
        int n = year*12;

        double x = sum*(p+(p/(pow((1+p),n)-1)));
        double y = x * n;
        double z = y - sum;

        ui->suma_viplat_num->setText(QString::number(y,12,2)+" ₽");
        ui->pereplata_num->setText(QString::number(z,12,2)+" ₽");
        ui->suma_viplat_mes_num->setText(QString::number(x,12,2)+" ₽");

    }
    else {

        ui->suma_viplat_num->setText("0");
        ui->pereplata_num->setText("0");
        ui->suma_viplat_mes_num->setText("0");

    }
}



void MainWindow::on_clear_clicked()
{
    ui->suma_viplat_num->setText("0");
    ui->pereplata_num->setText("0");
    ui->suma_viplat_mes_num->setText("0");

    ui->sum_num->setText(NULL);
    ui->interest_num->setText(NULL);
    ui->years_num->setText(NULL);
}

