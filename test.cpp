#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "user_code.h"

using namespace std;

int problem1(string inputPath, string outputPath){
    vector<vector<int> > denseMatrix;
    vector<int> values;
    vector<int> columnIndices;
    vector<int> rowPointers;

    ifstream inputFile(inputPath);
    ofstream outputFile(outputPath);
    int N;
    inputFile >> N;
    // read dense matrix from input file
    for(int i = 0; i < N; i++){
        vector<int> temp;
        for(int j = 0; j < N; j++){
            int x;
            inputFile >> x;
            temp.push_back(x);
        }
        denseMatrix.push_back(temp);
    }

    //add input size matrix (N*N )log here
    // measure time taken in nanoseconds
    cout<< "input_size_n:" << denseMatrix.size() << endl;
    clock_t start = clock();
    denseToSparse(denseMatrix, values, columnIndices, rowPointers);
    clock_t end = clock();
    // time diff in nanoseconds
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC) * 1000000000;
    cout << "exec_duration_nanosec:" << fixed << time_taken << setprecision(9)<< endl;

    // write values to output file
    for(int i = 0; i < values.size(); i++){
        outputFile << values[i] << " ";
    }
    outputFile << endl;
    for (int i = 0; i < columnIndices.size(); i++){
        outputFile << columnIndices[i] << " ";
    }
    outputFile << endl;
    for (int i = 0; i < rowPointers.size(); i++){
        outputFile << rowPointers[i] << " ";
    }
    outputFile << endl;
    
    inputFile.close();
    outputFile.close();
    return 0;
}



int main(int argc, char** argv) {
    string problem1InputPath = argv[1];
    string problem1OutputPath = argv[2];
   
    // Calling user code for Problem 1
    int p1Ret, p2aRet,p2bRet,p2cRet, p3Ret;

    p1Ret = problem1(problem1InputPath, problem1OutputPath);
    if(p1Ret != 0){

        cout << "Error in problem 1" << endl;
    }
   
}