// https://www.geeksforgeeks.org/problems/additive-sequence/1
// TC: O(N^3)
// SC: O(N)

class Solution {
  public:
    bool isAdditiveSequence(string s) {

    int n = s.size();

    int num1 = 0;
    for (int i = 0; i < n / 2; i++) {
        num1 = num1 * 10 + (s[i] - '0');

        int num2 = 0;
        for (int j = i + 1; j < n - 1; j++) {
            num2 = num2 * 10 + (s[j] - '0');
            int first = num1, sec = num2;

            int num3 = 0;
            
            int k = j + 1;
            while (k < n) {
                num3 = num3 * 10 + (s[k] - '0');
                if (num3 == first+sec) {
                    first = sec;
                    sec = num3;
                    num3 = 0;
                }

                k++;
            }

            if (k == n && num3 == 0)
                return true;
        }
    }

    return false;
        
    }
};



