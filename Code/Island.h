#ifndef ISLAND_H
#define ISLAND_H

class Island{
private:

public:
    int cost, points;
    float value;
    Island(){};
    Island(int, int);
    float FindValue();
};


#endif