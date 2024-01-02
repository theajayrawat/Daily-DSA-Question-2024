// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>mp;
        int row=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            row=max(row,mp[nums[i]]);
        }

        vector<vector<int>>ans(row,vector<int>());
        for(auto &i:mp){
            int freq=i.second;
            int val=i.first;
            while(freq){
                freq--;
                ans[freq].push_back(val);
            }
        }

        return ans;
    }
};