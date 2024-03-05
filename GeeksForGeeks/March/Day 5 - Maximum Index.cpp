// https://www.geeksforgeeks.org/problems/maximum-index-1587115620/1
// TC: O(NlogN)
// SC: O(N)

class Solution{
    public:
    int maxIndexDiff(int a[], int n) { 
        vector<pair<int  , int>> ar(n) ;
        for(int i = 0 ; i< n ; i++){
            ar[i] = {a[i],i} ;
        }
        sort(ar.begin() , ar.end()) ;
        int ans = 0 , i = ar[0].second ;
        for(int j = 0 ; j< n ; j++){
            i = min(ar[j].second , i) ;
            ans = max(ar[j].second - i , ans) ;
        }
        return ans ;
    }
};
