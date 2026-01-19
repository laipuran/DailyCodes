#include<iostream>
#include<vector>
#include<cmath>
#define DIGIT 10
using namespace std;

int get_digit(long long a,int i) {
    long long num = (int)pow(10, i-1);
    long long left = a / num;
    int ret = left % 10;
    return ret;
}

void get_vector_from_double(double a, vector<int>& numbers) {
    long long b = a * pow(10, DIGIT);
    for (int i = 0; i < DIGIT; i++)numbers.push_back(get_digit(b,i+1));
    return;
}

void add_product(vector<int> &a, vector<int> &b, vector<int> &result){
    for (int i = 0; i < DIGIT; i++) { 
        for (int j = 0; j < DIGIT; j++) {
            result[i+j] += a[i] * b[j];
        }
    }
    for (int i = 0; i < 39; i++) {
        result[i + 1] += result[i] / 10;
        result[i] %= 10;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> result(40, 0);
    vector<double> a, b;
    for (int i = 0; i < n; i++) {
        double temp;
        cin >> temp;
        a.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        double temp;
        cin >> temp;
        b.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        vector<int> va, vb;
        get_vector_from_double(a[i], va);
        get_vector_from_double(b[i], vb);
        add_product(va, vb, result);
    }
    bool out = false;
    for (int i = 39; i > 19; i--) {
        if (out || result[i] != 0) {
            cout << result[i];
            out = true;
        }
    }
    if (out == false)cout << 0;
    cout << ".";
    for (int i = 19; i >= 0; i--) {
            cout << result[i];
    }
}