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
int T, N, Ax, Ay, Bx, By;
int dir[8][2] = { {-2,-1},{-1,-2},{-2,1},{-1,2},{2,-1},{1,-2},{2,1},{1,2} };
int chk[300][300];
int map[300][300];											//https://www.acmicpc.net/problem/7562
struct node {												
	int x;
	int y;
	int cnt;
};
void bfs(int x, int y) {
	queue<node> q;
	q.push({ x,y,0 });
	chk[x][y] = 1;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, cnt = q.front().cnt;
		q.pop();
		if (x == Bx && y == By) {
			cout << cnt << endl;
			return;
		}
		for (int i = 0; i < 8; i++) {
			int xx = x + dir[i][0], yy = y + dir[i][1];
			if (xx >= 0 && yy >= 0 && xx < N && yy < N && !chk[xx][yy]) {
				q.push({ xx, yy, cnt + 1 });
				chk[xx][yy] = 1;
			}
		}
	}
}
int main() {
	cin >> T;
	while (T--) {
		memset(chk, 0, sizeof(chk));
		cin >> N;
		cin >> Ax >> Ay >> Bx >> By;
		bfs(Ax, Ay);
	}
}