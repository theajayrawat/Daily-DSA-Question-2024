// https://leetcode.com/problems/island-perimeter/
// TC: O(N^2)
// SC: O(1)

class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
            return 1;
        else
            return 0;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m =  grid[0].size();
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans = ans + solve(grid,i+1,j) + solve(grid,i,j+1) + solve(grid,i-1,j) + solve(grid,i,j-1);
                }
            }
        }

        return ans;
    }
};
