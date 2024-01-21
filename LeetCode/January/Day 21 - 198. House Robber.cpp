// https://leetcode.com/problems/house-robber/
// TC: O(N)
// SC: O(N*N)

class Solution {
public:
    int dp[101][102];
    int solve(vector<int>& nums, int i, int prev){
        if(i>=nums.size()){
            return 0;
        }
        
        if(dp[i][prev+1]!=-1)
            return dp[i][prev+1];
        int take=0,notTake=0;
        if(prev==-1 || i>=prev+2){
            take=nums[i]+solve(nums,i+1,i);
        }

        notTake=solve(nums,i+1,prev);

        return dp[i][prev+1]=max(take,notTake);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,-1);
    }
};
