// https://leetcode.com/problems/partition-array-for-maximum-sum/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    vector<int> dp;
    int solve(vector<int> &arr, int k, int ind){
        if(ind >= arr.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        int  mx = 0, ans = 0;
        for(int i=ind; i<min(ind+k, n); i++){
            mx = max(mx, arr[i]);
            ans = max(ans, (i - ind + 1)*mx + solve(arr, k, i+1));
        }
       
        return  dp[ind] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.resize(arr.size(), -1);
        return solve(arr, k, 0);
    }
};