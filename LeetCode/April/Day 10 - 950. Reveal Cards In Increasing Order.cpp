// https://leetcode.com/problems/time-needed-to-buy-tickets/
// TC: O(NlogN)
// SC: O(N)

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        vector<int> res(deck.size(), 0);
        int i=0;
        bool skipped = true;
		
        //every time fill up half of empty space
        while(i<deck.size()) {
            for(int j=0;j<res.size();j++)
                if(res[j]==0){
                    if(skipped){
                    res[j] = deck[i++];
                    }
                    skipped = !skipped;
                }
        }
        return res;
    }
};