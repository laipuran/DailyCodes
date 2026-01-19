#include<iostream>
#include<string>
using namespace std;

void move(long long &x, long long &y, char op) {
	switch (op)
	{
	case 'L':
		//cout << "L";
		x--;
		break;
	case 'R':
		//cout << "R";
		x++;
		break;
	case 'U':
		//cout << "U";
		y++;
		break;
	case 'D':
		//cout << "D";
		y--;
		break;
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	int length, n;
	string str;
	cin >> length >> n >> str;
	for (int i = 0; i < n; i++) {
		long long x = 0, y = 0;
		int l, r;
		long long dx, dy;
		cin >> l >> r >> dx >> dy;
		for (int j = 1; j < l; j++) {
			move(x, y, str[j - 1]);
		}
		for (int j = r + 1; j <= length; j++) {
			move(x, y, str[j - 1]);
		}
		if (x == dx && y == dy)cout << "YES\n";
		else cout << "NO\n";
	}
}