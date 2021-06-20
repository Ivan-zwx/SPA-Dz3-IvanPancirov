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

bool wallRead(string filepath, points& walls)
{
    ifstream file(filepath);
    if (!file) { cout << "Greska u pristupu datoteci" << endl; return false; }

    string temp;
    while (getline(file, temp))
    {
        stringstream ss(temp);
        string temp2;
        vector<string> dataVec;
        while (getline(ss, temp2, ','))
        {
            dataVec.push_back(temp2);
        }
        int x = stoi(dataVec.at(0));
        int y = stoi(dataVec.at(1));
        walls.push_back(point(x,y));
    }

    file.close();
    return true;
}