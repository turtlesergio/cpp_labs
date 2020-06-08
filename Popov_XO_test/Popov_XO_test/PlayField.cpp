#include <cassert>
#include "PlayField.h"

using namespace std;

PlayField PlayField::makeMove(CellPos cell) const {
    assert(playboard[cell.getX()][cell.getY()] == csEmpty);
    return (*this) + (cell);
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
    assert(Xs - Os <= 1);
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
    PlayField updatedField = PlayField(*this);
    updatedField.playboard[cell.getX()][cell.getY()] = nextMove();
    return updatedField;
}

PlayField::FieldStatus PlayField::checkFieldStatus() const { // doesn't

    int Xs = 0, Os = 0;
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            if (playboard[i][j] == csCross)
                Xs++;
            if (playboard[i][j] == csNought)
                Os++;
        }
    }
    if (Xs > 2) {
        // check Horizontal and Vertical lines
        for (int i = 0; i < m_size; i++) {
            if ((playboard[0][i] != csEmpty) &&
                ((playboard[0][i] == playboard[1][i]) && (playboard[1][i] == playboard[2][i]))) // case '—'
                return playboard[0][i] == csCross ? fsCrossesWin : fsNoughtsWin;
            if ((playboard[i][0] != csEmpty) &&
                ((playboard[i][0] == playboard[i][1]) && (playboard[i][1] == playboard[i][2]))) // case '|'
                return playboard[i][0] == csCross ? fsCrossesWin : fsNoughtsWin;
        }
        // check Diagonal lines
        if (playboard[1][1] != csEmpty &&
            (((playboard[0][0] == playboard[1][1]) && (playboard[1][1] == playboard[2][2])) ||	// case '\'
             ((playboard[2][0] == playboard[1][1]) && (playboard[1][1] == playboard[0][2]))))	// case '/'
            return playboard[1][1] == csCross ? fsCrossesWin : fsNoughtsWin;
    }
    if (PlayField::getEmptyCells().empty())
        return fsDraw;
    return ((Xs - Os == 0) || (Xs - Os == 1)) ? fsNormal : fsInvalid;
}
