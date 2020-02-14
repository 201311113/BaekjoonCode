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
int arr[1020][3];
int d[1020][3];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		arr[i][0] = r;
		arr[i][1] = g;
		arr[i][2] = b;
	}
	d[1][0] = arr[1][0];
	d[1][1] = arr[1][1];
	d[1][2] = arr[1][2];
	for (int i = 2; i <= n; i++) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + arr[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + arr[i][1];
		d[i][2] = min(d[i - 1][1], d[i - 1][0]) + arr[i][2];
	}
	int ans = 123456789;
	if (ans > d[n][0]) ans = d[n][0];
	if (ans > d[n][1]) ans = d[n][1];
	if (ans > d[n][2]) ans = d[n][2];
	cout << ans;
}