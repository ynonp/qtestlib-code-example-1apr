#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QObject>
#include <QList>

class GameLogic : public QObject
{
    Q_OBJECT
public:
    explicit GameLogic(QObject *parent = 0);

signals:

public slots:
    bool set_cell(int x, int y, int newVal);
    int has_winner();
    void reset();

private:
    int cell_idx(int x, int y);
    int val(int x, int y);

    int has_winner_row(int row);
    int has_winner_col(int col);
    int has_winner_diag();

private:
    QList<int> m_board;
};

#endif // GAMELOGIC_H
