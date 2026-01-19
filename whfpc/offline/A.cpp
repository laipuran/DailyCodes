#include<iostream>
#include<string>
#include<vector>
using namespace std;

string strs[5] = { "WHUT","WHU" ,"HZAU" ,"HUST" ,"CCNU" };
int num[5] = { 0,0,0,0,0 };

struct times {
	int index;
	int count;
};

int find_next(string str, string school, int alpha, int index) {
	vector<times> indexes;
	for (int i = index; i < str.length(); i++) {
		if (str[i] == school[alpha]) {
			//cout << "found" << school[alpha] << endl;
			times st;
			st.index = i;
			if (alpha == school.length() - 1)st.count = 1;
			else st.count = find_next(str, school, alpha + 1, i + 1);
			indexes.push_back(st);
		}
	}
	int sum = 0;
	for (auto a : indexes)sum += a.count;
	return sum;
}

int main() {
	string input;
	cin >> input;
	for (int i = 0; i < 5; i++) {
		//cout << "checking " << strs[i] << endl;
		num[i] = find_next(input, strs[i], 0, 0);
	}
	int max = 0;
	string max_sch = "";
	for (int i = 0; i < 5; i++) {
		if (num[i] >= max) {
			max = num[i];
			max_sch = strs[i];
		}
	}
	cout << max_sch << " " << max << endl;
}