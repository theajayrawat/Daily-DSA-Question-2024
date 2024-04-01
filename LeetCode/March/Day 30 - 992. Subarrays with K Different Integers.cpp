// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindowAtMost(nums, k) - slidingWindowAtMost(nums, k - 1);
    }
    int slidingWindowAtMost(vector<int>& nums, int k) {
        int ans = 0, start = 0;
        unordered_map<int, int> frequency;
        
        for (int end = 0; end < nums.size(); end++) {
            frequency[nums[end]]++;
            while (frequency.size() > k) {
                frequency[nums[start]]--;
                if (frequency[nums[start]] == 0) 
                    frequency.erase(nums[start]);
                start++;
            }
            ans += (end - start + 1);
        }
        
        return ans;
    }
};