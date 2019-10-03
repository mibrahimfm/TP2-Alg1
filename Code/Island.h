#ifndef ISLAND_H
#define ISLAND_H

class Island{
private:
    int cost, points;
    float value;
public:
    Island(){};
    Island(int, int);
    float FindValue();
    int getCost();
    int getPoints();
    float getValue();
};


#endif