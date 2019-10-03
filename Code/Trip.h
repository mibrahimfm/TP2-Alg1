#ifndef TRIP_H
#define TRIP_H

#include <iostream>
#include "Island.h"

using std::cout;
using std::endl;

class Trip{
private:
    int _moneyToSpend, _ammountIslands;
    Island* _islands;
    int max(int, int);
    Island* sortByValue();
    void mergeSort(Island[], int, int);
    void merge(Island[], int, int, int);
public:
    Trip(int, int, Island[]);
    void MaxPointsRepeatingIslands();
    void MaxPointsWithoutRepeating();
};


#endif