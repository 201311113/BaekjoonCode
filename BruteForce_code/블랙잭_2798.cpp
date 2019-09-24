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
int n, m;
int arr[101];
int ans = 0;
void cal(int idx, int sum, int cnt) {

	if (cnt == 3 && sum <= m) {
		if (ans < sum)ans = sum;
		return;
	}
	if (idx >= n || cnt > 3 || sum > m) return;
	cal(idx + 1, sum + arr[idx], cnt + 1);
	cal(idx + 1, sum, cnt);
}
int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cal(0, 0, 0);
	cout << ans << endl;
}