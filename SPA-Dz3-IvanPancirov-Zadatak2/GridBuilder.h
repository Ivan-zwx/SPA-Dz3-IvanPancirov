#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<char>> grid;
typedef pair<int, int> point;
typedef vector<point> points;

const int rows = 20; //20 redaka
const int columns = 40; //40 stupaca

grid initializeGrid()
{
    grid myGrid;
    for (int i = 0; i < rows; i++)
    {
        vector<char> row;
        for (int j = 0; j < columns; j++)
        {
            row.push_back('-');
        }
        myGrid.push_back(row);
    }
    return myGrid;
}

void alterGrid(grid& myGrid, const point& A, const point& B, const points walls)
{
    myGrid[A.first - 1][A.second - 1] = 'A';
    myGrid[B.first - 1][B.second - 1] = 'B';

    for (unsigned int i = 0; i < walls.size(); i++)
    {
        myGrid[walls.at(i).first - 1][walls.at(i).second - 1] = '*';
    }
}

void printGrid(const grid& myGrid)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << myGrid[i][j];
        }
        cout << endl;
    }
}