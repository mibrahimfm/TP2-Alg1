#include "Island.h"

Island::Island(int c, int p) : cost(c), points(p){
    this->value = FindValue();
}

int Island::getCost(){ return this->cost; }

int Island::getPoints(){ return this->points; }

float Island::getValue(){ return this->value; }

float Island::FindValue(){
    return (float)this->points / this->cost;
}