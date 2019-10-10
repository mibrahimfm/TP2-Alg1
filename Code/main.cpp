#include <iostream>
#include <fstream>
#include <string.h>
#include <chrono>
#include "Trip.h"
#include "Island.h"

using namespace std::chrono;
using std::ifstream;
using std::string;
using std::cout;
using std::endl;


int main(int argc, char** argv){
    string fileName = argv[1];

    ifstream input(fileName);

    int moneyToSpend, ammountIslands;
    int *costs, *points;

    auto start = high_resolution_clock::now();

    if(input.is_open()){
        input >> moneyToSpend >> ammountIslands;

        costs = new int[ammountIslands];
        points = new int[ammountIslands];
        
        for(int i = 0; i < ammountIslands; i++){
            input >> costs[i] >> points[i];
        }


        Island islands[ammountIslands];
        for(int i = 0; i < ammountIslands; i++){
            islands[i] = Island(costs[i], points[i]);
        }

        Trip t(moneyToSpend, ammountIslands, islands);
        t.MaxPointsRepeatingIslands();
        t.MaxPointsWithoutRepeating();

    }
    else{
        cout << "Erro ao abrir o arquivo " << fileName << endl;;
    }

    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start); 

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
}