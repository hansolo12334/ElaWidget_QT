#include "main_window.h"

#include "T_Home.h"
#include "T_Setting.h"
#include "T_Chat.h"

#include "app_config.h"

main_window::main_window(QWidget *parent)
    : ElaWindow(parent)
{
    init_window();

    init_content();
}


void main_window::init_window()
{
    // this->setUserInfoCardVisible(false);
    this->resize(600, 740);
    this->setUserInfoCardTitle(QString("hansolo first try"));
    this->setUserInfoCardSubTitle(QString("111111"));
    this->setUserInfoCardPixmap(QPixmap(":/resources/image/640.png"));
    this->setWindowTitle("Test");
    //移动到中心

    this->moveToCenter();
}


void main_window::init_content()
{
    _homePage = new T_Home(this);


    _chatPage = new T_Chat(this);
    _settingPage = new T_Setting(this);

    this->addPageNode("HOME", _homePage, ElaIconType::House);

    this->addPageNode("CHAT", _chatPage, ElaIconType::PeopleArrows);

    this->addFooterNode("Setting", _settingPage, _settingKey, 0, ElaIconType::GearComplex);

    connect(&AppConfig::instance(), &AppConfig::configChanged, this, [=]() {
        if(AppConfig::instance().isEnableTTS()){
            qDebug() << "启用tts";
        }else{
            qDebug() << "关闭tts";
        }
    });
}
