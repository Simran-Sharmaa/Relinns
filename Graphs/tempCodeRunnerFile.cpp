#include <bits/stdc++.h>
using namespace std;

// Recursive DFS function to find the minimum cost of visiting all cities starting from 'node'
int dfs(int node, vector<vector<int>> &cost, vector<bool> &vis, int n) {
    // Mark the current node as visited
    vis[node] = true;

    // Assign maximum value
    int mini = INT_MAX;

    // Explore all unvisited cities
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            // Calculate the cost of the new path and recursively explore it
            int newRes = cost[node][i] + dfs(i, cost, vis, n);
            mini = min(mini, newRes);
        }
    }

    // Backtrack - mark the current node as unvisited
    vis[node] = false;

    // All paths are visited, so return the last path
    if (mini == INT_MAX) {
        return cost[node][0];
    }

    return mini;
}

int main() {
    int n;
    // Declare a 2D vector to store the cost matrix for cities
    vector<vector<int>> graph(n, vector<int>(n, 0));

    // Get the number of cities from the user
    cout << "Enter the number of cities: ";
    cin >> n;

    // Get the cost matrix from the user
    cout << "Enter the cost matrix for the cities:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int source;
    // Get the source node from the user
    cout << "Enter the source node: ";
    cin >> source;

    // Initialize a boolean vector to keep track of visited nodes
    vector<bool> vis(n, false);

    // Call the DFS function and print the result
    cout << dfs(source, graph, vis, n);

    return 0;
}
