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
    void MaxPointsRepeatingIslands();
    void MaxPointsWithoutRepeating();
    int Max(int, int);
    Island* SortByValue();
    void MergeSort(Island[], int, int);
    void Merge(Island[], int, int, int);
};


#endif