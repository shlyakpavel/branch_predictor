#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QQueue>
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

private:
    Ui::MainWindow *ui;
    mode getMode();
    void follow(element el);
    bool willjump = false;
};

#endif // MAINWINDOW_H
