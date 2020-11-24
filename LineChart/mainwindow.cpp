#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <iostream>
#include <QPen>
#include<bits/stdc++.h>
#include<sstream>
#include<string>
int PEN_WIDTH = 2;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::makePlot1();
    MainWindow::makePlot2();
    MainWindow::makePlot3();
    MainWindow::makePlot4();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::makePlot1()
{int i=0;
    QVector<double> x(4000), y(4000);
    std::string line,A,B;
    std::fstream fin;
    fin.open("dataset1.csv", std::ios::in);

    while( getline(fin, line))
           { std::stringstream X(line);
               getline(X, A, ',');
               getline(X, B, ',');
               ++i;
               x[i]=std::stod(A);
               y[i]=std::stod(B);
           }

// generate some data:

    // create graph and assign data to it:
    ui->customPlot1->setInteraction(QCP::iRangeDrag,true);
    ui->customPlot1->setInteraction(QCP::iRangeZoom,true);
    ui->customPlot1->addGraph();
    ui->customPlot1->graph(0)->setBrush(QBrush(QColor(0, 120, 255, 20)));
    ui->customPlot1->graph(0)->setPen(QPen(Qt::red));
    ui->customPlot1->graph(0)->setData(x, y);

    // give the axes some labels:
    ui->customPlot1->xAxis->setLabel("x");
    ui->customPlot1->yAxis->setLabel("y");

    // set axes ranges, so we see all data:
    ui->customPlot1->xAxis->setRange(0, 10);
    ui->customPlot1->xAxis->ticker()->setTickCount(12);
    ui->customPlot1->yAxis->ticker()->setTickCount(2);
    ui->customPlot1->yAxis->setRange(0,500);
    ui->customPlot1->replot();

}

