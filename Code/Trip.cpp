#include "Trip.h"

Trip::Trip(int m, int ai, Island i[]) : moneyToSpend(m), ammountIslands(ai), islands(i){}

void Trip::MaxPointsRepeatingIslands(){
    auto sortedIslands = this->SortByValue();
    int m = moneyToSpend;
    int i = 0, maxPoints = 0, days = 0;

    while(m > 0 && i < this->ammountIslands){
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
    
    std::cout << maxPoints << " " << days << std::endl;
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
            else if(this->islands[i-1].getCost() <= j){
                values[i][j] = Trip::Max(this->islands[i-1].getPoints() + values[i-1][j-this->islands[i-1].getCost()], values[i-1][j]);
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
            maxPoints -= islands[i-1].getPoints();
            j -= islands[i-1].getCost();
        }
    }

    std::cout << days << std::endl;
}

int Trip::Max(int a, int b){
    return (a > b) ? a : b;
}

void Trip::Merge(Island arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    Island L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0;  
    j = 0;  
    k = l;
    while (i < n1 && j < n2) 
    { 
        if (L[i].getValue() > R[j].getValue()) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    }    
}

void Trip::MergeSort(Island arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        MergeSort(arr, l, m); 
        MergeSort(arr, m+1, r); 
  
        Merge(arr, l, m, r); 
    } 
}

Island* Trip::SortByValue(){
    auto sortedIslands = this->islands;

    MergeSort(sortedIslands, 0, this->ammountIslands-1);

    return sortedIslands;
}