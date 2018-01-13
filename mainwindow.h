#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
//#include <QQueue>
#include <branch_types.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_StepButton_clicked();

    void on_mode_forward_toggled(bool checked);

    void on_mode_jump_toggled(bool checked);

    void on_mode_clever_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    mode curmode;
    bool willjump = false;
    void setPrediction(int prediction);
};

#endif // MAINWINDOW_H
