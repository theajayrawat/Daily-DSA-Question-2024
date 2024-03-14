// https://www.geeksforgeeks.org/problems/print-matrix-in-diagonal-pattern/1
// TC: O(N*M)
// SC: O(N*M)

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
        int n=mat.size();
        int m=mat[0].size();
        vector<int>ans(n*m,0);
        int row=0;
        int col=0;
        int k=0;
        bool up=true;
        while(row<n &&col<m){
            
            if(up==true){
                while(row>0 && col<m-1){
                ans[k++]=mat[row][col];
                row--;
                col++;
                }
                ans[k++]=mat[row][col];
                if(col==m-1) row++;
                else col++;
            }
            else {
                while(row<n-1 && col>0){
                    ans[k++]=mat[row][col];
                    row++;
                    col--;
                }
                ans[k++]=mat[row][col];
                if(row==n-1) col++;
                else row++;
            }
            up=!up;
        }
        return ans;
    }
};


