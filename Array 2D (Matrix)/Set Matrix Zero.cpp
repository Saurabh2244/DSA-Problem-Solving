// Brute Force==> Traverse matrix and if we find 0 then then make row and col in which that 0 lie as -1. Not 0 because
                   if we make zero then then next element of founded 0 is also 0 but in real sometimes in not. 
                   So, to avoid error mark as -1 instead of 0;

                   Then again traverse matrix and if we find -1 then make it as 0.

class Solution {
public:
    
    // mark row as -1
    void markRowZero(vector<vector<int>>&matrix,int row,int col){
        for(int i=0;i<row;i++){
            if(matrix[i][col]!=0){
                matrix[i][col]=-1;
            }
        }
    }

    // mark col as -1
    void markColZero(vector<vector<int>>&matrix,int row,int col){
        for(int i=0;i<col;i++){
            if(matrix[row][i]!=0){
                matrix[row][i]=-1;
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        
        //traverse matrix and find 0 and mark that row and col as -1
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    markRowZero(matrix,row,j);
                    markColZero(matrix,i,col);
                }
            }
        }

        //traverse matrix and if we found -1 then make it as 0
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==-1){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

==============================================================================================================================

// Better Solution==> In brute force, if we found 0 then we make whole row as 0. Again we found 0 then again we make it 0 but initially it is 0 
                      So, it takes time. To optimize this,

                      We create 2 array one is RowVis and other is colVis and if we found 0 then we mark rowVis and colVis as 1
                      if we have minimum 1 zero then our entire row will 0 and col is also become 0.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        
        //create visited array
        vector<int>rowVis(row,0);
        vector<int>colVis(col,0);
 
        // Traverse matrix and if we found 0 then mark it as visited
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    rowVis[i]=1;
                    colVis[j]=1;
                }
            }
        }
        
        //Again traverse matrix and we found any of row or col is contain 0 (i.e.visited) then mark that element as 0
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(rowVis[i]==1 || colVis[j]==1){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

==============================================================================================================================

// Optimal Solution==> Here we want to optimize so we can reduce space complexuty. Instead of creating 2 new array outside 
                       matrix we use first row and col for 2 arrays.

                       if(matrix[0][0]==0) ==> then colVis array i.e.first row is 0
                       if(col1==0)===> then rowVis array i.e.first col is 0

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();

        // vector<int>rowVis(row,0); // matrix[....][0]
        // vector<int>colVis(col,0); //matrix[0][....]

        int col1=matrix[0][0];

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;

                    if(j!=0){
                      matrix[0][j]=0;
                    }

                    else{
                        col1=0;
                    }
                    
                }
            }
        }

        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(matrix[i][j]!=0){
                    if(matrix[i][0]==0 || matrix[0][j]==0){
                        matrix[i][j]=0;
                    }
                }
            }
        }

        if(matrix[0][0]==0){
            for(int j=0;j<col;j++){
                matrix[0][j]=0;
            }
        }

        if(col1==0){
            for(int i=0;i<row;i++){
                matrix[i][0]=0;
            }
        }
    }
};
