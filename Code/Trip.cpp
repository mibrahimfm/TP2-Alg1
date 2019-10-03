#include "Trip.h"

Trip::Trip(int m, int ai, Island i[]) : _moneyToSpend(m), _ammountIslands(ai), _islands(i){}

//Finds maximum points and the duration from a trip where it's allowed to repeat islands
void Trip::MaxPointsRepeatingIslands(){
    auto sortedIslands = this->sortByValue();
    int m = this->_moneyToSpend, i = 0, maxPoints = 0, days = 0;

    while(m > 0 && i < this->_ammountIslands){
        if(sortedIslands[i].getCost() <= m){
            int aux = m / sortedIslands[i].getCost();

            m = m % sortedIslands[i].getCost();
            days += aux;
            maxPoints += (aux * sortedIslands[i].getPoints());
        }
        else{
            i++;
        }
    }
    
    cout << maxPoints << " " << days << endl;
}

//Sorts islands by their value in descending order
Island* Trip::sortByValue(){
    auto sortedIslands = this->_islands;

    mergeSort(sortedIslands, 0, this->_ammountIslands-1);

    return sortedIslands;
}

//merge sort implementation to order the array of islands
void Trip::mergeSort(Island is[], int left, int right){ 
    if (left < right){ 
        int middle = left+(right-left)/2; 
  
        mergeSort(is, left, middle); 
        mergeSort(is, middle+1, right); 
  
        merge(is, left, middle, right); 
    } 
}

void Trip::merge(Island is[], int left, int middle, int right){ 
    int i, j, k; 
    int n1 = middle - left + 1; 
    int n2 =  right - middle; 
  
    Island L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++){
        L[i] = is[left + i]; 
    }
    for (j = 0; j < n2; j++){
        R[j] = is[middle + 1 + j]; 
    }

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2){
        if (L[i].getValue() > R[j].getValue()){ 
            is[k] = L[i]; 
            i++; 
        } 
        else{ 
            is[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1){ 
        is[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2){ 
        is[k] = R[j]; 
        j++; 
        k++; 
    }    
}

//Finds maximum points and the duration from a trip where it's not allowed to repeat islands
void Trip::MaxPointsWithoutRepeating(){
    int m = this->_moneyToSpend, ai = this->_ammountIslands;
    int i, j, maxPoints, days = 0;
    int values[ai+1][m+1];

    for(i = 0; i <= ai; i++){
        for(j = 0; j <=m; j++){
            if(i==0 || j==0){
                values[i][j] = 0;
            }
            else if(this->_islands[i-1].getCost() <= j){
                values[i][j] = Trip::max(this->_islands[i-1].getPoints() + values[i-1][j-this->_islands[i-1].getCost()], values[i-1][j]);
            }
            else{
                values[i][j] = values[i-1][j];
            }
        }
    }

    maxPoints = values[ai][m];


    int pointsAux = maxPoints;    
    j = m;
    
    for(i = ai; i > 0 && pointsAux > 0; i--){
        if(pointsAux == values[i-1][j])
            continue;
        else{
            days++;
            pointsAux -= this->_islands[i-1].getPoints();
            j -= this->_islands[i-1].getCost();
        }
    }

    cout << maxPoints << " " << days << endl;
}

int Trip::max(int a, int b){
    return (a > b) ? a : b;
}