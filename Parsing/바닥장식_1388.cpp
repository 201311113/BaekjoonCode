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
int n, m;
char map[101][101];
bool chk[101][101];
int ans = 0;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
void dfs(char pivot, int x, int y) {
	chk[x][y] = 1;
	ans++;
	if (pivot == '-') {
		queue<pair<int, int>> q;
		q.push({ x,y });
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int i = 0; i < 2; i++) {
				int xx = x + dir[i][0], yy = y + dir[i][1];
				if (xx >= 0 && yy >= 0 && xx < m && yy < n && !chk[xx][yy] && map[xx][yy] == '-') {
					q.push({ xx,yy });
					chk[xx][yy] = 1;
				}
			}
		}
	}
	else if (pivot == '|') {
		queue<pair<int, int>> q;
		q.push({ x,y });
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int i = 2; i < 4; i++) {
				int xx = x + dir[i][0], yy = y + dir[i][1];
				if (xx >= 0 && yy >= 0 && xx < m && yy < n && !chk[xx][yy] && map[xx][yy] == '|') {
					q.push({ xx,yy });
					chk[xx][yy] = 1;
				}
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[j][i];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!chk[j][i]) {
				dfs(map[j][i], j, i);
			}
		}
	}
	cout << ans;
}