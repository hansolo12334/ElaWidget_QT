#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include "ElaWindow.h"



class main_window : public ElaWindow
{
    Q_OBJECT
public:
    main_window(QWidget *parent=nullptr);

    void init_window();
};

#endif // MAIN_WINDOW_H
