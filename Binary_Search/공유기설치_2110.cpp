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
int main() {
	int n, c;
	vector<int> home;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		home.push_back(num);
	}
	sort(home.begin(), home.end());
	long long f = 0, l = home.back();
	long long ans = -1;
	while (f <= l) {
		long long mid = (f + l) / 2;
		int prev = 0;
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			if (home[i] - home[prev] >= mid) {
				prev = i;
				cnt++;
			}
		}
		if (cnt >= c) {
			if (ans < mid) ans = mid;
			f = mid + 1;
		}
		else {
			l = mid - 1;
		}
	}
	cout << ans;
}