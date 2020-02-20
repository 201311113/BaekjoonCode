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
typedef long long ll;
int dp[304][304];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dp[i][1] = i - 1;
	}
	for (int i = 2; i <= m; i++) {
		dp[n][i] = dp[n][i - 1] + n;
	}
	cout << dp[n][m];
}