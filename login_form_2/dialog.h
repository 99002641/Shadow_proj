#ifndef DIALOG_H
#define DIALOG_H
#include<QLineEdit>
#include <QDialog>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGroupBox>
#include<QPushButton>
#include<QMessageBox>
class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private: QLineEdit *lineedit1,*lineedit2;
    QVBoxLayout *vbox;
    QHBoxLayout *hbox1,*hbox2,*hbox3;
    QGroupBox *gbox1,*gbox2,*gbox3;
    QPushButton *pushb1,*pushb2;
    QMessageBox *msg;

public slots: void onlogin();
};

#endif // DIALOG_H
