#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main() {
    int m;
    cin >> m;
    for (int r = 0; r < m; r++) {
        int n;
        cin >> n;
        vector<int> nums;
        int min = 0; int nmax = 0;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            if (i == 0)min = temp;
            if (temp < min)min = temp;
            if (temp > nmax)nmax = temp;
            nums.push_back(temp);
        }
        cout <<
            max(max(nums[0] - nums[n - 1], nums[n - 1] - nums[0]), max(nmax - nums[n - 1], nums[0] - min)) << endl;
    }
}