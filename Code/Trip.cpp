#include "Trip.h"

Trip::Trip(int m, int ai, Island i[]) : moneyToSpend(m), ammountIslands(ai), islands(i){}

int Trip::MaxPointsRepeatingIslands(){

}


void Trip::MaxPointsWithoutRepeating(){
    int m = this->moneyToSpend, ai = this->ammountIslands;
    int i, j, maxPoints, days = 0;
    int values[ai+1][m+1];

    for(i = 0; i <= ai; i++){
        for(j = 0; j <=m; j++){
            if(i==0 || j==0){
                values[i][j] = 0;
            }
            else if(this->islands[i-1].cost <= j){
                values[i][j] = Trip::Max(this->islands[i-1].points + values[i-1][j-this->islands[i-1].cost], values[i-1][j]);
            }
            else{
                values[i][j] = values[i-1][j];
            }
        }
    }

    maxPoints = values[ai][m];
    std::cout << maxPoints << " ";
    j = m;
    for(i = ai; i > 0 && maxPoints > 0; i--){
        if(maxPoints == values[i-1][j])
            continue;
        else{
            days++;
            maxPoints -= islands[i-1].points;
            j -= islands[i-1].cost;
        }
    }

    std::cout << days << std::endl;
}

int Trip::Max(int a, int b){
    return (a > b) ? a : b;
}