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


int problem2a(string inputPath, string outputPath){
    vector<vector<int> > denseMatrix1;
    vector<vector<int> > denseMatrix2;
    vector<vector<int> > denseMatrixResult;
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
        denseMatrix1.push_back(temp);
    }
    // read dense matrix 2 from input file
    for(int i = 0; i < N; i++){
        vector<int> temp;
        for(int j = 0; j < N; j++){
            int x;
            inputFile >> x;
            temp.push_back(x);
        }
        denseMatrix2.push_back(temp);
    }

    // initialize resultant matrix
    denseMatrixResult.resize(N, vector<int>(N,0));


    // measure time taken in nanoseconds
    cout<< "input_size_n:" << denseMatrix1.size() << endl;
    clock_t start = clock();
    
    denseMatrixMultiplication(denseMatrix1, denseMatrix2, N, denseMatrixResult);
    clock_t end = clock();
    // time diff in nanoseconds
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC) * 1000000000;
    cout << "exec_duration_nanosec:" << fixed << time_taken << setprecision(9)<< endl;


    // write values to output file
    for(int i = 0; i < denseMatrixResult.size(); i++){
        for(int j = 0; j < denseMatrixResult[i].size(); j++){
            outputFile << denseMatrixResult[i][j] << " ";
        }
        outputFile << endl;
    }
    
    return 0;
}

int problem2b(string inputPath, string outputPath){
    vector<vector<int> > denseMatrix1;
    vector<vector<int> > denseMatrix2;
    vector<vector<int> > denseMatrixResult;
    ifstream inputFile(inputPath);
    ofstream outputFile(outputPath);
    int N;
    int B;
    inputFile >>N>>B;
    // read dense matrix 1 from input file
    for(int i = 0; i < N; i++){
        vector<int> temp;
        for(int j = 0; j < N; j++){
            int x;
            inputFile >> x;
            temp.push_back(x);
        }
        denseMatrix1.push_back(temp);
    }

    // read dense matrix 2 from input file
    for(int i = 0; i < N; i++){
        vector<int> temp;
        for(int j = 0; j < N; j++){
            int x;
            inputFile >> x;
            temp.push_back(x);
        }
        denseMatrix2.push_back(temp);
    }

    // initialize resultant matrix
    denseMatrixResult.resize(N, vector<int>(N,0));

    cout<< "input_size_n:" << denseMatrix1.size() << endl;
    clock_t start = clock();

    blockMatrixMultiplication(denseMatrix1, denseMatrix2, N, B, denseMatrixResult);
    clock_t end = clock();
    // time diff in nanoseconds
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC) * 1000000000;
    cout << "exec_duration_nanosec:" << fixed << time_taken << setprecision(9)<< endl;
    for (int i = 0; i < denseMatrixResult.size(); i++){
        for (int j = 0; j < denseMatrixResult[i].size(); j++){
            outputFile << denseMatrixResult[i][j] << " ";
        }
        outputFile << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}

int problem2c(string inputPath, string outputPath){

    ifstream inputFile(inputPath);
    ofstream outputFile(outputPath);
    int N;
    vector<vector<int> > dataFromFile;
    while (inputFile){
        vector<int> temp;

        // NOTE::: Line can contain at max N*N elements
        string line;
        int x;
        getline(inputFile, line);
        stringstream ss(line);
        while (ss >> x){
            temp.push_back(x);
        }
        if (temp.size() == 0){
            break;
        }
        dataFromFile.push_back(temp);
    }
    
    N = dataFromFile[0][0];
    vector<int> values1 = dataFromFile[1];
    vector<int> columnIndices1 = dataFromFile[2];
    vector<int> rowPointers1 = dataFromFile[3];
    vector<int> values2 = dataFromFile[4];
    vector<int> columnIndices2 = dataFromFile[5];
    vector<int> rowPointers2 = dataFromFile[6];
    vector<int> valuesResult;
    vector<int> columnIndicesResult;
    vector<int> rowPointersResult;


    cout<< "input_size_n:" << N << endl;
    clock_t start = clock();
    sparseMatrixMultiplication(values1, columnIndices1, rowPointers1, values2, columnIndices2, rowPointers2, N, valuesResult, columnIndicesResult, rowPointersResult);
    clock_t end = clock();
    // time diff in nanoseconds
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC) * 1000000000;
    cout << "exec_duration_nanosec:" << fixed << time_taken << setprecision(9)<< endl;
    // write values to output file

    for(int i = 0; i < valuesResult.size(); i++){
        outputFile << valuesResult[i] << " ";
    }
    outputFile << endl;
    for (int i = 0; i < columnIndicesResult.size(); i++){
        outputFile << columnIndicesResult[i] << " ";
    }
    outputFile << endl;
    for (int i = 0; i < rowPointersResult.size(); i++){
        outputFile << rowPointersResult[i] << " ";
    }
    outputFile << endl;

    inputFile.close();
    outputFile.close();
    return 0;
}

