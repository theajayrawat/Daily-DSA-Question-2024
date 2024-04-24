// https://www.geeksforgeeks.org/problems/row-with-minimum-number-of-1s5430/1
// TC: O(N^2)
// SC: O(1)

class Solution {
  public:
    int minRow(int n, int m, vector<vector<int>> a) {
        // code here
        int min=INT_MAX;
        int row=0;
        for(int i=0;i<n;i++){
            int cnt1=0;
            for(int j=0;j<m;j++){
                if(a[i][j]==1){
                    cnt1++;
                }
            }
            if(min>cnt1){
                min=cnt1;
                row=i+1;
            }
        }
        return row;
    }
};