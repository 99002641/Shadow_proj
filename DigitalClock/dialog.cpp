#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    timer = new QTimer(this);
    lcdNumberTime = new QLCDNumber(this);
    lcdNumberDate = new QLCDNumber(this);
    vLayout = new QVBoxLayout(this);
    time = new QTime();
    date = new QDate();
    label = new QLabel(this);
    vLayout->addWidget(label);
    vLayout->addWidget(lcdNumberDate,Qt::AlignCenter);
    vLayout->addWidget(lcdNumberTime,Qt::AlignCenter);
    lcdNumberDate->setDigitCount(10);
    lcdNumberTime->setDigitCount(10);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);

}

Dialog::~Dialog()
{
    
}

void Dialog::showTime()
{

    label->setText("\t\tDATE and TIME");

    QTime time = QTime::currentTime();
    const QString timeText = time.toString("hh:mm:ss");
    lcdNumberTime->display(timeText);

    QString dt = QDate::currentDate().toString("dd.MM.yyyy");
    lcdNumberDate->display(dt);

}
