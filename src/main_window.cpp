#include "main_window.h"

main_window::main_window(QWidget *parent)
    : ElaWindow(parent)
{
    init_window();
}


void main_window::init_window()
{
    // this->setUserInfoCardVisible(false);
    this->setUserInfoCardTitle(QString("hansolo first try"));
    this->setUserInfoCardSubTitle(QString("111111"));
    this->setUserInfoCardPixmap(QPixmap(":/resources/image/640.png"));
}
