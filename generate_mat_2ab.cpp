#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>

using namespace std;

// Generate a dense square matrix of size n with random integers
// The first row has only 1 element representing the size of matrix
// The elements of the matrix are represented row-wise
// and are separated by a space
// Store the resultant matrix generated in a txt file
void generateMatrix(int n){
    ofstream myfile;
    myfile.open ("mat_2a_9in.txt");
    myfile << n << endl; // Store the size of the matrix on the first line
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            myfile << rand() % 100 << " ";
        }
        myfile << endl; // Add a newline character to separate rows
    }
    myfile.close();
}
//  Generate a dense matrix with random integers
// the matrix is used as a test set for block matrix multiplication
// the first row has the size of the square matrix and the block size used for multiplication
//  block size is less than half the size of matrix, the first row has size of square matrix and block size
// seperated by a space
// and the rows below it represnt the dense matrix row wise
// Store the resultant matrix generated in a txt file
void generatedenseMatrix(int n, int blockSize){
    ofstream myfile;
    myfile.open ("mat_2b_10in.txt");
    myfile << n << " " << blockSize << endl; // Store the size of the matrix and block size on the first line
    srand(time(0)); //seed random number generator
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            myfile << rand() % 1000 << " "; //generate random numbers between 0-99
        }
        myfile << endl;
    }   
    myfile.close();
}


int main(){
  
    generateMatrix(10000);
    generatedenseMatrix(10000, 500);

    return 0;
}
