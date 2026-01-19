#include<iostream>
using namespace std;
int main() {
	long long n;
	cin >> n;
	if (n == 1 || n == 2)
	{
		cout << 1;
		return 0;
	}
	long long lineStart = 1, max = 1;
	for (int i = 2; i <= n; i++) {
		if ((i - lineStart) == (max)) {
			lineStart = i;
			max = i;
		}
		else
		{
			max += i;
		}
		if (n - i <= max) {
			cout << n - i - 1;
			return 0;
		}
	}
}