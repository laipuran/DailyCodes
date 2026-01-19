//#include<cmath>
//#include<vector>
//#include<unordered_set>
//#include<iostream>
//
//using namespace std;
//unordered_set<int> prime; int max_prime = 3;
//bool is_prime(int num) {
//	if (num == 1)return false;
//	if (num == 2)return true;
//	auto it = prime.find(num);
//	if (num < max_prime && it == prime.end())return false;
//	if (it != prime.end())return true;
//	for (int i = 2; i < sqrt(num) + 1; i++) {
//		if (num%i == 0)return false;
//	}
//	if (prime.find(num) == prime.end())
//		prime.insert({num});
//	if (num > max_prime)max_prime = num;
//	return true;
//}
//
//int main() {
//	cin.sync_with_stdio(false);
//	cin.tie(0);
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int a;
//		cin >> a;
//		bool can = false;
//		if (is_prime(a)) {
//			can = (a % 4 == 1) || a == 2;
//		}
//		else {
//			for (int j = 1; j <= sqrt(a / 2) + 1; j++) {
//				int another = sqrt(a - j * j);
//				if (a == j * j + another * another && another > 0)can = true;
//			}
//		}
//		if (can)cout << "Yes\n";
//		else cout << "No\n";
//	}
//}