#include "T_Chat.h"


#include <QVBoxLayout>

#include "ElaImageCard.h"
#include "ElaIconButton.h"
#include "ElaScrollArea.h"
#include "ElaText.h"


T_Chat::T_Chat(QWidget *parent) : T_BasePage(parent)
{


    ElaImageCard *backgroundCard = new ElaImageCard(this);
    backgroundCard->setBorderRadius(10);
    backgroundCard->setFixedHeight(600);
    backgroundCard->setMaximumAspectRatio(1.7);

    QVBoxLayout *backgroundLayout = new QVBoxLayout(backgroundCard);
    backgroundLayout->setContentsMargins(0, 0, 0, 0);

    ElaScrollArea *cardScrollArea = new ElaScrollArea(this);


    ElaIconButton *sendButton = new ElaIconButton(this);



    backgroundLayout->addWidget(cardScrollArea);



    QWidget *centralWidget = new QWidget(this);
    centralWidget->setWindowTitle("Chat");
    QVBoxLayout *centerVLayout = new QVBoxLayout(centralWidget);
    centerVLayout->setSpacing(0);
    centerVLayout->setContentsMargins(0, 0, 0, 0);
    centerVLayout->addWidget(backgroundCard);
    centerVLayout->addSpacing(20);
    // centerVLayout->addLayout(flowTextLayout);
    // centerVLayout->addSpacing(10);
    // centerVLayout->addLayout(flowLayout);
    // centerVLayout->addStretch();
    this->addCentralWidget(centralWidget);

}
