#include<iostream>

using namespace std;

const int MAX = 20000005;
bool can[MAX];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i < 10000; i++) {
		for (int j = i; j < 10000; j++) {
			if ((j * j + i * i) < 20000000)can[j * j + i * i] = true;
			else break;
		}
	}

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (can[temp])cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}