// https://leetcode.com/problems/contiguous-array/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(nums[i]==0)
                sum--;
            if(sum==0){
                ans=i+1;
            }else if(mp.find(sum)!=mp.end()){
                ans=max(ans,i-mp[sum]);
            }else{
                mp[sum]=i;
            }   
        }

        return ans;
    }
};