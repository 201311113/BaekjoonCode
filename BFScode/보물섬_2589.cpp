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
char map[50][50];
int chk[50][50] = { -1, };
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	int cnt = -1;
	chk[x][y] = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0], yy = y + dir[i][1];
			if (xx >= 0 && yy >= 0 && xx < M && yy < N && map[xx][yy] == 'L' && chk[xx][yy] == -1) {
				q.push({ xx,yy });
				chk[xx][yy] = chk[x][y] + 1;
			}
		}
		cnt = chk[x][y];
	}
	return cnt;
}
int main() {
	cin >> N >> M;
	int max_cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[j][i];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			memset(chk, -1, sizeof(chk));
			if (map[j][i] == 'L') {
				max_cnt = max(max_cnt, bfs(j, i));
			}
		}
	}
	cout << max_cnt;
}
