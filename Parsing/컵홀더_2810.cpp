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
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans, S = 0, L = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'S') {
			S++;
		}
		else if (s[i] == 'L') {
			L++;
		}
	}
	L /= 2;
	ans = 1 + S + L;
	cout << min(n, ans);
}