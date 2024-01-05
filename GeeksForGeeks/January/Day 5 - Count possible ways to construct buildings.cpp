// https://www.geeksforgeeks.org/problems/count-possible-ways-to-construct-buildings5007/1
// TC: O(N)
// SC: O(1)

class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    int mod = 1e9+7;
        long a = 1, b = 2, c = 2;
        
        for (int i = 2; i <= N; i++) {
            c = (a + b) % mod;
            a = b;
            b = c;
        }
        
        return (c * c) % mod;
	}
};

