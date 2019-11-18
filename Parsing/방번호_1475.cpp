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
string n;
int alpha[10];
int main() {
	cin >> n;
	for (int i = 0; i < n.size(); i++) {
		alpha[n[i] - '0']++;
	}
	int cnt = (alpha[6] + alpha[9]) / 2;
	if ((alpha[6] + alpha[9]) % 2)	cnt++;
	for (int i = 0; i < 9; i++) {
		if (i == 6) continue;
		cnt = max(cnt, alpha[i]);
	}
	cout << cnt;
}