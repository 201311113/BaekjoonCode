#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
vector<int> a[1002];
bool check[1002] = { 0, };
bool check2[1002] = { 0, };
void DFS(int start) {
	check[start] = true;
	printf("%d ", start);
	for (int i = 0; i < a[start].size(); i++) {
		int next = a[start][i];
		if (check[next] == 0)
			DFS(next);
	}
}
void BFS(int start) {
	queue<int> q;
	check2[start] = 1;
	q.push(start);
	while (!q.empty()) {
		int next = q.front();
		printf("%d ", next);
		q.pop();
		for (int i = 0; i < a[next].size(); i++) {
			int next2 = a[next][i];
			if (check2[next2] == 0) {
				check2[next2] = 1;
				q.push(next2);
			}
		}
	}
}
int main() {
	int Vnum, Enum, start;
	scanf("%d %d %d", &Vnum, &Enum, &start);
	for (int i = 0; i < Enum; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i < Vnum; i++) {
		sort(a[i].begin(), a[i].end());
	}
	DFS(start);
	printf("\n");
	BFS(start);
}
