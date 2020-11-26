#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{

    spinb=new QSpinBox;
    tempb=new QPushButton("TEMPERATURE");
    volb=new QPushButton("VOLUME");
    result=new QLCDNumber;
    label=new QLabel;


    vbox=new QVBoxLayout;
    hbox1=new QHBoxLayout;
    hbox2=new QHBoxLayout;
    hbox3=new QHBoxLayout;

    gbox1=new QGroupBox;
    gbox2=new QGroupBox;
    gbox3=new QGroupBox;


    vbox->addWidget(label);
    spinb->setRange(-100,100);
    hbox1->addWidget(spinb);
    gbox1->setLayout(hbox1);
    vbox->addWidget(gbox1);

    hbox2->addWidget(result);
    gbox2->setLayout(hbox2);
    vbox->addWidget(gbox2);

    hbox3->addWidget(tempb);
    hbox3->addWidget(volb);
    gbox3->setLayout(hbox3);
    vbox->addWidget(gbox3);

    setLayout(vbox);

  result->setPalette(Qt::black);
  connect(tempb,SIGNAL(clicked()),this,SLOT(ontemp()));

  connect(volb,SIGNAL(clicked()),this,SLOT(onvol()));

}

Dialog::~Dialog()
{
    
}

void Dialog::ontemp()
{label->setText("TEMPERATURE");
    result->display(spinb->value());
}


void Dialog::onvol()
{ label->setText("VOLUME");
    result->display(spinb->value());
}
