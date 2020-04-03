#pragma once

#include "iostream"
#include "vector"
#include "cassert"
#include "stdafx.h"
#include "initializer_list"

class PlayField {
public:
	enum CellStatus { csEmpty, csCross, csNought };
	enum FieldStatus { fsInvalid, fsNormal, fsCrossesWin, fsNoughtsWin, fsDraw };
	
	class CellPos {
	public:
		CellPos GetCellPos(std::initializer_list<int> cell) {
			return CellPos(cell);
		}
		void SetCellPos(int x, int y) {
			_x = x;
			_y = y;
		}
		CellPos(std::initializer_list<int> cell) {
			_x = *cell.begin();
			_y = *(cell.begin() + 1);
		}
		const int getX() { return _x; }
		const int getY() { return _y; }
	private:
		int _x, _y;
	};

	PlayField makeMove(CellPos cell) const;
	std::vector<CellPos> getEmptyCells() const;
	FieldStatus checkFieldStatus() const;
	CellStatus operator[](CellPos cell);
private:
	CellStatus playboard[3][3] = { csEmpty, csEmpty, csEmpty, csEmpty, csEmpty, csEmpty, csEmpty, csEmpty, csEmpty, };
	PlayField operator+(CellPos cell);
	CellStatus nextMove() const;
};
