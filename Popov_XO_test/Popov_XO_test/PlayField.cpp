#include <cassert>
#include "PlayField.h"

using namespace std;

PlayField PlayField::makeMove(CellPos cell) const {
    assert(playboard[cell.getX()][cell.getY()] == csEmpty);
    return *this + cell;
}

PlayField::CellStatus PlayField::nextMove() const {
    int Xs = 0, Os = 0;
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            if (playboard[i][j] == csCross)
                Xs++;
            if (playboard[i][j] == csNought)
                Os++;
        }
    }
    assert((Xs - Os > -1) && (Xs - Os < 2));
    return Xs > Os ? csNought : csCross;
}

vector<PlayField::CellPos> PlayField::getEmptyCells() const {
    vector<CellPos> emptyCells;
    for (int i = 0; i < m_size; i++)
        for (int j = 0; j < m_size; j++)
            if (playboard[i][j] == csEmpty)
                emptyCells.push_back({ i, j });
    return emptyCells;
}

PlayField::CellStatus PlayField::operator[](CellPos cell) const {
    return playboard[cell.getX()][cell.getY()];
}

PlayField PlayField::operator+(CellPos cell) const {
    assert(playboard[cell.getX()][cell.getY()] == csEmpty);
    PlayField updatedField = *this;
    updatedField.playboard[cell.getX()][cell.getY()] = nextMove();
    return updatedField;
}

PlayField::FieldStatus PlayField::checkFieldStatus() const {
    int Xs = 0, Os = 0;
    auto size = PlayField::m_size;
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            if (playboard[i][j] == csCross)
                Xs++;
            if (playboard[i][j] == csNought)
                Os++;
        }
    }
    if (!((Xs - Os == 1) || (Xs - Os == 0)))
        return fsInvalid;
    if (Xs >= size) {
        int horizWinCounter = 0, vertWinCounter = 0;
        for (int i = 0; i < size; i++) {
            auto markX = csEmpty, markY = csEmpty, markZ1 = csEmpty, markZ2 = csEmpty;
            auto sumX = 0, sumY = 0, sumZ1 = 0, sumZ2 = 0;
            for (int c = 0; c < size - 1; c++) {
                auto cpp = c + 1;
                if ((playboard[c][i] != csEmpty) && (playboard[c][i] == playboard[cpp][i])) { // горизонтальная проверка
                    markX = playboard[c][i];
                    sumX++;
                    if (sumX == size - 1)
                        horizWinCounter++;
                }
                if ((playboard[i][c] != csEmpty) && (playboard[i][c] == playboard[i][cpp])) { // вертикальная
                    markY = playboard[i][c];
                    sumY++;
                    if (sumY == size - 1)
                        vertWinCounter++;
                }
                if ((playboard[c][c] != csEmpty) && (playboard[c][c] == playboard[cpp][cpp])) { // основная диагональ
                    sumZ1++;
                    markZ1 = playboard[c][c];
                }
                if ((playboard[size - c - 1][c] != csEmpty) &&
                    (playboard[size - c - 1][c] == playboard[size - c - 2][cpp])) { // побочная диагональ
                    sumZ2++;
                    markZ2 = playboard[c][c];
                }
            }
            assert(horizWinCounter < 2 && vertWinCounter < 2); // проверка на неналичие двух побед одновременно
            if (sumX == size - 1)
                return markX == csCross ? fsCrossesWin : fsNoughtsWin;
            if (sumY == size - 1)
                return markY == csCross ? fsCrossesWin : fsNoughtsWin;
            if (sumZ1 == size - 1)
                return markZ1 == csCross ? fsCrossesWin : fsNoughtsWin;
            if (sumZ2 == size - 1)
                return markZ2 == csCross ? fsCrossesWin : fsNoughtsWin;
        }
        if ((Xs + Os) == (size * size))
            return fsDraw;
    }
    return fsNormal;
}
