// https://leetcode.com/problems/count-elements-with-maximum-frequency/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        int maxi=0;
        for(auto &i:mp){
            maxi=max(maxi,i.second);
        }
        
        int ans=0;
        for(auto &i:mp){
            if(maxi==i.second)
                ans++;
        }
        
        return ans*maxi;
    }
};