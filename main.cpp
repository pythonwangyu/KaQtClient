#include "mainwindow.h"
#include <QApplication>
#include "loginwindows.h"

#include <QPushButton>





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginWindows v;
    v.show();
    return a.exec();
}
