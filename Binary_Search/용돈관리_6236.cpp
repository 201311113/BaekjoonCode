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
int paid[100002];
int main() {
	cin >> n >> m;
	int max_num = 0;
	for (int i = 0; i < n; i++) {
		cin >> paid[i];
		max_num += paid[i];
	}
	int f = 1, l = max_num;
	int ans = max_num;
	while (f <= l) {
		int mid = (f + l) / 2;
		int total = mid;
		int cnt = 1;
		bool flag = 0;
		for (int i = 0; i < n; i++) {
			if (mid < paid[i]) {
				flag = 1;
				break;
			}
			if (total - paid[i] < 0) {
				total = mid;
				cnt++;
			}
			total -= paid[i];
		}
		if (flag) {
			f = mid + 1;
			continue;
		}
		if (cnt > m) {
			f = mid + 1;
		}
		else {
			if (ans > mid) ans = mid;
			l = mid - 1;
		}

	}
	cout << ans;
}