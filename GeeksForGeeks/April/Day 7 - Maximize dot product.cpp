// https://www.geeksforgeeks.org/problems/maximize-dot-product2649/1
// TC: O(N^2)
// SC: O(N^2)

class Solution{		
	public:
	int maxDotProduct(int n, int m, int a[], int b[]) 
    { 
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int p = 1; p <= m; p++) {
            for(int k = p; k <= n; k++) {
                dp[p][k] = max(dp[p][k-1], dp[p-1][k-1] + a[k-1] * b[p-1]);
            }
        }
        return dp[m][n];
    } 
};