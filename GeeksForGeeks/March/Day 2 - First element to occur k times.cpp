// https://www.geeksforgeeks.org/problems/first-element-to-occur-k-times5150/1
// TC: O(N)
// SC: O(N)

class Solution{
    public:
    int firstElementKTime(int n, int k, int a[])
    {
          unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            if(++m[a[i]] >=k) return a[i];
        }
        return -1;
    }
};