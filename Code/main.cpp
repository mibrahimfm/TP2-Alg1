#include <iostream>
#include <fstream>
#include <string.h>
//#include <chrono>
#include "Trip.h"
#include "Island.h"

//using namespace std::chrono;
using std::ifstream;
using std::string;
using std::cout;
using std::endl;


int main(int argc, char** argv){
    if(argc > 1){ //Checks if the file name was passed as a program parameter

        string fileName = argv[1];
    
        ifstream input(fileName);

        int moneyToSpend, ammountIslands;
        int *costs, *points;


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
            cout << "Couldn't open file " << fileName << 
                ", please check if the file name is correct and if it actually exists" << endl;;
        }
    }
    else{
        cout << "Please pass a file name as a parameter to the program" << endl;
    }
     
}