#include "testgamelogic.h"
#include "../gamelogic.h"

#include <QTest>

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
            QVERIFY2(l.set_cell(i,j,1)==1,QString("set_cell(%1,%2)").arg(i,j).toStdString().c_str());
        }
    }
}

void TestGameLogic::testSetCellTwice()
{
    GameLogic l;
    QVERIFY2(l.set_cell(0,1,1)==1,"set_cell(0,1) works first time");
    QVERIFY2(l.set_cell(0,1,1)==0,"set_cell(0,1) fails second time");
}

void TestGameLogic::testSetCellTwiceWithDifferentValues()
{
    GameLogic l;
    QVERIFY2(l.set_cell(0,1,1)==1,"set_cell(0,1) works first time");
    QVERIFY2(l.set_cell(0,1,2)==0,"set_cell(0,1) fails second time");
}
