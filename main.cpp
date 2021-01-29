#include "mainwindow.h"
#include <QApplication>
#include "loginwindows.h"

#include <QPushButton>

//class MyWindows: public QWidget
//{
//public:
//    explicit MyWindows()
//    {
//        Btn = new QPushButton(this);
//        Btn->show();
//    }

//    ~MyWindows()
//    {
//        delete Btn;
//    }

//private:
//    QPushButton  *Btn;
//};



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginWindows v;
    v.show();
    return a.exec();
}
