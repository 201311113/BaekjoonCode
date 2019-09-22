#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
int R, C;
char map[251][251];									//�����ּ�:https://www.acmicpc.net/problem/3184
bool chk[251][251];									//�� ������ bfs������ ����ü�� �˻��Ͽ� ��Ÿ���� �ƴϰ� �湮
int WOLF = 0, SHEEP = 0;							//���� �ʾ����� bfs�� Ž���Ͽ� �� �����Ǿ��� ���� ���� ���� ī��Ʈ�ϰ�
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };		//�Լ� ����� ��� ���� �� ������ �Ǵ��Ͽ� ��ü ���̳� ������ ����
void bfs(int x, int y) {								//�����ָ� �ذᰡ���ϴ�
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