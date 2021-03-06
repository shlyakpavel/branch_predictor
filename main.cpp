#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator qtTranslator;
    qtTranslator.load("qt_" + QLocale::system().name(),
    QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&qtTranslator);

    QTranslator myappTranslator;
    QString lang = QString(":/languages/") + QLocale::system().name() + ".qm";
    myappTranslator.load(lang);
    a.installTranslator(&myappTranslator);

    MainWindow w;
    w.show();

    return a.exec();
}
