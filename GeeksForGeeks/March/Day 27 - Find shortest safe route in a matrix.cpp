// https://www.geeksforgeeks.org/problems/find-shortest-safe-route-in-a-matrix/1
// TC: O(r * c)
// SC: O(r * c)

class Solution
{
public:
    
    int dfs(int i, int j, vector<vector<int>> &mat){
        int n = mat.size(), m = mat[0].size();
        if(i<0 || j<0 || i>=n || j>=m || mat[i][j] == 2 || i-1 >= 0 && mat[i-1][j] == 0 ||
        i+1 < n && mat[i+1][j] == 0 || j-1 >= 0 && mat[i][j-1] == 0 || j+1 < m && mat[i][j+1] == 0){
            return 1e6;
        }
        if(j == m-1) return 1;
        mat[i][j] = 2;
        int left = dfs(i-1, j, mat);
        int right = dfs(i+1, j, mat);
        int up = dfs(i, j-1, mat);
        int down = dfs(i, j+1, mat);
        mat[i][j] = 1;
        return 1+min(min(left, right), min(up, down));
    }

    int findShortestPath(vector<vector<int>> &mat)
    {
        int ans = INT_MAX;
        for(int i=0; i<mat.size(); i++){
            if(mat[i][0])
                ans = min(ans, dfs(i, 0, mat));  
        }
        if(ans >= 1e6) return -1;
        return ans;
    }
};

