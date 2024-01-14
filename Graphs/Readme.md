# Algorithm to solve the Traveling Salesman Problem (TSP) using a given list of cities and their respective distances.

## Functionality Explanation:

**DFS Function (dfs):**

The dfs function implements a Depth-First Search to find the minimum cost of visiting all cities starting from a given node.
It uses a recursive approach to explore all possible paths.

**Algorithm Steps (DFS):**

1. Mark the current node as visited (vis[node]=true).
1. Initialize a variable mini to store the maximum cost.
1. Iterate over all cities (i) that haven't been visited yet.
1. Calculate the cost of the new path (newRes) from the current city to an unvisited city and recursively explore it.
1. Update mini with the minimum cost encountered during exploration.
1. **Backtrack**: Mark the current node as unvisited (vis[node]=false).
1. All paths are visited:
1. If mini is still at its initial value (INT_MAX), it means all paths are visited. Return the cost of returning to the starting city (cost[node][0]).
1. Return the minimum cost (mini).

**Main Function (main):**
1. Declare a 2D vector graph to store the cost matrix for cities.
1. Get the number of cities (n) from the user.
1. Get the cost matrix from the user.
1. Initialize a boolean vector vis to keep track of visited nodes.
1. Call the dfs function with the provided inputs and print the result.

## How to execute
1. Compile the program.
1. Enter the number of cities (size of the graph).
1. Enter elements in the graph.

*Things to consider* 
1. The distance from same node will be 0.
1. The distance from one node to another will be same.For example- There is an edge from 0 to 1 the distance from 0 to 1 and from 1 to 0 should be idetical.