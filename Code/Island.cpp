#include "Island.h"

Island::Island(int c, int p) : cost(c), points(p){
    this->value = FindValue();
}

float Island::FindValue(){
    return (float)this->points / this->cost;
}