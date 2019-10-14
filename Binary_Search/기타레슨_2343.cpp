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
int n, m;
int lesson[100001];
int main() {
	cin >> n >> m;
	int t_time = 0;
	for (int i = 0; i < n; i++) {
		cin >> lesson[i];
		t_time += lesson[i];
	}
	int f = 0, l = t_time;
	long long ans = 100000 * 10000;
	while (f <= l) {
		int mid = (f + l) / 2;
		int cnt = 1;
		int total = 0;
		bool flag = 0;
		for (int i = 0; i < n; i++) {
			if (lesson[i] > mid) {
				flag = 1;
				break;
			}
			total += lesson[i];
			if (total > mid) {
				total = lesson[i];
				cnt++;
			}
		}
		if (flag) {
			f = mid + 1;
			continue;
		}
		if (cnt <= m) {
			if (ans > mid) ans = mid;
			l = mid - 1;
		}
		else {
			f = mid + 1;
		}
	}
	cout << ans;
}