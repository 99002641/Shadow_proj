#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLCDNumber>
#include <QTimer>
#include <QVBoxLayout>
#include <QTime>
#include <QLabel>
#include <QDate>
class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
public slots:
    void showTime();
private:
    QLCDNumber *lcdNumberTime;
     QLCDNumber *lcdNumberDate;
    QTimer *timer;
    QTime *time;
    QVBoxLayout *vLayout;
    QLabel *label;
    QDate *date;
};

#endif // DIALOG_H
