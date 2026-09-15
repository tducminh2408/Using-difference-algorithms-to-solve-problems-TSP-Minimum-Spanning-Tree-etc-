#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = 1e9; // Giá trị đại diện cho vô cực
int n;
vector<vector<int>> C;
vector<vector<int>> memo;

// Hàm DP tính chi phí nhỏ nhất
// mask: trạng thái các thành phố đã đi qua (dưới dạng chuỗi bit)
// u: thành phố hiện tại đang đứng
int tsp(int mask, int u) {
    // Nếu tất cả n thành phố đều đã đi qua (tất cả các bit từ 0 đến n-1 đều là 1)
    if (mask == (1 << n) - 1) {
        return C[u][0]; // Quay về thành phố xuất phát (0)
    }

    // Nếu trạng thái này đã được tính trước đó
    if (memo[mask][u] != -1) {
        return memo[mask][u];
    }

    int ans = INF;

    // Thử đi đến thành phố v tiếp theo
    for (int v = 0; v < n; ++v) {
        // Nếu thành phố v chưa được ghé thăm (bit thứ v trong mask là 0)
        if (!(mask & (1 << v))) {
            int newCost = C[u][v] + tsp(mask | (1 << v), v);
            ans = min(ans, newCost);
        }
    }

    // Lưu kết quả vào bảng quy hoạch động và trả về
    return memo[mask][u] = ans;
}

int main() {
    // Tối ưu I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return 0;

    C.assign(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> C[i][j];
        }
    }

    // Khoảng không gian trạng thái: (2^n) hàng x n cột
    memo.assign(1 << n, vector<int>(n, -1));

    // Xuất phát từ thành phố 0, mask ban đầu là (1 << 0) tức là bit 0 được bật
    int minCost = tsp(1, 0);

    cout << minCost << "\n";

    return 0;
}