#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{msg=new QMessageBox;

    lineedit1=new QLineEdit;
    lineedit2=new QLineEdit;

    pushb1=new QPushButton("login");
    pushb2=new QPushButton("signup");

    vbox=new QVBoxLayout;

    hbox1=new QHBoxLayout;
    hbox2=new QHBoxLayout;
    hbox3=new QHBoxLayout;

    gbox1=new QGroupBox;
    gbox2=new QGroupBox;
    gbox3=new QGroupBox;


    lineedit1->setPlaceholderText("USERNAME");
    lineedit2->setPlaceholderText("PASSWORD");

    hbox1->addWidget(lineedit1);
    hbox2->addWidget(lineedit2);
    hbox3->addWidget(pushb1);
    hbox3->addWidget(pushb2);

    gbox1->setLayout(hbox1);
    gbox2->setLayout(hbox2);
    gbox3->setLayout(hbox3);

    vbox->addWidget(gbox1);
    vbox->addWidget(gbox2);
    vbox->addWidget(gbox3);

    setLayout(vbox);

    connect(pushb1,SIGNAL(clicked()),this,SLOT(onlogin()));

}

void Dialog::onlogin()
{if(lineedit1->text()=="shadowproject"&&lineedit2->text()=="shadowproject")
    {
    lineedit1->setEnabled(false);
    lineedit2->setEnabled(false);

    pushb2->setEnabled(false);
    pushb1->setText("LOGGED IN");
}
    else {
        msg->warning(this,"Invalid password","wrong password");

    }
}

Dialog::~Dialog()
{
    
}
