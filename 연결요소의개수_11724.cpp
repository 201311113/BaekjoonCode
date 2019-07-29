#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstdio>
#include<stack>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;						//https://www.acmicpc.net/problem/11724
vector<int> arr[1002];						//그래프를 잘 이해하고 있는가 묻는 문제이다
bool check[1002] = { 0, };
int dfs_result = 1;
int bfs_result = 1;
void dfs(int s, int v) {
	check[s] = 1;
	for (int i = 0; i < arr[s].size(); i++) {
		int next = arr[s][i];
		if (check[next] == 0) {
			dfs(next, v);
		}
	}
	for (int i = 1; i <= v; i++) {
		if (check[i] == 0) {
			dfs_result++;
			dfs(i, v);
		}
	}
}
void bfs(int s, int v) {
	queue<int> q;
	check[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < arr[x].size(); i++) {
			int next = arr[x][i];
			if (check[next] == 0) {
				check[next] = 1;
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		if (check[i] == 0) {
			bfs_result++;
			bfs(i, v);
		}
	}
}
int main() {
	int v, e;
	cin >> v >> e;
	while (e--) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for (int i = 0; i < v; i++) {
		sort(arr[i].begin(), arr[i].end());
	}
	bfs(1, v);

	printf("%d", bfs_result);
}