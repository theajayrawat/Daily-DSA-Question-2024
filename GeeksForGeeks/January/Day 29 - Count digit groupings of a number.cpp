// https://www.geeksforgeeks.org/problems/count-digit-groupings-of-a-number1520/1
// T.C : O(N^3)
// S.C : O(N^2)

class Solution{
	public:
	int n;
	
	int t[101][10001];
	
	int solve(int idx, int prev_sum, string &str) {
	    if(idx >= n) {
	        return 1;
	    }
	    
	    if(t[idx][prev_sum] != -1) {
	        return t[idx][prev_sum];
	    }
	    
	    int result   = 0;
	    int curr_sum = 0;
	    for(int i = idx; i < n; i++) {
	        curr_sum += (str[i]-'0');
	        if(prev_sum <= curr_sum) {
	            result += solve(i+1, curr_sum, str);
	        }
	    }
	    
	    
	    return t[idx][prev_sum] = result;
	}
	
	int TotalCount(string str) {
	    n = str.length();
	    memset(t, -1, sizeof(t));
	    return solve(0, 0, str);
	}
};
