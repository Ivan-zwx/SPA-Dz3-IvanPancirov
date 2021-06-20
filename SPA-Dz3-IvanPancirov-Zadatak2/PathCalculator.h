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
		//cout << "p: " << p.first << " " << p.second << endl;
		//cout << "w: " << w.at(i).first << " " << w.at(i).second << endl;
		if ((p.first == w.at(i).first) && (p.second == w.at(i).second))
		{
			return true;
		}
	}
	//cout << endl;
	return false;
}
bool isVisited(point p, points vis)
{
	for (unsigned int i = 0; i < vis.size(); i++)
	{
		if ((p.first == vis.at(i).first) && (p.second == vis.at(i).second))
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
	points visited;
	int loopCount = 0;

	while (loopCount < 800)
	{
		loopCount += 1;
		//cout << "xcurr: " << xCurrent << endl;
		//cout << "ycurr: " << yCurrent << endl;
		if (xCurrent == xDestination && yCurrent == yDestination)
		{
			break;
		}

		if (xCurrent < xDestination)
		{
			if (validX(xCurrent + 1) && !isPointAtTheWall(point(xCurrent +1, yCurrent), walls) && !isVisited(point(xCurrent + 1, yCurrent), visited))
			{
				xCurrent += 1;
				currentPoint.first = xCurrent;
				currentPoint.second = yCurrent;
				path.push_back(currentPoint);
				visited.push_back(currentPoint);
				continue;
			}
		}
		else if (xCurrent > xDestination)
		{
			if (validX(xCurrent - 1) && !isPointAtTheWall(point(xCurrent -1, yCurrent), walls) && !isVisited(point(xCurrent - 1, yCurrent), visited))
			{
				xCurrent -= 1;
				currentPoint.first = xCurrent;
				currentPoint.second = yCurrent;
				path.push_back(currentPoint);
				visited.push_back(currentPoint);
				continue;
			}
		}

	// micem drugi while
		if (yCurrent < yDestination)
		{
			if (validY(yCurrent + 1) && !isPointAtTheWall(point(xCurrent, yCurrent + 1), walls) && !isVisited(point(xCurrent, yCurrent + 1), visited))
			{
				yCurrent += 1;
				currentPoint.first = xCurrent;
				currentPoint.second = yCurrent;
				path.push_back(currentPoint);
				visited.push_back(currentPoint);
				continue;
			}
		}
		else if (yCurrent > yDestination)
		{
			if (validY(yCurrent - 1) && !isPointAtTheWall(point(xCurrent, yCurrent - 1), walls) && !isVisited(point(xCurrent, yCurrent - 1), visited))
			{
				yCurrent -= 1;
				currentPoint.first = xCurrent;
				currentPoint.second = yCurrent;
				path.push_back(currentPoint);
				visited.push_back(currentPoint);
				continue;
			}
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
