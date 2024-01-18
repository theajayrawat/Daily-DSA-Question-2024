// https://www.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1
// TC: O(N)
// SC: O(N)

class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	   unordered_map<int,int>mp;
	   int sum=0;
	   int ans=0;
	   for(int i=0;i<n;i++){
	       sum+=arr[i];
	       int rem=sum%k;
	       if(rem<0) 
	            rem +=k;
	       if(rem == 0) 
	            ans = i+1;
	       else{
	           if(mp.find(rem)!=mp.end())
	                ans=max(ans,i-mp[rem]);
	           else
	                mp[rem]=i;
	       }
	       
	   }
	   return ans;
	}
};