#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui/QtGui>
#include "gamelogic.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void clicked(QString where);

private:
    Ui::MainWindow *ui;

    QSignalMapper m_mapper;
    GameLogic m_game;
};

#endif // MAINWINDOW_H
