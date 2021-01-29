#include "loginwindows.h"
#include "ui_loginwindows.h"

#include <QDebug>
#include <QMessageBox>
#include <QString>

LoginWindows::LoginWindows(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindows)
{
    ui->setupUi(this);
    m_Status = false;

}

LoginWindows::~LoginWindows()
{
    delete ui;
}



void LoginWindows::ReadIPInfromationFromUi()
{
    //set Login Server and Port to Private Member
    m_IP = ui->IPLineEdit->text();
    m_port = ui->PortLineEdit->text().toInt();
    qDebug() << m_IP << m_port << endl;
    ui->IPLineEdit->clear();
    ui->PortLineEdit->clear();
}











//登录成功
void LoginWindows::Login_Sucess()
{
    this->hide();
    ChatWindow  = new MainWindow(this);
    ChatWindow->show();
}

//登录失败
void LoginWindows::Login_Error()
{
    QMessageBox::warning(nullptr,QObject::tr("提示"),"密码错误");
    ui->UserNameLineEdit->clear();
    ui->PasswdLineEdit->clear();
}


//确认登录信息
bool LoginWindows::Define_Information()
{
    return true;
}



void LoginWindows::on_LoginButton_clicked()
{
    //qDebug() << "on_LoginButton" << endl;

    if(Define_Information())
    {
        Login_Error();
    }
    else {
        Login_Error();
    }
}




//按钮触发的事件
void LoginWindows::on_RegisterButton_clicked()
{
    qDebug() << "on_RegisterButton_clicked()" << endl;
}


void LoginWindows::on_SettingButton_clicked()
{
    qDebug() << "on_RegisterButton_clicked()" << endl;
}

void LoginWindows::on_ChooseServerButton_clicked()
{
    //qDebug() << "on_ChooseServerButton_clicked()" << endl;
    ReadIPInfromationFromUi();
}
