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
int n;
int arr[1020];
int dp[1020];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	dp[2] = max(2 * arr[1], arr[2]);
	for (int i = 3; i <= n; i++) {
		dp[i] = max(arr[1]*i,arr[i]);
		for (int j = 1; j <= n; j++) {
			if (j > i - j) {
				break;
			}
			dp[i] = max(dp[i], dp[j] + dp[i - j]);
		}
	}
	cout << dp[n];
}