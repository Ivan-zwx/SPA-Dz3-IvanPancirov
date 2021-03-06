#include <iostream>
#include "GridBuilder.h"
#include "PathCalculator.h" 
#include "UserInput.h" 

using namespace std;

int main()
{
    point pointA; //(1, 1);
    point pointB; // (10, 10);
    points walls;
    //walls.push_back(point(10, 20));
    //walls.push_back(point(5, 10));

    userInput(pointA, pointB, walls);
    //pointPrint(pointA);
    //pointPrint(pointB);

    grid myGrid = initializeGrid();
    alterGrid(myGrid, pointA, pointB, walls);
    //printGrid(myGrid);

    /***********************************************************/

    points path = calculatePath(myGrid, pointA, pointB, walls);
    //printPoints(path);

    renderGrid(myGrid, path);

    return 0;
}