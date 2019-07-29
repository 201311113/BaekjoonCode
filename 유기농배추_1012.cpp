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
#define MAX_SIZE 100				//이 문제는 1이 가로세로로 붙어있는 덩어리 수를 세면 되는 간단한 문제이다
#define INF 0x7fffffff				//문제는 맵을 직접입력받는 것이 아니고 배추의 주소를 입력받기 때문에 배추주소를
									//입력받을때 마다 배추를 맵에 1로 표기하여야한다
int n, k, d;						//문제해결을 위해 필요한 로직은 맵전체를 검사하여 1을 찾는 반복문과 1을 찾으면 
									//bfs를 돌려 check를 해주는 로직이 필요하다
// 상 하 좌 우 
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