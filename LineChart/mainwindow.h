#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
    void makePlot1();
    void makePlot2();
    void makePlot3();
    void makePlot4();

private slots:

    /*
    void on_colorButton_clicked();

    void on_reset_clicked();

    void on_increaseThickness_clicked();

    void on_decreaseThickness_clicked();

    void on_restoreBack_clicked();
   */

    void on_actionColor_triggered();

    void on_actionReset_Color_triggered();

    void on_actionIncrease_Thickness_triggered();

    void on_actionDecrease_Thickness_triggered();

    void on_actionRestore_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
