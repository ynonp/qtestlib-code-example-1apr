#ifndef TESTGAMELOGIC_H
#define TESTGAMELOGIC_H

#include <QObject>

class TestGameLogic : public QObject
{
    Q_OBJECT

public:
    TestGameLogic(QObject *parent=NULL);

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
    void testSetEmptyCells();
    void testSetCellTwice();
    void testSetCellTwiceWithDifferentValues();
};


#endif // TESTGAMELOGIC_H
