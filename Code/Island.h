#ifndef ISLAND_H
#define ISLAND_H

class Island{
private:
    int _cost, _points;
    float _value;
public:
    Island(){}; //Default constructor to allow creation of empty variables of type Island
    Island(int, int);
    float FindValue();
    int getCost();
    int getPoints();
    float getValue();
};


#endif