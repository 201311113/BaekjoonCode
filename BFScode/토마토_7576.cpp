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
using namespace std;			//���� ��ó : https://www.acmicpc.net/problem/7576
int N, M;
int map[1001][1001];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int max_day = 0;
struct node {					//��� �迭���� �˻��Ͽ� 1���̸� ť�� �־� bfs�� �����Ͽ��� ��¥�� ���� ���ؼ� 
	int x;						//node��� �ڷ����� ������� �׷��� bfs�� ������ �� ���� ������ ����Ǹ�
	int y;						//�������� ������ �丶��(0��)�� �ִ��� Ȯ���� ������ -1�� ������ ��¥���� ����Ѵ�
	int day;

};
bool chk() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[j][i] == 0) {
				return false;
			}
		}
	}
	return true;
}
void bfs() {
	queue<node> q;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[j][i] == 1) {
				q.push({ j,i,0 });
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, day = q.front().day;
		q.pop();
		max_day = max(max_day, day);
		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0], yy = y + dir[i][1];
			if (xx >= 0 && yy >= 0 && xx < N && yy < M && map[xx][yy] == 0) {
				map[xx][yy] = 1;
				q.push({ xx, yy, day + 1 });
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[j][i];
		}
	}
	bfs();
	if (chk())
		cout << max_day;

	else
		cout << "-1";
}