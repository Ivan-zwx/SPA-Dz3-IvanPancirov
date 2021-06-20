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

// TOCKE ZIDA SU PISANE U FORMATU (x,y) U RASPONU 0 <= x <= 19 I 0 <= y <= 39

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
        int x = stoi(dataVec.at(0)); //-1
        int y = stoi(dataVec.at(1)); //-1
        walls.push_back(point(x,y));
    }

    file.close();
    return true;
}