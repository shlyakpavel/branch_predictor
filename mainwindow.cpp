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
          //items[i] = new QListWidgetItem(getElementBynooom(i).toString(), ui->listWidget);
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
        ui->label_3->setText(QString("Prediction: %1").arg(el.curaddr+1));
    }
    else{
        switch( getMode() ) {
        case jump:
            follow(el);
            break;
        case forward:

            break;
        default:
            //DoCleverStep();
            break;
        }
        willjump=static_cast<bool>(qrand() % 2);
        ui->label_4->setText(QString("Next opr will jump(random): %1").arg(willjump));
    }
}

mode MainWindow::getMode() {
    if ( ui->mode_jump->isChecked() ) { return jump; } else
    if ( ui->mode_forward->isChecked() ) { return forward; } else
    return clever; // default mode
}

void MainWindow::follow(element el){
ui->label_3->setText(QString("Prediction: %1").arg(el.pointsto));
}
