
void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here
    int row=matrix.size();
    int col=matrix[0].size();
    
    //Take transpose
    for(int i=0;i<row;i++){
        for(int j=i+1;j<col;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    
    //swap upper half with lower half
    for(int i=0;i<row/2;i++){
        for(int j=0;j<col;j++){
            swap(matrix[i][j],matrix[col-1-i][j]);
        }
    }
}
