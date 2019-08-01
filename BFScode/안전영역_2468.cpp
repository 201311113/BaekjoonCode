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
using namespace std;								//https://www.acmicpc.net/problem/2468
int N;												//�� ������ ���� ���̸��� �˻��Ͽ��� �ϱ⶧���� 1.���� �ִ���̸�ŭ
int map[101][101];									//�ݺ��ϸ鼭 ��俵���� üũ�ϴ� ������ 2.���� ���� ������ ������
bool drown_map[101][101];							//���ϴ� ������ ����Ͽ� ���� Ǯ �� �־���.
int max_height = 0;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	drown_map[x][y] = 1;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0], yy = y + dir[i][1];
			if (xx >= 0 && yy >= 0 && xx < N && yy < N && drown_map[xx][yy] == 0) {
				drown_map[xx][yy] = 1;
				q.push({ xx,yy });
			}
		}
	}
}
int main() {
	cin >> N;
	int max_safearea = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[j][i];
			max_height = max(max_height, map[j][i]);
		}
	}
	for (int k = 0; k < max_height; k++) {
		memset(drown_map, 0, sizeof(drown_map));
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[j][i] <= k) {
					drown_map[j][i] = 1;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (drown_map[j][i] == 0) {
					bfs(j, i);
					cnt++;
				}
			}
		}
		max_safearea = max(max_safearea, cnt);
	}
	cout << max_safearea;
}