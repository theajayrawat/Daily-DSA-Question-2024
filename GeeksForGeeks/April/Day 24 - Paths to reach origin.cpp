// https://www.geeksforgeeks.org/problems/paths-to-reach-origin3850/1
// TC: O(N^2)
// SC: O(N^2)

class Solution
{
public:
     int solve(int x,int y, vector<vector<int>>&dp){
        if(x<0 || y<0) return 0;
        if(x==0 && y==0) return 1;
        
        if(dp[x][y]!=-1) return dp[x][y];
        
        return dp[x][y]=(solve(x-1,y,dp) + solve(x,y-1,dp))%1000000007;
    }

public:
    int ways(int x, int y)
    {
        //code here.
      vector<vector<int>>dp(x+1,vector<int>(y+1,-1));
        return solve(x,y,dp)%1000000007;
    }
};