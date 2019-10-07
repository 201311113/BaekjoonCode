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
int l_budget[10001];
int main() {
	long long n, m;
	cin >> n;
	int max_budget = 0;
	for (int i = 0; i < n; i++) {
		cin >> l_budget[i];
		max_budget = max(max_budget, l_budget[i]);
	}
	cin >> m;
	long long f = 0, l = max_budget;
	long long ans = 0;
	while (f <= l) {
		long long mid = (f + l) / 2;
		long long tmp = 0;
		for (int i = 0; i < n; i++) {
			if (l_budget[i] > mid)tmp += mid;
			else tmp += l_budget[i];
		}
		if (tmp > m) {
			l = mid - 1;
		}
		else {
			if (ans < mid) ans = mid;
			f = mid + 1;
		}
	}
	cout << ans;
}