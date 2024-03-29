// https://leetcode.com/problems/binary-subarrays-with-sum/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int, int>mp;
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==goal){
                ans++;
            }if(mp.find(sum-goal)!=mp.end()){
                ans+=mp[sum-goal];
               
            }
            mp[sum]++;
        }

        return ans;
    }
};