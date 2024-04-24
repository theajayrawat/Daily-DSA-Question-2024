// https://leetcode.com/problems/n-th-tribonacci-number/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        return help(n,dp);
    }
    int help(int n,vector<int>&dp){
        if(dp[n]!=-1)return dp[n];
        if(n==0)return dp[n]=0;
        if(n==1||n==2)return dp[n]=1;
        return dp[n]=help(n-3,dp)+help(n-1,dp)+help(n-2,dp);
    }
};

