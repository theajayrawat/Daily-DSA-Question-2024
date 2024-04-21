// https://www.geeksforgeeks.org/problems/three-way-partitioning/1
// TC: O(N)
// SC: O(N)

class Solution {
public:
    bool solve(vector<vector<int>>& graph, int source, int destination, vector<int>& visited) {
        if (source == destination)
            return true;
        
        visited[source] = 1;
        
        for (auto& neighbor : graph[source]) {
            if (!visited[neighbor]) {
                if (solve(graph, neighbor, destination, visited))
                    return true; // If a path is found, return true
            }
        }
        return false; // No path found from source to destination
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> visited(n, 0);
        
        return solve(graph, source, destination, visited);
    }
};