int problem3(string inputPath, string outputPath){
   
    vector<vector<int> > adjMatrix;
    map<vector<int>, int> outputMap;
    vector<vector<int> > outputVec;
    ifstream inputFile(inputPath);
    ofstream outputFile(outputPath);

    int numVertices;
    inputFile >> numVertices;
    for (int i = 0; i < numVertices; i++){
        std::vector<int> temp;
        for (int j = 0; j < numVertices; j++){
            int val;
            inputFile >> val;
            temp.push_back(val);
        }
        adjMatrix.push_back(temp);
    }

    cout<< "input_size_n:" << numVertices << endl;
    clock_t start = clock();
    findTrianglesAsMap(adjMatrix, numVertices,outputMap);
    clock_t end = clock();
    // time diff in nanoseconds
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC) * 1000000000;
    cout << "exec_duration_nanosec:" << fixed << time_taken << setprecision(9)<< endl;
    findTrianglesAsVec(adjMatrix, numVertices, outputVec);
    double time_taken2 = double(end - start) / double(CLOCKS_PER_SEC) * 1000000000;
    cout << "exec_duration_nanosec:" << fixed << time_taken2 << setprecision(9)<< endl;

    for (auto it = outputMap.begin(); it != outputMap.end(); it++){
        outputFile << it->first[0] << " " << it->first[1] << " " << it->first[2] << " " << it->second << endl;
    }
    for (int i = 0; i < outputVec.size(); i++){
        outputFile << outputVec[i][0] << " " << outputVec[i][1] << " " << outputVec[i][2] << " " << outputVec[i][3] << endl;
    }
    outputFile << endl;

    
    inputFile.close();
    outputFile.close();

    return 0;
}



int main(int argc, char** argv) {
    string problem1InputPath = argv[1];
    string problem1OutputPath = argv[2];
    string problem2aInputPath = argv[3];
    string problem2aOutputPath = argv[4];
    string problem2bInputPath = argv[5];
    string problem2bOutputPath = argv[6];
    string problem2cInputPath = argv[7];
    string problem2cOutputPath = argv[8];
    string problem3InputPath = argv[9];
    string problem3OutputPath = argv[10];
   

    // Calling user code for Problem 1
    int p1Ret, p2aRet,p2bRet,p2cRet, p3Ret;

    cout << "Problem 1" << endl;
    p1Ret = problem1(problem1InputPath, problem1OutputPath);
    if(p1Ret != 0){

        cout << "Error in problem 1" << endl;
    }
    cout << "----------------------------" << endl;

    cout << "Problem 2a" << endl;
    p2aRet = problem2a(problem2aInputPath, problem2aOutputPath);
    if(p2aRet != 0){
      cout << "Error in problem 2a" << endl;
    }
    cout << "----------------------------" << endl;

    cout << "Problem 2b" << endl;
    p2bRet = problem2b(problem2bInputPath, problem2bOutputPath);
    if(p2bRet != 0){
      cout << "Error in problem 2b" << endl;
    }
    cout << "----------------------------" << endl;

    cout << "Problem 2c" << endl;
    p2cRet = problem2c(problem2cInputPath, problem2cOutputPath);
    if(p2cRet != 0){
      cout << "Error in problem 2c" << endl;
    }
    cout << "----------------------------" << endl;

    cout << "Problem 3" << endl;
    p3Ret = problem3(problem3InputPath, problem3OutputPath);
    if(p3Ret != 0){
      cout << "Error in problem 3" << endl;
    }
    cout << "----------------------------" << endl;
}
