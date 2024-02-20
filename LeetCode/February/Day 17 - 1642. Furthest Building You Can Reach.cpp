// https://leetcode.com/problems/furthest-building-you-can-reach/
// TC: O(NlogN)
// SC: O(N)

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> pq;
        int i;
        for (i = 0; i < n - 1; ++i) {
            int diff = heights[i + 1] - heights[i];
            if (diff > 0) {
                if (bricks>=diff) {
                    bricks-=diff;
                    pq.push(diff);
                } else if(ladders>0){
                    if (!pq.empty()) {
                        int max_bricks_past=pq.top();
                        if(max_bricks_past>diff){
                            bricks+=max_bricks_past;
                            bricks-=diff;
                            pq.pop();
                            pq.push(diff);
                        }
                    }
                    ladders--;
                }else {
                   break; 
                }
            }
        }
        return i;
    }
};
