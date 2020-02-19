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
bool chk[503];
vector<int> arr[503];
int dfs(int n) {
	int sum = 0;
	for (int i = 0; i < arr[n].size(); i++) {
		if (!chk[arr[n][i]]) {
			chk[arr[n][i]] = 1;
			sum++;
		}
	}
	return sum;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	int ans = 0;
	chk[1] = 1;
	for (int i = 0; i < arr[1].size(); i++) {
		if (!chk[arr[1][i]]) {
			chk[arr[1][i]] = 1;
			ans++;
		}
		ans += dfs(arr[1][i]);
	}
	cout << ans;
}