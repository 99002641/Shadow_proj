#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QSpinBox>
#include<QLCDNumber>
#include<QPushButton>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGroupBox>
#include<QLabel>
#include<string>
class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    QPushButton *tempb,*volb;
    QSpinBox *spinb;
    QLCDNumber *result;


    QVBoxLayout *vbox;
    QHBoxLayout *hbox1,*hbox2,*hbox3;
    QGroupBox *gbox1,*gbox2,*gbox3;
    QLabel *label;
    int volume=0,temperature=0;


public slots:
    void ontemp();
    void onvol();

};

#endif // DIALOG_H
