#include<QApplication>

#include "ElaApplication.h"
#include "main_window.h"




int main(int argc,char **argv)
{
    QApplication a(argc, argv);
    eApp->init();

    main_window w;
    w.show();


    return a.exec();
}
