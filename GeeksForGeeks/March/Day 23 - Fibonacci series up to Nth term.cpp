// https://www.geeksforgeeks.org/problems/fibonacci-series-up-to-nth-term/1
// TC: O(N)
// SC: O(N)

class Solution {
  public:
    vector<int> Series(int n) {
        // Code here
        const int MOD = 1e9 + 7;
    vector<int> fib(n + 1);
    
    if (n >= 1)
        fib[1] = 1;

    for (int i = 2; i <= n; ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }
    
    return fib;
    }
};