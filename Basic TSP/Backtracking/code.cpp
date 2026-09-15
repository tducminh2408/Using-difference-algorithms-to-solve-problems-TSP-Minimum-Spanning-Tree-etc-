#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
vector<vector<int>> C; 
vector<bool> visited;  
int minCost = INT_MAX; 

// Hàm Quay lui (Backtracking)
// u: thành phố hiện tại (Current city)
// count: số lượng thành phố đã ghé thăm (Number of cities visited)
// currentCost: tổng chi phí đã đi tính đến u (Total cost of the path)
void backtrack(int u, int count, int currentCost) {
    if (currentCost >= minCost) {
        return;
    }

    if (count == n) {
        int totalCost = currentCost + C[u][0];
        minCost = min(minCost, totalCost);
        return;
    }

    for (int v = 0; v < n; ++v) {
        if (!visited[v]) {
            visited[v] = true;
            backtrack(v, count + 1, currentCost + C[u][v]);
            visited[v] = false; 
        }
    }
}

int main() {

    if (!(cin >> n)) return 0;

    C.assign(n, vector<int>(n));
    visited.assign(n, false);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> C[i][j];
        }
    }

    visited[0] = true;
    backtrack(0, 1, 0);

    cout << minCost << "\n";

    return 0;
}