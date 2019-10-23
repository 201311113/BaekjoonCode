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
int n, m;
int cost[100001];
int main() {
	cin >> n >> m;
	long long max_num = 0;
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
		if (max_num < cost[i]) max_num = cost[i];
	}
	max_num *= m;
	ll f = 1, l = max_num;
	ll ans = 0;
	while (f <= l) {
		ll mid = (f + l) / 2;
		ll tmp = 0;
		for (int i = 0; i < n; i++) {
			tmp += mid / cost[i];
		}
		if (tmp < m) {
			f = mid + 1;
		}
		else {
			ans = mid;
			l = mid - 1;
		}
	}
	cout << ans;
}