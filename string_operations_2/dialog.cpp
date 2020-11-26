#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{

    lineedit1=new QLineEdit;
    lineedit2=new QLineEdit;

    result=new QLCDNumber;

    pushb1=new QPushButton("length");
    pushb2=new QPushButton("copy");
    pushb3=new QPushButton("concat");
    pushb4=new QPushButton("compare");

   vbox=new QVBoxLayout;

   hbox1=new QHBoxLayout;
   hbox2=new QHBoxLayout;
   hbox3=new QHBoxLayout;
   hbox4=new QHBoxLayout;


   gbox1=new QGroupBox;
   gbox2=new QGroupBox;
   gbox3=new QGroupBox;
   gbox4=new QGroupBox;


   lineedit1->setPlaceholderText("String 1");
   lineedit2->setPlaceholderText("String 2");

   hbox1->addWidget(lineedit1);
   hbox2->addWidget(lineedit2);
   hbox3->addWidget(result);
   hbox4->addWidget(pushb1);
   hbox4->addWidget(pushb2);
   hbox4->addWidget(pushb3);
   hbox4->addWidget(pushb4);

   gbox1->setLayout(hbox1);
   gbox2->setLayout(hbox2);
   gbox3->setLayout(hbox3);
   gbox4->setLayout(hbox4);





   vbox->addWidget(gbox1);
   vbox->addWidget(gbox2);
   vbox->addWidget(gbox3);
   vbox->addWidget(gbox4);

   connect(pushb1,SIGNAL(clicked()),this,SLOT(onlength()));
   connect(pushb2,SIGNAL(clicked()),this,SLOT(oncopy()));
   connect(pushb3,SIGNAL(clicked()),this,SLOT(onconcat()));
   connect(pushb4,SIGNAL(clicked()),this,SLOT(oncompare()));

   result->setPalette(Qt::black);

   setLayout(vbox);
}

void Dialog::onlength()
{
    result->display(lineedit1->text().length()+lineedit2->text().length());
}

void Dialog::oncopy()
{
    lineedit2->setText(lineedit1->text());
}
void Dialog::onconcat()
{
    lineedit2->setText(lineedit1->text()+lineedit2->text());
}

void Dialog::oncompare()
{
    if(lineedit1->text()==lineedit2->text())
        result->display("True");
    else
        result->display("False");
}

Dialog::~Dialog()
{
    
}
