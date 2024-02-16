// https://leetcode.com/problems/rearrange-array-elements-by-sign/
// TC: O(NLogN)
// SC: O(1)

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum=nums[0]+nums[1];
        long long ans=sum;
        long long cnt=2;

        for(int i=2;i<nums.size();i++){
            if(sum>nums[i]){
                ans=sum+nums[i];
                cnt=i+1;
            }
            sum+=nums[i];
        }

        return cnt>=3 ? ans : -1;
    }
};