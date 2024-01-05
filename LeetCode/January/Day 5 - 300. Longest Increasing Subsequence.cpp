// https://leetcode.com/problems/longest-increasing-subsequence/
// TC: O(N*N)
// SC: O(N*N)

class Solution {
public:
    int solve(vector<int>& nums, vector<vector<int>>&dp, int index, int prevIndex){
        if(index==nums.size()){
            return 0;
        }
        if(dp[index][prevIndex+1]!=-1)
            return dp[index][prevIndex+1];
        
        int take=0, notTake=0;
        if(prevIndex==-1 || nums[index]>nums[prevIndex]){
            take=1+solve(nums, dp, index+1,index);
        }
        notTake=solve(nums,dp,index+1,prevIndex);

        return dp[index][prevIndex+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(nums,dp,0,-1);
    }
};
