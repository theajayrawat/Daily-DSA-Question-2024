// https://www.geeksforgeeks.org/problems/maximum-sum-of-hour-glass3842/1
// TC: O(N^2)
// SC: O(N^2)

class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        // code here
        if(n<3 || m<3){
            return -1;
        }
        int mx=-1;
        for(int i=1;i<n-1;i++){
            int r=i;
            for(int j=1;j<m-1;j++){
                int c=j;
                int sm=0;
                sm=sm+mat[r-1][c]+mat[r+1][c]+mat[r-1][c-1]+mat[r-1][c+1]+mat[r+1][c-1]+mat[r+1][c+1]+mat[r][c];
                mx=max(mx,sm);
            }
        }
        return mx;
    }
};



