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
int N;
int map[102][102];
bool chk[102][102];
int chk_brid[102][102];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
void bfs_colored(int x, int y, int cnt) {		//»öÄ¥
	queue<pair<int, int>> q;
	q.push({ x,y });
	chk[x][y] = 1;
	map[x][y] = cnt;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0], yy = y + dir[i][1];
			if (xx >= 0 && yy >= 0 && xx < N && yy < N && !chk[xx][yy] && map[xx][yy] == 1) {
				chk[xx][yy] = 1;
				map[xx][yy] = cnt;
				q.push({ xx,yy });
			}
		}
	}
}
bool chk_shore(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int xx = x + dir[i][0], yy = y + dir[i][1];
		if (xx >= 0 && yy >= 0 && xx < N && yy < N) {
			if (map[xx][yy] == 0) {
				return true;
			}
		}
	}
	return false;
}
struct node {
	int x;
	int y;
	int cnt;
};
int bfs_shore(int x, int y) {
	queue<node> q;
	memset(chk_brid, 0, sizeof(chk_brid));
	chk_brid[x][y] = 1;
	q.push({ x,y,0 });
	int pivot = map[x][y];
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, cnt = q.front().cnt;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0], yy = y + dir[i][1];
			if (xx >= 0 && yy >= 0 && xx < N && yy < N) {
				if (map[xx][yy] == 0 && !chk_brid[xx][yy]) {
					chk_brid[xx][yy] = chk_brid[x][y] + 1;
					q.push({ xx,yy ,cnt + 1 });
				}
				else if (map[xx][yy] && map[xx][yy] != pivot) {
					return cnt;
				}
			}
		}
	}

}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[j][i];
		}
	}
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[j][i] == 1 && !chk[j][i]) {
				bfs_colored(j, i, cnt);
				cnt += 1;
			}
		}
	}
	int ans = 123456789;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[j][i] && chk_shore(j, i)) {
				ans = min(ans, bfs_shore(j, i));
			}
		}
	}

	cout << ans;
}