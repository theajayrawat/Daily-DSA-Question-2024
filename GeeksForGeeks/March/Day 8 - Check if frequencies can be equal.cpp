// https://www.geeksforgeeks.org/problems/check-frequencies4211/1
// TC: O(NlogN)
// SC: O(1)

class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    int n=s.size();
       unordered_map<char,int> mp;
       unordered_map<int,int> fremp;
       for(int i=0; i<n; i++) mp[s[i]]++;
       for(auto it: mp){
           fremp[it.second]++;
       }
       if(fremp.size()>2) return false;
       if(fremp.size()==1) return true;
       vector<pair<int,int>> arr;
       for(auto it: fremp){
           arr.push_back({it.first,it.second});
       }
       
       if((arr[0].first==1 && arr[0].second==1) || (arr[1].first==1 && arr[1].second==1)) return true;// edge case
       
       int ct=INT_MAX;
       if(arr[0].first>arr[1].first){
           int r=(arr[0].first-arr[1].first)*arr[0].second;
           ct=min(ct,r);
       }
       else{
           int r=(arr[1].first-arr[0].first)*arr[1].second;
           ct=min(ct,r);
       }
       if(ct>1) return false;
       return true;
	}
};