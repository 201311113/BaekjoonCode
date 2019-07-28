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
using namespace std;			//문제 출처 : https://www.acmicpc.net/problem/7576
int N, M;
int map[1001][1001];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int max_day = 0;
struct node {					//모든 배열값을 검사하여 1값이면 큐에 넣어 bfs를 진행하였다 날짜를 세기 위해서 
	int x;						//node라는 자료형을 만들었다 그렇게 bfs가 진행할 수 없을 때까지 진행되면
	int y;						//마지막에 안익은 토마토(0값)이 있는지 확인후 있으면 -1을 없으면 날짜값을 출력한다
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