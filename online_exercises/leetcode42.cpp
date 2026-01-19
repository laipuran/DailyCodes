#include<iostream>
#include<cmath>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> index;
        int n = height.size(), sum = 0;
        for (int i = 0; i < n; i++) {
            while (!index.empty() && height[i] > height[index.top()]) {
                int bottom = height[index.top()];
                index.pop();
                if (index.empty()) break;
                int right = height[i];
                int left = height[index.top()];
                int h = min(right, left) - bottom;
                int w = i - index.top() - 1;
                sum += h * w;
            }
            index.push(i);
        }
        return sum;
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n;
    vector<int> heights;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        heights.push_back(temp);
    }
    Solution sln;
    cout << sln.trap(heights) << "\n";
}