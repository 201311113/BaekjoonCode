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
int map[101][101];
bool chk[101][101];
int n, m;
int cnt, t_cnt = 0;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
bool cal() {
	vector<pair<int, int>> c;
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	chk[0][0] = 1;
	t_cnt++;

	while (!q.empty()) {	//밖에서 부터 0검사해서 안쪽의 구멍은 chk안하도록
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0], yy = y + dir[i][1];
			if (xx >= 0 && yy >= 0 && xx < m && yy < n && !chk[xx][yy]) {
				if (map[xx][yy]) {//1이면 공기가 닿는 치즈
					c.push_back({ xx,yy });
					chk[xx][yy] = 1;
				}
				else {//0이면 아님
					q.push({ xx,yy });
					chk[xx][yy] = 1;
				}
			}
		}
	}
	if (c.size())	cnt = c.size();
	for (int i = 0; i < c.size(); i++) {
		int x = c[i].first, y = c[i].second;
		map[x][y] = 0;
	}
	if (c.empty()) return false;
	else return true;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[j][i];
		}
	}
	while (cal()) {
		memset(chk, 0, sizeof(chk));
	}
	cout << t_cnt - 1 << endl << cnt;
}