void MainWindow::makePlot2()
{
    // generate some data:
    QVector<double> x(4000), y(4000); // initialize with entries 0..100
    for (int i=0; i<2000; ++i)
    {
        x[i] = i; // x goes from -1 to 1
        y[i] = cos(x[i]*( 3.141592653589793238/180)); // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->customPlot2->setInteraction(QCP::iRangeDrag,true);
    ui->customPlot2->setInteraction(QCP::iRangeZoom,true);
    ui->customPlot2->addGraph();
    ui->customPlot2->graph(0)->setBrush(QBrush(QColor(0, 15, 255, 20)));
    ui->customPlot2->graph(0)->setPen(QPen(Qt::darkCyan));
    ui->customPlot2->graph(0)->setData(x, y);

    // give the axes some labels:
    ui->customPlot2->xAxis->setLabel("x");
    ui->customPlot2->yAxis->setLabel("y");

    // set axes ranges, so we see all data:
    ui->customPlot2->xAxis->setRange(0, 1440);
    ui->customPlot2->xAxis->ticker()->setTickCount(12);
    ui->customPlot2->yAxis->ticker()->setTickCount(2);
    ui->customPlot2->yAxis->setRange(-1, 1);
    ui->customPlot2->replot();

}

void MainWindow::makePlot3()
{
    // generate some data:
    QVector<double> x(4000), y(4000); // initialize with entries 0..100
    for (int i=0; i<2000; ++i)
    {
        x[i] = i; // x goes from -1 to 1
        y[i] = tan(x[i]*( 3.141592653589793238/180)); // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->customPlot3->setInteraction(QCP::iRangeDrag,true);
    ui->customPlot3->setInteraction(QCP::iRangeZoom,true);
    ui->customPlot3->addGraph();
    ui->customPlot3->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->customPlot3->graph(0)->setPen(QPen(Qt::darkGreen));
    ui->customPlot3->graph(0)->setData(x, y);

    // give the axes some labels:
    ui->customPlot3->xAxis->setLabel("x");
    ui->customPlot3->yAxis->setLabel("y");

    // set axes ranges, so we see all data:
    ui->customPlot3->xAxis->setRange(0, 1440);
    ui->customPlot3->xAxis->ticker()->setTickCount(12);
    ui->customPlot3->yAxis->ticker()->setTickCount(2);
    ui->customPlot3->yAxis->setRange(-1, 1);
    ui->customPlot3->replot();


}


void MainWindow::makePlot4()
{
    // generate some data:
    QVector<double> x(4000), y(4000); // initialize with entries 0..100
    for (int i=0; i<2000; ++i)
    {
        x[i] = i; // x goes from -1 to 1
        y[i] = sin(x[i]*( 3.141592653589793238/180)); // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->customPlot4->setInteraction(QCP::iRangeDrag,true);
    ui->customPlot4->setInteraction(QCP::iRangeZoom,true);
    ui->customPlot4->addGraph();
    ui->customPlot4->graph(0)->setBrush(QBrush(QColor(0, 120, 255, 20)));
    ui->customPlot4->graph(0)->setPen(QPen(Qt::darkYellow));
    ui->customPlot4->graph(0)->setData(x, y);

    // give the axes some labels:
    ui->customPlot4->xAxis->setLabel("x");
    ui->customPlot4->yAxis->setLabel("y");

    // set axes ranges, so we see all data:
    ui->customPlot4->xAxis->setRange(0, 1440);
    ui->customPlot4->xAxis->ticker()->setTickCount(12);
    ui->customPlot4->yAxis->ticker()->setTickCount(2);
    ui->customPlot4->yAxis->setRange(-1, 1);
    ui->customPlot4->replot();

}
/*
void MainWindow::on_colorButton_clicked()
{
    ui->customPlot1->graph(0)->setPen(QPen(Qt::blue));
    ui->customPlot1->graph(0)->setBrush(QBrush(QColor(100, 120, 255, 20)));
    ui->customPlot2->graph(0)->setPen(QPen(Qt::blue));
    ui->customPlot2->graph(0)->setBrush(QBrush(QColor(100, 120, 255, 20)));
    ui->customPlot3->graph(0)->setPen(QPen(Qt::blue));
    ui->customPlot3->graph(0)->setBrush(QBrush(QColor(100, 120, 255, 20)));
    ui->customPlot4->graph(0)->setPen(QPen(Qt::blue));
    ui->customPlot4->graph(0)->setBrush(QBrush(QColor(100, 120, 255, 20)));
    ui->customPlot1->replot();
    ui->customPlot2->replot();
    ui->customPlot3->replot();
    ui->customPlot4->replot();
}

void MainWindow::on_reset_clicked()
{
    ui->customPlot1->graph(0)->setPen(QPen(Qt::red));
    ui->customPlot2->graph(0)->setPen(QPen(Qt::darkCyan));
    ui->customPlot3->graph(0)->setPen(QPen(Qt::darkGreen));
    ui->customPlot4->graph(0)->setPen(QPen(Qt::darkYellow));
    ui->customPlot1->replot();
    ui->customPlot2->replot();
    ui->customPlot3->replot();
    ui->customPlot4->replot();
}

void MainWindow::on_increaseThickness_clicked()
{
    ++PEN_WIDTH;
    ui->customPlot1->graph(0)->setPen(QPen(Qt::red,PEN_WIDTH));
    ui->customPlot2->graph(0)->setPen(QPen(Qt::darkCyan,PEN_WIDTH));
    ui->customPlot3->graph(0)->setPen(QPen(Qt::darkGreen,PEN_WIDTH));
    ui->customPlot4->graph(0)->setPen(QPen(Qt::darkYellow,PEN_WIDTH));
    ui->customPlot1->replot();
    ui->customPlot2->replot();
    ui->customPlot3->replot();
    ui->customPlot4->replot();
}

void MainWindow::on_decreaseThickness_clicked()
{
    --PEN_WIDTH;
    ui->customPlot1->graph(0)->setPen(QPen(Qt::red,PEN_WIDTH));
    ui->customPlot2->graph(0)->setPen(QPen(Qt::darkCyan,PEN_WIDTH));
    ui->customPlot3->graph(0)->setPen(QPen(Qt::darkGreen,PEN_WIDTH));
    ui->customPlot4->graph(0)->setPen(QPen(Qt::darkYellow,PEN_WIDTH));
    ui->customPlot1->replot();
    ui->customPlot2->replot();
    ui->customPlot3->replot();
    ui->customPlot4->replot();
}

void MainWindow::on_restoreBack_clicked()
{
   PEN_WIDTH = 2;
   makePlot1();
   makePlot2();
   makePlot3();
   makePlot4();
}*/

void MainWindow::on_actionColor_triggered()
{
    ui->customPlot1->graph(0)->setPen(QPen(Qt::blue));
    ui->customPlot1->graph(0)->setBrush(QBrush(QColor(100, 120, 255, 20)));
    ui->customPlot2->graph(0)->setPen(QPen(Qt::blue));
    ui->customPlot2->graph(0)->setBrush(QBrush(QColor(100, 120, 255, 20)));
    ui->customPlot3->graph(0)->setPen(QPen(Qt::blue));
    ui->customPlot3->graph(0)->setBrush(QBrush(QColor(100, 120, 255, 20)));
    ui->customPlot4->graph(0)->setPen(QPen(Qt::blue));
    ui->customPlot4->graph(0)->setBrush(QBrush(QColor(100, 120, 255, 20)));
    ui->customPlot1->replot();
    ui->customPlot2->replot();
    ui->customPlot3->replot();
    ui->customPlot4->replot();
}

void MainWindow::on_actionReset_Color_triggered()
{
    ui->customPlot1->graph(0)->setPen(QPen(Qt::red));
    ui->customPlot2->graph(0)->setPen(QPen(Qt::darkCyan));
    ui->customPlot3->graph(0)->setPen(QPen(Qt::darkGreen));
    ui->customPlot4->graph(0)->setPen(QPen(Qt::darkYellow));
    ui->customPlot1->replot();
    ui->customPlot2->replot();
    ui->customPlot3->replot();
    ui->customPlot4->replot();
}

void MainWindow::on_actionIncrease_Thickness_triggered()
{
    ++PEN_WIDTH;
    ui->customPlot1->graph(0)->setPen(QPen(Qt::red,PEN_WIDTH));
    ui->customPlot2->graph(0)->setPen(QPen(Qt::darkCyan,PEN_WIDTH));
    ui->customPlot3->graph(0)->setPen(QPen(Qt::darkGreen,PEN_WIDTH));
    ui->customPlot4->graph(0)->setPen(QPen(Qt::darkYellow,PEN_WIDTH));
    ui->customPlot1->replot();
    ui->customPlot2->replot();
    ui->customPlot3->replot();
    ui->customPlot4->replot();
}

void MainWindow::on_actionDecrease_Thickness_triggered()
{
    --PEN_WIDTH;
    ui->customPlot1->graph(0)->setPen(QPen(Qt::red,PEN_WIDTH));
    ui->customPlot2->graph(0)->setPen(QPen(Qt::darkCyan,PEN_WIDTH));
    ui->customPlot3->graph(0)->setPen(QPen(Qt::darkGreen,PEN_WIDTH));
    ui->customPlot4->graph(0)->setPen(QPen(Qt::darkYellow,PEN_WIDTH));
    ui->customPlot1->replot();
    ui->customPlot2->replot();
    ui->customPlot3->replot();
    ui->customPlot4->replot();
}

void MainWindow::on_actionRestore_triggered()
{
    PEN_WIDTH = 2;
    makePlot1();
    makePlot2();
    makePlot3();
    makePlot4();
}
