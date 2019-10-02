#include <iostream>
#include <fstream>
#include <string.h>

using std::ifstream;
using std::string;
using std::cout;

int main(int argc, char** argv){
    string fileName = argv[1];

    ifstream input(fileName);

    int maxSpent, ammountIslands;
    int** islandsInfo;

    if(input.is_open()){

        input >> maxSpent >> ammountIslands;

        islandsInfo = new int*[ammountIslands];
        for(int i = 0; i < ammountIslands; i++){
            islandsInfo[i] = new int[2];
        }
        for(int i = 0; i < ammountIslands; i++){
            input >> islandsInfo[i][0] >> islandsInfo[i][1];
        }
    }
    else{
        cout << "Erro ao abrir o arquivo " << fileName;
    }
}