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

vector<pair<int, int>> brid[100001];
int n, m;
int a, b;
bool chk[100001];
bool cal(long long val) {
	queue<int> q;
	q.push(a);
	while (!q.empty()) {
		int idx = q.front();
		q.pop();
		if (idx == b) return true;
		for (int i = 0; i < brid[idx].size(); i++) {
			if (!chk[brid[idx][i].first] && brid[idx][i].second >= val) {
				q.push(brid[idx][i].first);
				chk[brid[idx][i].first] = 1;
			}
		}
	}
	return false;
}
int main() {
	cin >> n >> m;
	long long max_num = 0;
	for (int i = 0; i < m; i++) {
		int a, b, v;
		cin >> a >> b >> v;
		max_num += v;
		brid[a].push_back({ b,v });
		brid[b].push_back({ a,v });
	}
	cin >> a >> b;
	long long f = 0, l = max_num;
	int ans = 0;
	while (f <= l) {
		long long mid = (f + l) / 2;
		if (cal(mid)) {
			f = mid + 1;
			ans = mid;
		}
		else {
			l = mid - 1;
		}
		memset(chk, 0, sizeof(chk));
	}
	cout << ans;
}