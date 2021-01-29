#ifndef LOGINWINDOWS_H
#define LOGINWINDOWS_H

#include "mainwindow.h"

#include <QWidget>

//for Net Work
#include <QTcpSocket>
#include <QHostAddress>
#include <string>


namespace Ui {
class LoginWindows;
}


//Get Results of LoginServer send back to Client;

typedef struct LoginMessage{
    std::string ip;
    std::string port;
    uint32_t    Ack_num;
}ResLoginMessage;





class LoginWindows : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindows(QWidget *parent = nullptr);
    ~LoginWindows();


    //Read Information from UI
    void ReadIPInfromationFromUi();






    //Send Login Information to LoginSever,     send username,passwd,Will
    bool  SendToLoginServer();

    //Get Results of Login






    //关于信息登录的函数
    bool Define_Information();      //如果确认成功，返回true
    void Login_Sucess();
    void Login_Error();


public slots:
   // void slotConnected();               //slot function when socket connected  signal
    //void slotDisconnected();            //slot function when socket disconnected signal


private slots:

//      与按钮触发的槽函数，on_控件名_对应的事件()
//      这样设置的槽函数会自动地与按钮连接，而无需调用QObject::connection函数。

    void on_LoginButton_clicked();              //点击登录按钮触发的槽函数
    void on_RegisterButton_clicked();           //点击注册按钮触发的的槽函数
    void on_SettingButton_clicked();            //点击设置按钮触发的槽函数
    //点击选择之后，将私有变量中的IP和PORT初始化
    void on_ChooseServerButton_clicked();       //点击触发选择服务器的槽函数

private:
    Ui::LoginWindows *ui;                       // loginUi          this is a LoginUi for User,can choose LoginServer
    MainWindow       *ChatWindow;               //Chatwindow

    int              m_port;                    //store，loginServer Port,  MsgServerPort
    QString          m_IP;                      //store，loginServer Port,  MsgServerPort
    QHostAddress     *serverIP;                 //for Connection to loginServer or MsgServer
    QTcpSocket       *tcpSocket;                //for Connection to loginServer or MsgServer
    bool             m_Status;                  //Connection Status  true ,false


    ResLoginMessage  Res;
};



#endif // LOGINWINDOWS_H
