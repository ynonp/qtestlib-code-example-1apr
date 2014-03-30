#include <QtCore/QtCore>
#include <QTest>
#include "testgamelogic.h"

int main(int argc, char **argv)
{
  QCoreApplication app(argc, argv);

  if ( app.arguments().size() < 2 )
  {
    qDebug() << "Usage: test <TestType>";
    return 1;
  }
  else if ( app.arguments()[1] == "GameLogic" )
  {
    TestGameLogic t1;
    return QTest::qExec(&t1, argc - 1, &argv[1]);
  }
  else
  {
    qDebug() << "Unknown test type: " << app.arguments()[1];
    qDebug() << "Available types: GameLogic";
    return 2;
  }

}



