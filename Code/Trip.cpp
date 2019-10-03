#include "Trip.h"

int Trip::MaxPointsRepeatingIslands(){

}

void Trip::MaxPointsWithoutRepeating(int m, int ai, int costs[], int points[]){
    int i, j, maxPoints, days = 0;
    int values[ai+1][m+1];

    for(i = 0; i <= ai; i++){
        for(j = 0; j <=m; j++){
            if(i==0 || j==0){
                values[i][j] = 0;
            }
            else if(costs[i-1] <= j){
                values[i][j] = Trip::Max(points[i-1] + values[i-1][j-costs[i-1]], values[i-1][j]);
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
            maxPoints -= points[i-1];
            j -= costs[i-1];
        }
    }

    std::cout << days << std::endl;
}

int Trip::Max(int a, int b){
    return (a > b) ? a : b;
}