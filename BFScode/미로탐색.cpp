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
int map[101][101];
bool chk[101][101];
int min_cnt = 123456789;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
struct node {
	int x;
	int y;
	int cnt;
};

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[j][i]);
		}
	}
	queue<node> q;
	q.push({ 0,0,1 });
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, cnt = q.front().cnt;
		q.pop();
		if (x == M - 1 && y == N - 1) {
			min_cnt = min(min_cnt, cnt);
		}
		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0], yy = y + dir[i][1];
			if (xx >= 0 && yy >= 0 && xx < M && yy < N && map[xx][yy] == 1 && !chk[xx][yy]) {
				q.push({ xx,yy,cnt + 1 });
				chk[xx][yy] = 1;
			}
		}
	}
	cout << min_cnt;
}