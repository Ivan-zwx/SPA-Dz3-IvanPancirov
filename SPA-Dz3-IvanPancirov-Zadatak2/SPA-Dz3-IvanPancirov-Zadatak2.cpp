#include <iostream>
#include "GridBuilder.h"
#include "PathCalculator.h" 
#include "UserInput.h" 
#include "WallReader.h" 

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

    wallRead("tocke-zida.txt", walls);
    //printPoints(walls);

    grid myGrid = initializeGrid();
    alterGrid(myGrid, pointA, pointB, walls);
    //printGrid(myGrid);

    /***********************************************************/

    points path = calculatePath(myGrid, pointA, pointB, walls);
    //printPoints(path);

    //druga verzija algoritma, izbacena iz rjesenja:
    //points path = seekPath(myGrid, pointA, pointB, walls);

    renderGrid(myGrid, path);

    return 0;
}