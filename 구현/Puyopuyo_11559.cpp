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
typedef long long ll;
char map[7][13];
bool chk[7][13];
int cnt = 0;
int dir[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
bool chk_finish() {
	vector<pair<int, int>> puyo;
	bool flag = 0;
	for (int i = 11; i >=0; i--) {
		for (int j = 0; j < 6; j++) {
			if (!chk[j][i] && map[j][i] != '.') {
				int t_cnt = 1;
				char pivot = map[j][i];
				chk[j][i] = 1;
				puyo.push_back({ j,i });
				queue<pair<int, int>> q;
				q.push({ j,i });
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int xx = x + dir[i][0], yy = y + dir[i][1];
						if (xx >= 0 && yy >= 0 && xx < 6 && yy < 12 && map[xx][yy] == pivot && !chk[xx][yy]) {
							t_cnt++;
							chk[xx][yy] = 1;
							puyo.push_back({ xx,yy });
							q.push({ xx,yy });
						}
					}
				}
				if (t_cnt >= 4) {
					flag = 1;
					for (int i = 0; i < puyo.size(); i++) {
						map[puyo[i].first][puyo[i].second] = '.';
					}
				}
				puyo.clear();
			}
		}
	}
	if (flag) return false;
	return true;
}
int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> map[j][i];
		}
	}
	int ans = 0;
	while (!chk_finish()) {
		ans++;
		memset(chk, 0, sizeof(chk));
		for (int i = 0; i < 6; i++) {
			for (int j = 11; j >=0 ; j--) {
				if (map[i][j] != '.') {
					char t_map = map[i][j];
					for (int k = j + 1; k < 12; k++) {
						if (map[i][k] == '.') {
							map[i][k] = t_map;
							map[i][k - 1] = '.';
						}
					}
				}
			}
		}
	}
	cout << ans;
}