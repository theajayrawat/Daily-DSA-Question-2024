// https://leetcode.com/problems/trapping-rain-water/?
// TC: O(N)
// SC: O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        int i=0,j=n-1,rightMax=0,leftMax=0;
        while(i<=j){
            if (height[i] < height[j]){
                if (height[i] > leftMax){
                    leftMax = height[i];
                } 
                else ans += leftMax -height[i];
                i++;
            } 
            else {
                if (height[j] > rightMax )rightMax =height[j];
                else ans += rightMax - height[j];
                j--;
            }
        }
        return ans;
    }
};