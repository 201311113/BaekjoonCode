#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<stack>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<ctime>
#include<set>
#include<sstream>
using namespace std;
int arr[10];
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int mul_ans = a * b * c;
	string s = to_string(mul_ans);
	for (int i = 0; i < s.size(); i++) {
		arr[s[i] - '0']++;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}
}