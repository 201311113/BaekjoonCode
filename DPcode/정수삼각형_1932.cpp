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
ll d[505][505];
int arr[505][505];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];//i가 높이 j가 idx
		}
	}
	d[1][1] = arr[1][1];
	d[2][1] = d[1][1] + arr[2][1];
	d[2][2] = d[1][1] + arr[2][2];
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i][j] = arr[i][j] + max(d[i - 1][j], d[i - 1][j - 1]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < d[n][i]) {
			ans = d[n][i];
		}
	}
	cout << ans;
}