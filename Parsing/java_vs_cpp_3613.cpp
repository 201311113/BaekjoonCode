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
int main() {
	string s;
	cin >> s;
	if (!(s[0] >= 'a' && s[0] <= 'z')) {
		cout << "Error!";
		return 0;
	}
	bool cpp = 0, java = 0;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			continue;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			if (cpp) {
				cout << "Error!";
				return 0;
			}
			java = 1;
		}
		else if (s[i] == '_') {
			if (java) {
				cout << "Error!";
				return 0;
			}
			cpp = 1;
		}
	}
	string ans = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			ans += s[i];
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			int tmp = s[i] - 'A' + 'a';
			ans += '_';
			ans += (char)tmp;
		}
		else if (s[i] == '_') {
			if (i == s.size() - 1 || s[i + 1] == '_') {
				cout << "Error!";
				return 0;
			}
			int tmp = s[i + 1] - 'a' + 'A';
			i++;
			ans += (char)tmp;
		}
	}
	cout << ans;
}