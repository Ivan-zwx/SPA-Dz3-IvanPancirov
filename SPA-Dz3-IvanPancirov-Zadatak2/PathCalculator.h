#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <Windows.h>
#include "GridBuilder.h"

using namespace std;


bool validX(int x)
{
	return x < rows;
}
bool validY(int y)
{
	return y < columns;
}
bool isPointAtTheWall(point p, points w)
{
	for (unsigned int i = 0; i < w.size(); i++)
	{
		if ((p.first == w.at(i).first) && (p.second == w.at(i).second))
		{
			return true;
		}
	}
	return false;
}

// while petlja nikada nece producirati invalidne tocke, B ne moze ujedno biti ispod A i invalid (bez zida)
points calculatePath(const grid& myGrid, const point& A, const point& B, const points& walls)
{
	points path;
	point currentPoint;
	int xCurrent = A.first - 1;
	int yCurrent = A.second - 1;
	int xDestination = B.first - 1;
	int yDestination = B.second - 1;

	while (true)
	{
		if (xCurrent < xDestination)
		{
			if (validX(xCurrent + 1) && !isPointAtTheWall(point(xCurrent +1, yCurrent), walls))
			{
				xCurrent += 1;
				currentPoint.first = xCurrent;
				currentPoint.second = yCurrent;
				path.push_back(currentPoint);
			}
		}
		else if (xCurrent > xDestination)
		{
			if (validX(xCurrent - 1))
			{
				xCurrent -= 1;
				currentPoint.first = xCurrent;
				currentPoint.second = yCurrent;
				path.push_back(currentPoint);
			}
		}
		else if (xCurrent == xDestination)
		{
			break;
		}
	}

	while (true)
	{
		if (yCurrent < yDestination)
		{
			if (validY(yCurrent + 1))
			{
				yCurrent += 1;
				currentPoint.first = xCurrent;
				currentPoint.second = yCurrent;
				path.push_back(currentPoint);
			}
		}
		else if (yCurrent > yDestination)
		{
			if (validY(yCurrent - 1))
			{
				yCurrent -= 1;
				currentPoint.first = xCurrent;
				currentPoint.second = yCurrent;
				path.push_back(currentPoint);
			}
		}
		if (yCurrent == yDestination)
		{
			break;
		}
	}

	return path;
}

void printPoints(const points& p)
{
	cout << endl;
	for (unsigned int i = 0; i < p.size(); i++)
	{
		cout << "(" << p.at(i).first << ", " << p.at(i).second << ")" << endl;
	}
	cout << endl;
}

void renderGrid(grid& myGrid, const points& path)
{
	queue<point> pointQ;
	for (unsigned int i = 0; i < path.size(); i++)
	{
		pointQ.push(path.at(i));
	}

	point oldPoint(-1, -1);
	printGrid(myGrid);
	while (!pointQ.empty())
	{
		Sleep(100);
		system("CLS");
		if (oldPoint.first >= 0 && oldPoint.second >= 0)
		{
			myGrid[oldPoint.first][oldPoint.second] = '-';
		}
		point currentPoint = pointQ.front();
		myGrid[currentPoint.first][currentPoint.second] = 'x';
		pointQ.pop();
		printGrid(myGrid);
		oldPoint = currentPoint;
	}
}

// JOS NAPISATI DA SE TOCKE KROZ KOJE PROLAZI x VRAJACU NA -
