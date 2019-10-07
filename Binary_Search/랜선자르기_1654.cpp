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
int arr[10001];
int main() {
	long long k, n;
	cin >> k >> n;
	long long min_len = 10000000001;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}
	long long f = 0, l = min_len;
	long long ans = 0;

	while (f <= l) {
		long long tmp = 0;
		long long mid = (f + l) / 2;
		for (int i = 0; i < k; i++) {
			tmp += arr[i] / mid;
		}
		if (tmp >= n) {//n개 넘개 나오면
			if (ans < mid) ans = mid;
			f = mid + 1;
		}
		else {
			l = mid - 1;
		}
	}
	cout << ans;
}