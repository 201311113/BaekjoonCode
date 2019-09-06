#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
using namespace std;
int N, M;
int map[1002][1002];
bool chk[1002][1002][2];
int chk_cnt[1002][1002];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
struct node {
	int x;
	int y;
	int flag;
};
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[j][i]);
		}
	}
	int ans = -1;
	queue<node> q;
	q.push({ 0,0,0 });
	chk[0][0][0] = 1;
	chk[0][0][1] = 1;
	chk_cnt[0][0] = 1;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, flag = q.front().flag;
		int cnt = chk_cnt[x][y];
		q.pop();
		if (x == M - 1 && y == N - 1) {
			ans = cnt;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0], yy = y + dir[i][1];
			if (xx >= 0 && yy >= 0 && xx < M && yy < N) {	//움직인게 맵안에 있을 때
				if (map[xx][yy] == 0) {
					if (flag && !chk[xx][yy][flag]) {
						chk[xx][yy][flag] = 1;
						chk_cnt[xx][yy] = cnt + 1;
						q.push({ xx,yy,flag });
					}
					else if (!flag && !chk[xx][yy][flag]) {
						chk[xx][yy][flag] = 1;
						chk_cnt[xx][yy] = cnt + 1;
						q.push({ xx,yy,flag });
					}
				}
				else if (map[xx][yy] == 1) {
					if (flag) continue;
					else if (!flag && !chk[xx][yy][flag]) {		//****벽뿌시고 드갈때 chk에 flag 0 으로 들어감
						chk[xx][yy][flag] = 1;
						chk_cnt[xx][yy] = cnt + 1;
						q.push({ xx,yy, 1 });
					}
				}
			}
		}
	}

	cout << ans;
}