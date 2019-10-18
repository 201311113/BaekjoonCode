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
int n, h;
int arr_u[100001];
int arr_d[100001];

int cal_d(int idx) {
	int f = 0, l = n / 2 - 1;
	while (f <= l) {
		int mid = (f + l) / 2;
		if (arr_d[mid] < idx) {
			f = mid + 1;
		}
		else {
			l = mid - 1;
		}
	}

	return n / 2 - f;
}
int cal_u(int idx) {
	int f = 0, l = n / 2 - 1;
	while (f <= l) {
		int mid = (f + l) / 2;
		if (arr_u[mid] < idx) {
			f = mid + 1;
		}
		else {
			l = mid - 1;
		}
	}
	return n / 2 - f;
}
int main() {
	cin >> n >> h;
	for (int i = 0; i < n / 2; i++) {
		cin >> arr_d[i] >> arr_u[i];
	}
	sort(arr_d, arr_d + (n / 2));
	sort(arr_u, arr_u + (n / 2));
	int ans = n;
	int cnt = 0;
	for (int i = 1; i <= h; i++) {
		int tmp = cal_d(i) + cal_u(h - i + 1);
		if (ans == tmp) cnt++;
		else if (ans > tmp) {
			cnt = 1;
			ans = tmp;
		}

	}
	cout << ans << " " << cnt;
}