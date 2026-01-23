// Luogu P5788 单调栈

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	stack<int> index;
	vector<int> numbers;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		numbers.push_back(temp);
		while (index.size()>0) {
			if (numbers[index.top()] >= temp)
				break;
			numbers[index.top()] = i + 1;
			index.pop();
		}
		index.push(i);
	}
	while (index.size() > 0) {
		numbers[index.top()] = 0;
		index.pop();
	}
	for (int i : numbers)
		cout << i << " ";
}