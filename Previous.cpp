#include "Previous.h"
#include <iostream>
using namespace std;
Previous::Previous(int nRows, int nCols)
{
	m_rows = nRows;
	m_cols = nCols;
	for (int i = 0; i < m_rows; ++i)
	{
		for (int j = 0; j < m_cols; ++j)
		{
			m_grid[i][j] = false;
		}
	}
}

bool Previous::dropACrumb(int r, int c)
{
	if (r > m_rows || c > m_cols || r < 1 || c < 1)
	{
		return false;
	}
	else
	{
		m_grid[r - 1][c - 1] += 1;
		return true;
	}
}

void Previous::showPreviousMoves() const
{
	char letters[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	void clearScreen();
	for (int i = 0; i < m_rows; ++i)
	{
		for (int j = 0; j < m_cols; ++j)
		{
			if (m_grid[i][j] > 0 && m_grid[i][j] < 26)
			{
				cout << letters[m_grid[i][j] - 1];
			}
			else if (m_grid[i][j] > 25)
			{
				cout << 'Z';
			}
			else
			{
				cout << ".";
			}
		}
		cout << endl;
	}
	cout << endl;
}