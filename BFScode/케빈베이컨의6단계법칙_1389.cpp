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
int N, M;
vector<int> v[101];
bool chk[101];
int bfs(int num) {
	memset(chk, 0, sizeof(chk));
	queue<pair<int, int>> q;
	q.push({ num,0 });
	chk[num] = 1;
	int sum = 0;
	while (!q.empty()) {
		int n = q.front().first, cnt = q.front().second;
		q.pop();
		sum += cnt;
		for (int i = 0; i < v[n].size(); i++) {
			if (!chk[v[n][i]]) {
				q.push({ v[n][i],cnt + 1 });
				chk[v[n][i]] = 1;
			}
		}
	}
	return sum;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int min_sum = 123456789;
	int min_idx;
	for (int i = 1; i <= N; i++) {
		int num = bfs(i);
		if (num == min_sum) {
			min_idx = min(min_idx, i);
		}
		else {
			if (min_sum > num) {
				min_sum = min(min_sum, num);
				min_idx = i;
			}
		}
	}
	cout << min_idx;
}