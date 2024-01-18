// https://www.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/1
// TC: O(N!)
// SC: O(N)

class Solution {
  public:
    void recurPermute(int index, vector < int > & nums, vector < vector < int >> & ans) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int>st;
        for (int i = index; i < nums.size(); i++) {
            if(st.find(nums[i])==st.end()){
                swap(nums[index], nums[i]);
                recurPermute(index + 1, nums, ans);
                swap(nums[index], nums[i]);
            }
            st.insert(nums[i]); 
      }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        sort(arr.begin(),arr.end());
         vector < vector < int >> ans;
        recurPermute(0, arr, ans);
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};



