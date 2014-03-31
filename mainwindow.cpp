#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets/QtWidgets>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_mapper.setMapping(ui->pushButton_00, "0,0");
    m_mapper.setMapping(ui->pushButton_01, "0,1");
    m_mapper.setMapping(ui->pushButton_02, "0,2");
    m_mapper.setMapping(ui->pushButton_10, "1,0");
    m_mapper.setMapping(ui->pushButton_11, "1,1");
    m_mapper.setMapping(ui->pushButton_12, "1,2");
    m_mapper.setMapping(ui->pushButton_20, "2,0");
    m_mapper.setMapping(ui->pushButton_21, "2,1");
    m_mapper.setMapping(ui->pushButton_22, "2,2");

    QObject::connect(ui->pushButton_00, SIGNAL(clicked()), &m_mapper, SLOT(map()));
    QObject::connect(ui->pushButton_01, SIGNAL(clicked()), &m_mapper, SLOT(map()));
    QObject::connect(ui->pushButton_02, SIGNAL(clicked()), &m_mapper, SLOT(map()));
    QObject::connect(ui->pushButton_10, SIGNAL(clicked()), &m_mapper, SLOT(map()));
    QObject::connect(ui->pushButton_11, SIGNAL(clicked()), &m_mapper, SLOT(map()));
    QObject::connect(ui->pushButton_12, SIGNAL(clicked()), &m_mapper, SLOT(map()));
    QObject::connect(ui->pushButton_20, SIGNAL(clicked()), &m_mapper, SLOT(map()));
    QObject::connect(ui->pushButton_21, SIGNAL(clicked()), &m_mapper, SLOT(map()));
    QObject::connect(ui->pushButton_22, SIGNAL(clicked()), &m_mapper, SLOT(map()));

    QObject::connect(&m_mapper,SIGNAL(mapped(QString)),this,SLOT(clicked(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clicked(QString where)
{
    QStringList coords = where.split(",");
    int result = m_game.play(coords[0].toInt(), coords[1].toInt());
    if ( result )
    {
        QPushButton *btn = qobject_cast<QPushButton *>(m_mapper.mapping(where));
        QString player = result == 1 ? "X" : "O";
        btn->setText(player);

        if ( m_game.has_winner() )
        {
            QMessageBox::information(this,"Winner",QString("Player %1 won").arg(player));
        }
    }

}
