/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 *
 * https://leetcode-cn.com/problems/max-area-of-island/description/
 *
 * algorithms
 * Medium (53.13%)
 * Total Accepted:    4.3K
 * Total Submissions: 8.1K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]'
 *
 * 给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地)
 * 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。
 * 
 * 找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)
 * 
 * 示例 1:
 * 
 * 
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,1,1,0,1,0,0,0,0,0,0,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,0,1,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,1,1,0,0],
 * ⁠[0,0,0,0,0,0,0,0,0,0,1,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * 
 * 
 * 对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。
 * 
 * 示例 2:
 * 
 * 
 * [[0,0,0,0,0,0,0,0]]
 * 
 * 对于上面这个给定的矩阵, 返回 0。
 * 
 * 注意: 给定的矩阵grid 的长度和宽度都不超过 50。
 * 
 */
class Solution {
public:
	int dfs(vector<vector<int>>& grid, int x0, int y0) {
		int n, m, sum = 1;
		n = grid.size();
		m = grid[0].size();

		grid[x0][y0] = 0;
		int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

		for (int i = 0; i < 4; i++) {
			int x = x0 + dir[i][0];
			int y = y0 + dir[i][1];	
			if (x >= 0 && x < n&&y >= 0 && y < m&&grid[x][y] == 1)	sum += dfs(grid, x, y);
		}
		return sum;
	}

    int maxAreaOfIsland(vector<vector<int>>& grid) {
		int res = 0, n, m;
		n = grid.size();
		m = grid[0].size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1)	res = max(dfs(grid, i, j), res);
			}
		}
		return res;
    }
};

