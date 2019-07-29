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
using namespace std;				//https://www.acmicpc.net/problem/1012
#define MAX_SIZE 100				//�� ������ 1�� ���μ��η� �پ��ִ� ��� ���� ���� �Ǵ� ������ �����̴�
#define INF 0x7fffffff				//������ ���� �����Է¹޴� ���� �ƴϰ� ������ �ּҸ� �Է¹ޱ� ������ �����ּҸ�
									//�Է¹����� ���� ���߸� �ʿ� 1�� ǥ���Ͽ����Ѵ�
int n, k, d;						//�����ذ��� ���� �ʿ��� ������ ����ü�� �˻��Ͽ� 1�� ã�� �ݺ����� 1�� ã���� 
									//bfs�� ���� check�� ���ִ� ������ �ʿ��ϴ�
// �� �� �� �� 
int dy[] = { 0, -1, 1, 0 };
int dx[] = { -1, 0, 0, 1 };

int map[51][51];
int M, N, K;

void bfs(int x, int y) {
	map[x][y] = 0;
	queue<pair<int, int>> q;
	q.push(pair<int, int>(x, y));
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ax = cx + dx[i];
			int ay = cy + dy[i];
			if (ax >= 0 && ay >= 0 && ax < M && ay < N && map[ax][ay] == 1) {
				map[ax][ay] = 0;
				q.push(pair<int, int>(ax, ay));
			}
		}
	}
}


int main() {
	//std::ios::sync_with_stdio(false); cin.tie(0);

	int T;
	int x, y;
	int cnt;

	scanf("%d", &T);
	for (int c = 0; c < T; c++) {
		cnt = 0;
		scanf("%d %d %d", &M, &N, &K);
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = 0;
			}
		}

		for (int i = 0; i < K; i++) {
			scanf("%d %d", &x, &y);
			map[x][y] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1) {
					bfs(i, j);
					cnt++;
				}
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}