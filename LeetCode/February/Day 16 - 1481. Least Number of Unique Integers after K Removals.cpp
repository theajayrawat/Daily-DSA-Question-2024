// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
// TC: O(N)
// SC: O(N)

class Solution {
public:
  int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>mp;
        for(int i=0;i<arr.size();i++){
         mp[arr[i]]++;
        }

        vector<pair<int, int> > A; 
        for (auto& it : mp) { 
            A.push_back(make_pair(it.second,it.first)); 
        } 
        sort(A.begin(), A.end()); 

        int i=0;
        int n=A.size();
        while(i<n){
            cout<<A[i].first<<A[i].second<<" ";
            if(A[i].first<=k){
                k-=A[i].first;
            }else{
                break;
            }
            i++;
        }
        return n-i;
    }
};