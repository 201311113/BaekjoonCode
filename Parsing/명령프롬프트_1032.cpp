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
int n;
int main() {
	cin >> n;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	int max_size = v[0].size();
	string ans = "";
	for (int i = 0; i < max_size; i++) {
		bool flag = 1;
		for (int j = 1; j < n; j++) {
			if (v[j][i] == '?') continue;
			if (v[j][i] != v[j - 1][i]) {
				ans += '?';
				flag = 0;
				break;
			}
		}
		if (flag) ans += v[0][i];
	}
	cout << ans;
}