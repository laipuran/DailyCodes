/*
 *	P1901 ∑¢…‰’æ
 */

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

struct Node {
	//int before, end;
	long long int height;
	long long energy;
	long long total;
	Node(long long height, int energy) :height(height), energy(energy), total(0) {};
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<Node> nodes;
	for (int i = 0; i < n; i++) {
		long long a; int b;
		cin >> a >> b;
		nodes.push_back(Node(a, b));
	}
	stack<int> index;
	for (int i = 0; i < n; i++) {
		while (!index.empty()) {
			if (nodes[i].height <= nodes[index.top()].height)
				break;
			nodes[i].total += nodes[index.top()].energy;
			index.pop();
		}
		index.push(i);
	}
	while(!index.empty())index.pop();
	for (int i = n - 1; i >= 0; i--) {
		while (!index.empty()) {
			if (nodes[i].height <= nodes[index.top()].height)
				break;
			nodes[i].total += nodes[index.top()].energy;
			index.pop();
		}
		index.push(i);
	}
	long long max = 0;
	for (int i = 0; i < n; i++)max = nodes[i].total > max ? nodes[i].total : max;
	cout << max;
}