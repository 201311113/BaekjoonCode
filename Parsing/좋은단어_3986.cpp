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
bool chk(string s) {
	stack<char> stk;
	for (int i = 0; i < s.size(); i++) {
		if (!stk.empty()) {
			if (stk.top() == s[i]) stk.pop();
			else {
				stk.push(s[i]);
			}
		}
		else stk.push(s[i]);
	}
	if (stk.empty()) return true;
	else return false;
}
int main() {
	cin >> n;
	vector<string> abword;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		abword.push_back(s);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		string tmp = abword[i];
		if (chk(tmp)) ans++;
	}
	cout << ans;
}