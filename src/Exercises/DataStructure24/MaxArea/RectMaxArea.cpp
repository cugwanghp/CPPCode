/*
 * @Description: 
 * @Version: 1.0
 * @Author: Wang Hongping
 * @Date: 2024-12-10 10:16:16
 * @LastEditors: Wang Hongping
 * @LastEditTime: 2024-12-10 10:16:23
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> monotonicStack;
    heights.push_back(0); // Add a sentinel value to pop remaining bars
    int maxArea = 0;

    for (int i = 0; i < heights.size(); i++) {
        while (!monotonicStack.empty() && heights[i] < heights[monotonicStack.top()]) {
            int height = heights[monotonicStack.top()];
            monotonicStack.pop();
            int width = i - (monotonicStack.empty() ? 0 : monotonicStack.top() + 1);
            maxArea = max(maxArea, height * width);
        }
        monotonicStack.push(i);
    }

    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;

    int maxArea = 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> heights(cols, 0);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Update heights array
            if (matrix[i][j] == '1') {
                heights[j]++;
            } else {
                heights[j] = 0;
            }
        }
        
        // Calculate the maximum area for the current row's histogram
        maxArea = max(maxArea, largestRectangleArea(heights));
    }

    return maxArea;
}

int main() {
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    
    int maxArea = maximalRectangle(matrix);
    
    cout << "The area of the largest rectangle containing only 1s is: " << maxArea << endl;

    return 0;
}
