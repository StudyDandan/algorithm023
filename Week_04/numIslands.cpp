#include <vector>

/*解法：
dfs：时间复杂度O（M*N），空间复杂度O（M*N）
BFS：时间复杂度O（M*N），空间复杂度Omin（M,N）*/

using namespace std;

void dfs(vector<vector<char>>& grid, int row, int col) {
    if (grid.size() <= row || row < 0
        || col >= grid[0].size() || col < 0) {
        return;
    }
    if (grid[row][col] != '1') return;

    grid[row][col] = '2';//这样就不用加visited了
    dfs(grid, row, col - 1);
    dfs(grid, row, col + 1);
    dfs(grid, row - 1, col);
    dfs(grid, row + 1, col);
}

//bfs方法
//int numIslands(vector<vector<char>>& grid) {
//    int numIsland = 0;
//    queue<std::pair<int, int>> record;
//    for (int row = 0; row < grid.size(); row++) {
//        for (int col = 0; col < grid[row].size(); col++) {
//            if (grid[row][col] == '1') {
//                numIsland++;
//                record.push(std::make_pair(row, col));
//                while (!record.empty()) {
//                    std::pair<int, int> pair = record.front();
//                    grid[pair.first][pair.second] = '2';
//                    record.pop();
//                    if (isIsland(grid, pair.first, pair.second + 1)) {
//                        record.push(std::make_pair(pair.first, pair.second + 1));
//                        grid[pair.first][pair.second + 1] = '2';
//                    }
//
//                    if (isIsland(grid, pair.first, pair.second - 1)) {
//                        record.push(std::make_pair(pair.first, pair.second - 1));
//                        grid[pair.first][pair.second - 1] = '2';
//                    }
//
//                    if (isIsland(grid, pair.first + 1, pair.second)) {
//                        record.push(std::make_pair(pair.first + 1, pair.second));
//                        grid[pair.first + 1][pair.second] = '2';
//                    }
//
//                    if (isIsland(grid, pair.first - 1, pair.second)) {
//                        record.push(std::make_pair(pair.first - 1, pair.second));
//                        grid[pair.first - 1][pair.second] = '2';
//                    }
//                }
//            }
//        }
//    }
//    return numIsland;
//}

int numIslands(vector<vector<char>>& grid) {
    int numIsland = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '1') {
                numIsland++;
                dfs(grid, i, j);
            }
        }
    }
    return numIsland;
}

void main() 
{
    vector<vector<char>> grid;
    grid.push_back({ '1', '1', '1', '1', '0' });
    grid.push_back({ '1', '1', '0', '1', '0' });
    grid.push_back({ '1', '1', '0', '0', '0' });
    grid.push_back({ '0', '0', '0', '0', '0' });
    numIslands(grid);
}