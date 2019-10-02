#ifndef TRIP_H
#define TRIP_H

class Trip{
private:
    int moneyToSpend, ammountIslands;
    int *costs, *points;
public:
    Trip(int, int, int*, int*);
    int MaxPointsRepeatingIslands();
    int MaxPointsWithoutRepeating();
    int Max(int, int);
};


#endif