#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<vector<int>> C;
vector<bool> visited;
vector<int> currentPath, bestPath;
int minCost = INT_MAX;

void backtrack(int u, int count, int currentCost) {
    if (currentCost >= minCost) return;

    if (count == n) {
        int totalCost = currentCost + C[u][0];
        if (totalCost < minCost) {
            minCost = totalCost;
            bestPath = currentPath;
            bestPath.push_back(0); // Quay về 0
        }
        return;
    }

    for (int v = 0; v < n; ++v) {
        if (!visited[v]) {
            visited[v] = true;
            currentPath.push_back(v);
            
            backtrack(v, count + 1, currentCost + C[u][v]);
            
            currentPath.pop_back();
            visited[v] = false;
        }
    }
}

int main() {
    cin >> n;
    C.assign(n, vector<int>(n));
    visited.assign(n, false);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> C[i][j];

    visited[0] = true;
    currentPath.push_back(0);
    
    backtrack(0, 1, 0);

    cout << "Min cost: " << minCost << "\nPath: ";
    for (int node : bestPath) cout << node << " ";
    cout << "\n";

    return 0;
}