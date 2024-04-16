// https://www.geeksforgeeks.org/problems/minimize-the-difference/1
// TC: O(N)
// SC: O(N)

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        // code here
        vector<pair<int, int>> pre(n);
        pre[0] = {arr[0], arr[0]};
        for(int i = 1; i < n; ++i) {
            pre[i].first = min(pre[i - 1].first, arr[i]);
            pre[i].second = max(pre[i - 1].second, arr[i]);
        }
        
        vector<pair<int, int>> suff(n);
        suff[n - 1] = {arr[n - 1], arr[n - 1]};
        
        for(int i = n - 2; i >= 0; --i) {
            suff[i].first = min(suff[i + 1].first, arr[i]);
            suff[i].second = max(suff[i + 1].second, arr[i]);
        }
        
        int res = min(suff[k].second - suff[k].first, pre[n - k - 1].second - pre[n - k - 1].first);
        int i = 0, j = k + 1;
        while(j < n) {
            int mn = min(pre[i].first, suff[j].first);
            int mx = max(pre[i].second, suff[j].second);
            res = min(res, mx - mn);
            
            i++;
            j++;
        }
        
        return res;
    }
};

