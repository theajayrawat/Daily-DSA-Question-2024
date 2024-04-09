// https://www.geeksforgeeks.org/problems/convert-to-strictly-increasing-array3351/1
// TC: O(N^2)
// SC: O(N)

class Solution {
  public:
    int min_operations(vector<int>& nums) {
       
       int res=1,n=nums.size();
       
       vector<int> dp(n,1);
       
       
       for(int i=1;i<nums.size();i++){
           for(int j=0;j<i;j++){
               
               if(nums[i]-nums[j]>=i-j){
                   dp[i]=max(dp[i],dp[j]+1);
                   res=max(res,dp[i]);
               }
                
           }
     }
       
       return n-res;
    }
};