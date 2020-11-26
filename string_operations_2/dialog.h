#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QLineEdit>
#include<QPushButton>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGroupBox>
#include<QLCDNumber>
#include<string>
class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private: QLineEdit *lineedit1,*lineedit2;
QLCDNumber *result;
QPushButton *pushb1,*pushb2,*pushb3,*pushb4;

QVBoxLayout *vbox;
QHBoxLayout *hbox1,*hbox2,*hbox3,*hbox4;
QGroupBox *gbox1,*gbox2,*gbox3,*gbox4;

public slots: void onlength();
void oncopy();
void onconcat();
void oncompare();
};

#endif // DIALOG_H
