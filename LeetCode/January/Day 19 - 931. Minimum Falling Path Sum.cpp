// https://leetcode.com/problems/climbing-stairs/
// TC: O(N*M)
// SC: O(N*M)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Create a DP table to store the minimum falling path sum for each position
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

        // Initialize the DP table with the values in the first row
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Iterate through the matrix to fill the DP table
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = j - 1; k <= j + 1; k++) {
                    if (k >= 0 && k < n) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + matrix[i][j]);
                    }
                }
            }
        }

        // Find the minimum falling path sum in the last row of the DP table
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[m - 1][j]);
        }

        return ans;
    }
};