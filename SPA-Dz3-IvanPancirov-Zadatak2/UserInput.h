#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "GridBuilder.h"
#include "PathCalculator.h"

using namespace std;

void pointPrint(point p)
{
    cout << "Point data" << endl;
    cout << "x: " << p.first << endl;
    cout << "y: " << p.second << endl;
}

point pointParser(string pointStr)
{
    int x;
    int y;

    string temp;
    stringstream sstr(pointStr);
    getline(sstr, temp, ',');
    x = stoi(temp);
    getline(sstr, temp);
    y = stoi(temp);

    point pointOut(x, y);
    return pointOut;
}

bool userInput(point& pointA, point& pointB, points& walls)
{
    string pointAStr;
    string pointBStr;

    cout << "Unesite pocetnu i zavrsnu tocku (u formatu x,y) u rasponu koordinata 20,40" << endl; //1<=x<=20 i 1<=y<=40
    cout << endl;
    cout << "Tocka A: ";
    cin >> pointAStr;
    cout << endl;
    cout << "Tocka B: ";
    cin >> pointBStr;
    cout << endl;

    point inputPointA = pointParser(pointAStr);
    point inputPointB = pointParser(pointBStr);

    if (inputPointA.first > rows || inputPointA.first < 1)
    {
        cout << endl;
        cout << "Krivi unos" << endl;
        cout << endl;
        return false;
    }
    if (inputPointA.second > columns || inputPointA.second < 1)
    {
        cout << endl;
        cout << "Krivi unos" << endl;
        cout << endl;
        return false;
    }

    pointA = inputPointA;
    pointB = inputPointB;
    Sleep(500);
    return true;
}