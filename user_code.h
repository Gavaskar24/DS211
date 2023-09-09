// A function to convert a dense matrix to a sparse matrix
//  Input: denseMatrix - a 2D array of integers
//  Output: values - a 1D array of integers
//         columnIndices - a 1D array of integers
//          rowPointers - a 1D array of integers
//         (see the assignment description for details)

denseToSparse(denseMatrix, values, columnIndices, rowPointers){
    int n = denseMatrix.size();
    int m = denseMatrix[0].size();
    int count = 0;
    for(int i = 0; i < n; i++){
        rowPointers.push_back(count);
        for(int j = 0; j < m; j++){
            if(denseMatrix[i][j] != 0){
                values.push_back(denseMatrix[i][j]);
                columnIndices.push_back(j);
                count++;
            }
        }
    }
    rowPointers.push_back(count);
    
    
}