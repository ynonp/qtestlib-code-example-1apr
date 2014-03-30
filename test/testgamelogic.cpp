#include "testgamelogic.h"
#include "../gamelogic.h"

#include <QTest>

typedef QList<QPair<int,int> > CellsList;

TestGameLogic::TestGameLogic(QObject *parent) :
    QObject(parent)
{
}

void TestGameLogic::initTestCase()
{
}

void TestGameLogic::cleanupTestCase()
{
}

void TestGameLogic::testCase1()
{
    QVERIFY2(true, "Failure");
}

void TestGameLogic::testSetEmptyCells()
{
    GameLogic l;
    for (int i=0; i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            QVERIFY2(l.play(i,j),qPrintable(QString("set_cell(%1,%2)").arg(i,j)));
        }
    }
}

void TestGameLogic::testSetCellTwice()
{
    GameLogic l;
    QVERIFY2(  l.play(0,1),"set_cell(0,1) works first time");
    QVERIFY2(! l.play(0,1),"set_cell(0,1) fails second time");
}


void TestGameLogic::testWinner_data()
{
    QTest::addColumn<CellsList>("moves");
    QTest::addColumn<int>("player");
    QTest::addColumn<int>("winner");

    CellsList moves;
    moves << qMakePair(0,0) << qMakePair(1,0) <<
             qMakePair(0,1) << qMakePair(2,0) <<
             qMakePair(0,2);
    QTest::newRow("1 wins first row") << moves << 1 << 1;

    moves.clear();
    moves << qMakePair(0,0) << qMakePair(0,1) <<
             qMakePair(1,0) << qMakePair(1,1) <<
             qMakePair(2,0);
    QTest::newRow("1 wins first column") << moves << 1 << 1;

    moves.clear();
    moves << qMakePair(0,0) << qMakePair(1,0) <<
             qMakePair(1,1) << qMakePair(2,0) <<
             qMakePair(2,2);
    QTest::newRow("1 wins diagonal") << moves << 1 << 1;
}

void TestGameLogic::testWinner()
{
    GameLogic l;
    QFETCH(CellsList, moves);
    QFETCH(int, player);
    QFETCH(int, winner);

    for(int i=0;i<moves.length();i++)
    {
        QPair<int,int> cell = moves.at(i);
        l.play(cell.first, cell.second);
    }

    QCOMPARE(l.has_winner(),winner);
}
