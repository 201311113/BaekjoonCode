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
	getline(cin, s);
	int ans;
	if (s[0] == ' ') ans = -1;
	else ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			ans++;
		}
	}
	if (s[s.size() - 1] == ' ') {
		ans--;
	}
	cout << ans + 1;
}
