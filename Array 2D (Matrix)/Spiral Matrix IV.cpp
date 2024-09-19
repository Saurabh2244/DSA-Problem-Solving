Problem ==> You are given two integers m and n, which represent the dimensions of a matrix.

          You are also given the head of a linked list of integers.

         Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), 
         starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.

         Return the generated matrix.

=============================================================================================================================
Solution:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int row, int col, ListNode* head) {
        
        vector<vector<int>> matrix(row,vector<int>(col,-1));

        int startRow=0;
        int startCol=0;

        int endRow=row-1;
        int endCol=col-1;

        ListNode* curr=head;

        while(curr!=NULL){
            //left to right
            for(int i=startCol;i<=endCol && curr!=NULL ; i++){
                matrix[startRow][i]=curr->val;
                curr=curr->next;
            }
            startRow++;

            //top to bottom
            for(int i=startRow;i<=endRow && curr!=NULL;i++){
                matrix[i][endCol]=curr->val;
                curr=curr->next;
            }
            endCol--;

            //right to left
            for(int i=endCol;i>=startCol && curr!=NULL;i--){
                matrix[endRow][i]=curr->val;
                curr=curr->next;
            }
            endRow--;

            //bottom to top
            for(int i=endRow;i>=startRow && curr!=NULL;i--){
                matrix[i][startCol]=curr->val;
                curr=curr->next;
            }
            startCol++;
        }

        return matrix;
    }
};
