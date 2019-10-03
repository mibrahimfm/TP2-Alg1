#ifndef TRIP_H
#define TRIP_H

#include <iostream>
#include "Island.h"

class Trip{
private:
    int moneyToSpend, ammountIslands;
    Island* islands;
public:
    Trip(int, int, Island[]);
    int MaxPointsRepeatingIslands();
    void MaxPointsWithoutRepeating();
    int Max(int, int);
    float* FindValues(int[], int[], int);
};


#endif