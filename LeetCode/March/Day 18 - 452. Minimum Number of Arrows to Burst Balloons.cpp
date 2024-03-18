// https://leetcode.com/problems/insert-interval/
// TC: O(NlogN)
// SC: O(1)

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int prev=points[0][1];
        int ans=1;
        for(int i=0;i<points.size();i++){
            if(prev<points[i][0]){
                prev=points[i][1];
                ans++;
            }
            else{
                prev=min(prev,points[i][1]);
            }
        }

        return ans;

    }
};