#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        function<bool(int, int)> dfs = [&](int x, int y) -> bool {
            if (x == m - 1 && y == n - 1) {
                return true;
            }
            grid[x][y] = 0;
            return x + 1 < m && grid[x + 1][y] && dfs(x + 1, y) || y + 1 < n && grid[x][y + 1] && dfs(x, y + 1);
        };
        return !dfs(0, 0) || !dfs(0, 0);
    }
};