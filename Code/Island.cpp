#include "Island.h"

Island::Island(int c, int p) : _cost(c), _points(p){
    this->_value = FindValue();
}

int Island::getCost(){ return this->_cost; }

int Island::getPoints(){ return this->_points; }

float Island::getValue(){ return this->_value; }

//Calculates the value of an island
//given by how many points the island is worth divided by the cost of traveling there
float Island::FindValue(){
    return (float)this->_points / this->_cost;
}