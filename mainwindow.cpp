#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i <= 10; i++)
        ui->listWidget->addItem(getElementBynooom(i).toString());
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
            ui->listWidget->setCurrentRow(el.pointsto);
        };
    }
    else
        if (ui->listWidget->count()>el.curaddr+1)
            ui->listWidget->setCurrentRow(ui->listWidget->currentRow()+1);
    if (el.type==dostuff){
        setPrediction(el.curaddr+1);
    }
    else{
        switch( curmode ) {
        case jump:
            setPrediction(el.pointsto);
            break;
        case forward:
            setPrediction(el.curaddr+1);
            break;
        default:
            if (el.pointsto < el.curaddr){
                setPrediction(el.pointsto);
            } else{
                setPrediction(el.curaddr+1);
            }
            break;
        }
        willjump=static_cast<bool>(qrand() % 2);
        ui->label_4->setText(QString(tr("Next jump operation will actually jump(random): ")).append(willjump ? tr("yes") : tr("no")));
    }
}

void MainWindow::on_mode_forward_toggled(bool checked)
{
    if (checked) {
        curmode=forward;
        ui->Description->setText(tr("Always predict that a conditional jump will not be taken"));
    }
}

void MainWindow::on_mode_jump_toggled(bool checked)
{
    if (checked) {
        curmode=jump;
        ui->Description->setText(tr("Always predict that a conditional jump will be taken"));
    }
}

void MainWindow::on_mode_clever_toggled(bool checked)
{
    if (checked) {
        curmode=clever;
        ui->Description->setText(tr("A more advanced form of static prediction presumes that backward branches will be taken and that forward branches will not. A backward branch is one that has a target address that is lower than its own address. This technique can help with prediction accuracy of loops, which are usually backward-pointing branches, and are taken more often than not taken"));
    }
}

void MainWindow::setPrediction(int prediction){
     ui->label_prediction->setText(QString(tr("Prediction was: %1")).arg(prediction));
}
