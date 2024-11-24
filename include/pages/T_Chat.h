#ifndef T_CHAT_H
#define T_CHAT_H

#include "T_BasePage.h"

#include "ElaPlainTextEdit.h"
#include"ElaLineEdit.h"
#include"ElaComboBox.h"



class T_Chat : public T_BasePage
{
 Q_OBJECT
public:
    Q_INVOKABLE explicit T_Chat(QWidget* parent = nullptr);
    ~T_Chat();
Q_SIGNALS:
    // Q_SIGNAL void elaScreenNavigation();
    // Q_SIGNAL void elaBaseComponentNavigation();
    // Q_SIGNAL void elaSceneNavigation();
    // Q_SIGNAL void elaCardNavigation();
    // Q_SIGNAL void elaIconNavigation();

protected:
    // virtual void mouseReleaseEvent(QMouseEvent* event);

private:
};


#endif
