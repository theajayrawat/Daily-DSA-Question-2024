// https://www.geeksforgeeks.org/problems/possible-paths--141628/1
// TC: O(ElogE + QlogE) "E is edge & Q is quey"
// SC: O(N)

class Solution {
private:
    int ans;
    vector<int> parent;
    vector<int> size;

    // Find function with path compression
    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    // Union function with union by size
    int Union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (size[rootA] < size[rootB]) {
            ans += size[rootA] * size[rootB];
            parent[rootA] = rootB;
            size[rootB] += size[rootA];
        } else if (size[rootA] > size[rootB]) {
            ans += size[rootA] * size[rootB];
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        } else {
            ans += size[rootA] * size[rootB];
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        }

        return ans;
    }

public:
    vector<int> maximumWeight(int n, vector<vector<int>>& edges, int q, vector<int>& queries) {
        ans = 0;
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        iota(parent.begin(), parent.end(), 0); // Filling parent with 0, 1, 2, ...

        vector<int> res;
        map<int, int> mp; // Automatically sorts by the first element (key)

        // Sorting edges based on their weights
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        for (auto& edge : edges) {
            // Storing the max weight that can be obtained by using edges <= current edge's weight
            mp[edge[2]] = Union(edge[0], edge[1]);
        }

        for (auto& query : queries) {
            int maxWeight = 0;
            // Using lower_bound to find the first element not less than query
            auto it = mp.upper_bound(query);
            if (it != mp.begin()) {
                --it; // Now it points to the largest element <= query
                maxWeight = it->second;
            }
            res.push_back(maxWeight);
        }
        return res;
    }
};

