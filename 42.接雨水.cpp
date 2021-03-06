/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (41.25%)
 * Total Accepted:    8.9K
 * Total Submissions: 21.5K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢
 * Marcos 贡献此图。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出: 6
 * 
 */
class Solution {
public:
    int trap(vector<int>& height) {
		stack<int> st;
		int i = 0, res = 0, n = height.size();
		while (i < n) {
			if (st.empty() || height[i] <= height[st.top()]) {
				st.push(i++);
			}
			else {
				int t = st.top();
				st.pop();
				if (st.empty())	continue;
				res += (min(height[i], height[st.top()]) - height[t]) * (i - st.top() - 1);
			}
		}
		return res;
    }
};

