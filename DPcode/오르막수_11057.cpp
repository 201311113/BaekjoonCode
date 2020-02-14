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
ll d[1003][10];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 10; i++) {
		d[1][i] = 1;
	}
	for (int i = 0; i < 10; i++) {
		d[2][i] = i + 1;
	}
	for (int i = 3; i <= n; i++) {
		d[i][0] = 1;
		for (int j = 1; j < 10; j++) {
			d[i][j] = d[i - 1][j] + d[i][j - 1];
		}
	}
	ll ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += d[n][i];
	}
	cout << ans % 10007;
}