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
int map[9][9];
bool chk[9][9];	//bfs에서 쓰임
queue<pair<int, int>> virus_addr;
int map_tmp[9][9];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int safe_area = 0;
int one_cnt = 0;
int bfs() {
	queue<pair<int, int>> q;
	q = virus_addr;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map_tmp[j][i] = map[j][i];
		}
	}
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0], yy = y + dir[i][1];
			if (xx >= 0 && yy >= 0 && xx < M && yy < N && map_tmp[xx][yy] == 0) {
				map_tmp[xx][yy] = 2;
				q.push(make_pair(xx, yy));
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map_tmp[j][i] == 0) sum++;
		}
	}
	return sum;
}
void dfs(int wall_cnt) {
	if (wall_cnt == 3) {
		safe_area = max(safe_area, bfs());
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[j][i] == 0) {		//범위안에 있고 벽없으면 벽짓고 재귀
				map[j][i] = 1;
				dfs(wall_cnt + 1);
				map[j][i] = 0;
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[j][i];
			if (map[j][i] == 2) {
				virus_addr.push(make_pair(j, i));
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[j][i] == 0) {
				map[j][i] = 1;
				dfs(1);
				map[j][i] = 0;
			}
		}
	}
	cout << safe_area;
}