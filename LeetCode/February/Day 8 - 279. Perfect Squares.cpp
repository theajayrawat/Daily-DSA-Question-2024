// https://leetcode.com/problems/perfect-squares/
// TC: O(sqrt(n)^n)
// SC: O(n)

class Solution {
public:
    int dp[10001];
    int solve(int n,vector<int>&sq ){
        if(n==0)
            return 0;
        if(n<0)
            return -1;
        if(dp[n]!=-1)
            return dp[n];

        int ans=INT_MAX;
        for(int i=0;i<sq.size();i++){
            if(solve(n-sq[i],sq)!=-1){
                ans=min(ans,1+solve(n-sq[i],sq));
            }
        }

        return dp[n]=ans;
    }
    int numSquares(int n) {
        vector<int>sq;
        memset(dp, -1, sizeof(dp)); 
        for(int i=n;i>=1;i--){
            int no=sqrt(i);
            if(no*no==i)
                sq.push_back(i);
        }

        return solve(n,sq);
        
    }
};