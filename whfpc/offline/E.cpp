#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
struct Node {
	Node* parent;
	vector<Node*> children;
	bool is_deleted = false;
};

int get_children(Node* node) {
	if (node->is_deleted)return 0;
	if (node->children.empty())return 1;
	int count = 0;
	for (auto n : node->children) {
		count += get_children(n);
	}
	return count + 1;
}

int get_parent_nodes(Node* node) {
	if (node->parent == nullptr || node->parent->is_deleted)return 0;
	int count = 0;
	auto p = node->parent;
	count += get_children(p) - get_children(node);
	count += get_parent_nodes(p);
	return count;
}

int main() {
	int n;
	unordered_map<int, Node*> nodes;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		nodes.insert({i,new Node});
	}
	nodes[1]->parent = nullptr;
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		nodes[a]->children.push_back(nodes[b]);
		nodes[b]->parent=nodes[a];
	}
	int t;
	cin >> t;
	vector<int> ans;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		nodes[a]->is_deleted = true;
		int count = 0;
		count = get_parent_nodes(nodes[b]) + get_children(nodes[b]);
		ans.push_back(count);

		nodes[a]->is_deleted = false;
	}
	for (int a : ans)cout << a << endl;
	return 0;
}