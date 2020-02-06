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
int d[302];
int a[302];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	d[0] = a[0];
	d[1] = max(a[0]+a[1],a[1]);
	d[2] = max(a[0] + a[2], a[1] + a[2]);
	for (int i = 3; i <= n; i++) {
		d[i] = max(d[i - 2] + a[i], d[i - 3] + a[i] + a[i - 1]);
	}
	cout << d[n-1];

}