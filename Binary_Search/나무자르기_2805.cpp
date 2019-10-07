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
	long long n, m;
	vector<int> tree;
	cin >> n >> m;
	long long max_num = 0;
	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		tree.push_back(num);
		max_num = max(max_num, num);
	}
	long long f = 0, l = max_num;
	long long ans = -1;
	while (f <= l) {
		long long mid = (f + l) / 2;
		long long tmp = 0;
		for (int i = 0; i < n; i++) {
			if (mid < tree[i])	tmp += tree[i] - mid;
		}

		if (m > tmp) {
			l = mid - 1;
		}
		else {
			if (mid > ans) ans = mid;
			f = mid + 1;
		}
	}
	cout << ans;
}