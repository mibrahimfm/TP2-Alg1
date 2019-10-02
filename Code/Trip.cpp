#include "Trip.h"

Trip::Trip(int m, int ai, int* c, int* p) : moneyToSpend(m), ammountIslands(ai), costs(c), points(p){}

int Trip::MaxPointsRepeatingIslands(){

}

int Trip::MaxPointsWithoutRepeating(){
    int ai = this->ammountIslands, m = this->moneyToSpend;
    int i, j;
    int **maxValue = new int*[ai+1];
    for(int i = 0; i <= ai; i++){
        maxValue[i] = new int[m+1];
    }

    for(i = 0; i <= ai; i++){
        for(j = 0; j <=m; j++){
            if(i==0 || j==0){
                maxValue[i][j] = 0;
            }
            else if(this->costs[i-1] <= j){
                maxValue[i][j] = this->Max(points[i-1] + maxValue[i-1][j-costs[i-1]], maxValue[i-1][j]);
            }
            else{
                maxValue[i][j] = maxValue[i-1][j];
            }
        }
    }

    return maxValue[i][j];
}

int Trip::Max(int a, int b){
    return a > b ? a : b;
}