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
using namespace std;
int N;
int arr[12];
int sig[4];
long long min_ans = 1000000001;
long long max_ans = -1000000001;
void dfs(int plus, int minus, int mul, int div, int cnt, long long tmp) {
	if (cnt == N) {
		min_ans = min(min_ans, tmp);
		max_ans = max(max_ans, tmp);
		return;
	}
	if (plus > 0) {
		dfs(plus - 1, minus, mul, div, cnt + 1, tmp + arr[cnt]);
	}
	if (minus > 0) {
		dfs(plus, minus - 1, mul, div, cnt + 1, tmp - arr[cnt]);
	}
	if (mul > 0) {
		dfs(plus, minus, mul - 1, div, cnt + 1, tmp * arr[cnt]);
	}
	if (div > 0) {
		dfs(plus, minus, mul, div - 1, cnt + 1, tmp / arr[cnt]);
	}
	return;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> sig[i];
	}
	dfs(sig[0], sig[1], sig[2], sig[3], 1, arr[0]);
	cout << max_ans << endl;
	cout << min_ans << endl;
}
