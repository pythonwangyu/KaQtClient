#ifndef LOGINWINDOWS_H
#define LOGINWINDOWS_H

#include "mainwindow.h"

#include <QWidget>

//for Net Work
#include <QTcpSocket>
#include <QHostAddress>


namespace Ui {
class LoginWindows;
}

class LoginWindows : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindows(QWidget *parent = nullptr);
    ~LoginWindows();


    //Read Information from UI
    void ReadIPInfromationFromUi();






    //向发送LoginServer发送登录信息
    bool  SendToLoginServer();



    //关于信息登录的函数
    bool Define_Information();      //如果确认成功，返回true
    void Login_Sucess();
    void Login_Error();


public slots:
   // void slotConnected();               //连接上socket的函数
    //void slotDisconnected();            //断开socket的函数


private slots:

//      与按钮触发的槽函数，on_控件名_对应的事件()
//      这样设置的槽函数会自动地与按钮连接，而无需调用QObject::connection函数。

    void on_LoginButton_clicked();              //点击登录按钮触发的槽函数
    void on_RegisterButton_clicked();           //点击注册按钮触发的的槽函数
    void on_SettingButton_clicked();            //点击设置按钮触发的槽函数
    //点击选择之后，将私有变量中的IP和PORT初始化
    void on_ChooseServerButton_clicked();       //点击触发选择服务器的槽函数

private:
    Ui::LoginWindows *ui;
    MainWindow       *ChatWindow;

    int              m_port;
    QString          m_IP;
    QHostAddress     *serverIP;
    QTcpSocket       *tcpSocket;
    bool             m_Status;                  //状态

};



#endif // LOGINWINDOWS_H
