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
int W, H, K;
int map[201][201];
bool chk[201][201][31];
int dir_H[8][2] = { {-2,-1}, {-1,-2},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1} };
int dir_M[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
struct node {
	int x_;
	int y_;
	int k;
	int cnt;
};
int main() {
	cin >> K >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[j][i];
		}
	}
	bool flag = 0;
	queue<node> q;
	q.push({ 0,0,K,0 });
	chk[0][0][K] = 1;
	int min_cnt = 123456789;
	while (!q.empty()) {
		int x = q.front().x_, y = q.front().y_, k = q.front().k, cnt = q.front().cnt;
		q.pop();
		if (x == W - 1 && y == H - 1) {
			min_cnt = min(min_cnt, cnt);
			flag = 1;
			continue;
		}
		if (k > 0) {
			for (int i = 0; i < 8; i++) {
				int xx = x + dir_H[i][0], yy = y + dir_H[i][1];
				if (xx >= 0 && yy >= 0 && xx < W && yy < H && !chk[xx][yy][k - 1] && map[xx][yy] == 0) {
					q.push({ xx,yy, k - 1,cnt + 1 });
					chk[xx][yy][k - 1] = 1;
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int xx = x + dir_M[i][0], yy = y + dir_M[i][1];
			if (xx >= 0 && yy >= 0 && xx < W && yy < H && !chk[xx][yy][k] && map[xx][yy] == 0) {
				q.push({ xx,yy,k,cnt + 1 });
				chk[xx][yy][k] = 1;
			}
		}
	}
	if (flag) cout << min_cnt;
	else cout << "-1";
}