#include "iostream"
#include "vector"
#include "cassert"
#include "stdafx.h"
#include "PlayField.h"

using namespace std;

PlayField PlayField::makeMove(CellPos cell) const {
	assert(playboard[cell.getX()][cell.getY()] == csEmpty);
	return PlayField(*this) + (cell);
}

PlayField::CellStatus PlayField::nextMove() const {
	int Xs = 0, Os = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (playboard[i][j] == csCross)
				Xs++;
			if (playboard[i][j] == csNought)
				Os++;
		}
	}
	assert(Xs + Os <= 9);
	return Xs > Os ? csNought : csCross;
}

vector<PlayField::CellPos> PlayField::getEmptyCells() const {
	vector<CellPos> emptyCells;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (playboard[i][j] == csEmpty) {
				emptyCells.push_back(PlayField::CellPos({ i, j }));
			}
		}
	}
	return emptyCells;
}

PlayField::CellStatus PlayField::operator[](CellPos cell) {
	return playboard[cell.getX()][cell.getY()];
}

PlayField PlayField::operator+(CellPos cell) {
	PlayField updatedField = PlayField(*this);
	updatedField.playboard[cell.getX()][cell.getY()] = nextMove();
	return updatedField;
}

PlayField::FieldStatus PlayField::checkFieldStatus() const {	// bug gde-to zdes'
	int Xs = 0, Os = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (playboard[i][j] == csCross)
				Xs++;
			if (playboard[i][j] == csNought)
				Os++;
		}
	} 
	// check Horizontal and Vertical lines
	for (int i = 0; i < 3; i++) {
		if ((playboard[0][i] != csEmpty) &&
			((playboard[0][i] == playboard[1][i]) && (playboard[1][i] == playboard[2][i]))) // case '�'
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

	if (PlayField::getEmptyCells().empty()) return fsDraw;
	return (abs(Xs - Os) < 2) ? fsNormal : fsInvalid;
}
