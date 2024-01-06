// https://leetcode.com/problems/maximum-profit-in-job-scheduling/
//T.C : O((n^2)*logn)
//S.C : O(n)

class Solution {
public:
    int memo[50001];
    int n;
     int getNextIndex(vector<vector<int>>& array, int l, int currentJobEnd) {
        int r = n-1;
        
        int result = n+1;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(array[mid][0] >= currentJobEnd) { //we can take this task
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return result;
    }
    int solve(vector<vector<int>>&arr, int i){
        if(i>=n){
            return 0;
        }
        if(memo[i] != -1)
            return memo[i];

        int next  = getNextIndex(arr, i+1, arr[i][1]);
        
        int taken = arr[i][2] + solve(arr, next);
        int notTaken = solve(arr, i+1);
        
        return memo[i]=max(taken,notTaken);
    }
   
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        memset(memo, -1, sizeof(memo));
        n=startTime.size();
        vector<vector<int>> arr(n, vector<int>(3, 0)); //{s, e, p}
        
        for(int i = 0; i<n; i++) {
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }

        auto comp = [&](auto& vec1, auto& vec2) {
              return vec1[0] <= vec2[0];
        };
        
        //sort according to starting time
        sort(arr.begin(), arr.end(), comp);

        return solve(arr,0);
    }
};

