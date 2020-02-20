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
int arr[1020];
ll dp[1020];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) dp[i] = arr[i];
	for (int i = 2; i <= n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i],dp[j] + arr[i]);
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(dp[i], ans);
	}
	cout << ans;
}