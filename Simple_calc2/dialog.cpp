#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{ labelheading=new QLabel("Simple calculator 2");
    result=new QLCDNumber;


    lineedit1=new QLineEdit;
    lineedit1->setPlaceholderText("INPUT 1");
    lineedit2=new QLineEdit;
    lineedit2->setPlaceholderText("INPUT 2");


    radiobutton1=new QRadioButton("Add");
    radiobutton2=new QRadioButton("Subb");
    radiobutton3=new QRadioButton("Multiply");
    radiobutton4=new QRadioButton("Division");\

    pushbutton1 = new QPushButton;
    pushbutton1->setText("CALCULATE");
    pushbutton2 = new QPushButton;
    pushbutton2->setText("CLEAR");

    gbox1=new QGroupBox;
    gbox2=new QGroupBox;
    gbox3=new QGroupBox;
    gbox4=new QGroupBox;
    gbox5=new QGroupBox;

    hbox1= new QHBoxLayout(gbox1);
    hbox2=new QHBoxLayout(gbox2);
    hbox3=new QHBoxLayout(gbox3);
    hbox4=new QHBoxLayout(gbox4);
    hbox5=new QHBoxLayout(gbox5);

    vbox=new QVBoxLayout;



    hbox1->addWidget(lineedit1);
    gbox1->setLayout(hbox1);



    hbox2->addWidget(lineedit2);
    gbox2->setLayout(hbox2);

    hbox3->addWidget(radiobutton1);
    hbox3->addWidget(radiobutton2);
    hbox3->addWidget(radiobutton3);
    hbox3->addWidget(radiobutton4);
    gbox3->setLayout(hbox3);

    hbox4->addWidget(result);
    gbox4->setLayout(hbox4);

    hbox5->addWidget(pushbutton1);
    hbox5->addWidget(pushbutton2);
    gbox5->setLayout(hbox5);

    vbox->addWidget(labelheading);
    vbox->addWidget(gbox1);
    vbox->addWidget(gbox2);
    vbox->addWidget(gbox3);
    vbox->addWidget(gbox4);
    vbox->addWidget(gbox5);

setLayout(vbox);
 result->setPalette(Qt::black);



 connect(pushbutton2,SIGNAL(clicked()),lineedit1,SLOT(clear()));
 connect(pushbutton2,SIGNAL(clicked()),lineedit2,SLOT(clear()));

 connect(pushbutton1,SIGNAL(clicked()),this,SLOT(onCalculate()));






}


void Dialog::onCalculate()
{
    //check for empty input
    if(lineedit1->text()==NULL || lineedit2->text()==NULL)
    {
        messagebox->critical(this,"Empty Input", "Input Fields cannot be empty!");
    }
     //check for empty operation select
    else if(radiobutton1->isChecked()==false && radiobutton2->isChecked()==false && radiobutton3->isChecked()==false && radiobutton4->isChecked()==false  )
        messagebox->critical(this,"Invalid Operation", "Select an operation to be performed!");

    else

    {
        if(radiobutton1->isChecked())
            result->display(  QString::number( lineedit1->text().toInt() +  lineedit2->text().toInt() )   );
        else if(radiobutton2->isChecked())
            result->display(  QString::number( lineedit1->text().toInt() -  lineedit2->text().toInt() )   );
        else if(radiobutton3->isChecked())
            result->display(  QString::number( lineedit1->text().toInt() *  lineedit2->text().toInt() )   );
        else if(radiobutton4->isChecked())
        {
            if(lineedit1->text().toInt()==0 && lineedit2->text().toInt()==0 )
                 messagebox->critical(this,"Zero by Zero Error", "Numerator and Denominator cannot be zero!");

            if( lineedit2->text().toInt()!=0)
             result->display(  QString::number( lineedit1->text().toInt() /  lineedit2->text().toInt() )   );
            else
                messagebox->critical(this,"Divide by zero Error", "Denominator cannot be zero!");
        }

    }

}

Dialog::~Dialog()
{
    
}
