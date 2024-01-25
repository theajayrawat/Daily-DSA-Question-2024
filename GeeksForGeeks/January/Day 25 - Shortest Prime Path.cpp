// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
// T.C : O(n*log(log(n)))
// S.C : O(n)

class Solution {
public:
    vector<bool> findPrime() {
        vector<bool> prime(10001, true);

        for (int p = 2; p * p <= 10000; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= 10000; i += p)
                    prime[i] = false;
            }
        }

        return prime;
    }

    int solve(int num1, int num2) {
        // Add boundary checks here if needed

        if (num1 == num2)
            return 0;

        vector<bool> isPrime = findPrime();
        vector<bool> vis(10001, false);

        vis[num1] = true;
        queue<int> q;
        q.push(num1);
        int ans = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int p = q.front();
                q.pop();
                if (p == num2)
                    return ans;  // Break if destination is reached

                string nxt = to_string(p);
                for (int i = 0; i < 4; i++) {
                    for (char c = '0'; c <= '9'; c++) {
                        if (c == nxt[i] || (i == 0 && c == '0'))
                            continue;
                        string next = nxt;
                        next[i] = c;
                        int t = stoi(next);
                        if (!vis[t] && isPrime[t]) {
                            q.push(t);
                            vis[t] = true;
                        }
                    }
                }
            }
            ans++;
        }

        return -1;  // This line should not be reached if a valid path is found
    }
};