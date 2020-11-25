#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QLineEdit>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QMessageBox>
#include<QGroupBox>
#include<QLabel>
#include<QRadioButton>
#include<QPushButton>
#include<QObject>
#include <QLCDNumber>

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private:
    QLCDNumber *result;
    QLabel *labelheading;
    QLineEdit *lineedit1,*lineedit2;
    QRadioButton *radiobutton1,*radiobutton2,*radiobutton3,*radiobutton4;
    QPushButton *pushbutton1,*pushbutton2;

    QHBoxLayout *hbox1,*hbox2,*hbox3,*hbox4,*hbox5;

    QGroupBox *gbox1, *gbox2, *gbox3, *gbox4, *gbox5;
    QVBoxLayout *vbox;
    QMessageBox *messagebox;
public slots: void onCalculate();

    \






};

#endif // DIALOG_H
