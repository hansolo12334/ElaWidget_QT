#include "T_Chat.h"


#include <QVBoxLayout>

#include "ElaImageCard.h"
#include "ElaIconButton.h"
#include "ElaScrollArea.h"
#include "ElaPushButton.h"
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


    ElaLineEdit *text_input_edit = new ElaLineEdit(this);
    ElaPushButton *sendButton = new ElaPushButton(this);
    QHBoxLayout *text_input_layout = new QHBoxLayout();
    text_input_layout->addWidget(text_input_edit);
    text_input_layout->addWidget(sendButton);


    backgroundLayout->addWidget(cardScrollArea);
    backgroundLayout->addLayout(text_input_layout);


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

T_Chat::~T_Chat()
{

}
