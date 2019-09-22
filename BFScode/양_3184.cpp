#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
int R, C;
char map[251][251];									//문제주소:https://www.acmicpc.net/problem/3184
bool chk[251][251];									//이 문제는 bfs문제로 맵전체를 검사하여 울타리가 아니고 방문
int WOLF = 0, SHEEP = 0;							//하지 않았으면 bfs로 탐색하여 그 영역의양의 수와 늑대 수를 카운트하고
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };		//함수 종료시 어느 쪽이 더 많은지 판단하여 전체 양이나 늑대의 수를
void bfs(int x, int y) {								//더해주면 해결가능하다
	queue<pair<int, int>> q;
	q.push({ x,y });
	int wolf = 0, sheep = 0;
	if (map[x][y] == 'v') {
		wolf++;
	}
	else if (map[x][y] == 'o') {
		sheep++;
	}
	chk[x][y] = 1;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0], yy = y + dir[i][1];
			if (xx >= 0 && yy >= 0 && xx < C && yy < R && map[xx][yy] != '#' && !chk[xx][yy]) {
				if (map[xx][yy] == 'v') {
					wolf++;
				}
				else if (map[xx][yy] == 'o') {
					sheep++;
				}
				q.push({ xx,yy });
				chk[xx][yy] = 1;
			}
		}
	}
	if (wolf >= sheep) {
		WOLF += wolf;
	}
	else {
		SHEEP += sheep;
	}
}
int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[j][i];
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[j][i] != '#' && !chk[j][i]) {
				bfs(j, i);
			}
		}
	}
	cout << SHEEP << " " << WOLF;
}