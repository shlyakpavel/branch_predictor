#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i <= 10; i++)
       {
        ui->listWidget->addItem(getElementBynooom(i).toString());
       }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_StepButton_clicked()
{
    if ( ui->listWidget->selectedItems().isEmpty() ) return;
    QListWidgetItem* cur= ui->listWidget->selectedItems().first();
    element el(cur->text());
    if (el.type==jumpto and willjump){
        if (ui->listWidget->count() > el.pointsto){
            ui->listWidget->item(el.pointsto)->setSelected(true);};
    }
    else
        if (ui->listWidget->count()>el.curaddr+1)
            ui->listWidget->item(el.curaddr+1)->setSelected(true);
    if (el.type==dostuff){
        ui->label_3->setText(QString("Prediction was: %1").arg(el.curaddr+1));
    }
    else{
        switch( getMode() ) {
        case jump:
            ui->label_3->setText(QString("Prediction: %1").arg(el.pointsto));
            break;
        case forward:
            ui->label_3->setText(QString("Prediction: %1").arg(el.curaddr+1));
            break;
        default:
            if (el.pointsto < el.curaddr){
                ui->label_3->setText(QString("Prediction: %1").arg(el.pointsto));
            } else{
                ui->label_3->setText(QString("Prediction: %1").arg(el.curaddr+1));
            }
            break;
        }
        willjump=static_cast<bool>(qrand() % 2);
        ui->label_4->setText(QString("Next jump operation will actually jump(random): %1").arg(willjump));
    }
}

mode MainWindow::getMode() {
    if ( ui->mode_jump->isChecked() ) { return jump; } else
    if ( ui->mode_forward->isChecked() ) { return forward; } else
    return clever; // default mode
}
