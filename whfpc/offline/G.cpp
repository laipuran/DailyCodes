#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

int main() {
	int n, len;
	cin >> n >> len;
	if (n >= 20)cout << string(len, '1');
	else {
		int count = 0;
		for (int i = 0; i < len; i++) {
			if (count < pow(2, n - 1)) {
				cout << 1;
				count++;
			}
			else {
				cout << 0;
				count--;
			}
		}
	}
}