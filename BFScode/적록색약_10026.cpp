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
using namespace std;
int N;
char map[100][100];
bool chk[100][100] = { 0, };						//문제주소:https://www.acmicpc.net/problem/10026
int dir[4][2] = { {1,0}, {0,1} ,{-1,0} ,{0,-1} };
int cnt = 0;
void chk_map(int r, int c) {
	cnt += 1;
	chk[r][c] = 1;
	queue<pair<int, int>> q;
	char pivot = map[r][c];
	q.push(make_pair(r, c));
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0], yy = y + dir[i][1];
			if (xx >= 0 && yy >= 0 && xx < N && yy < N && map[xx][yy] == pivot && chk[xx][yy] == 0) {
				chk[xx][yy] = 1;
				q.push(make_pair(xx, yy));
			}
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[j][i];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (chk[j][i] == 0) chk_map(j, i);
		}
	}
	cout << cnt << " ";
	cnt = 0;
	memset(chk, 0, sizeof(chk));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[j][i] == 'R') map[j][i] = 'G';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (chk[j][i] == 0) chk_map(j, i);
		}
	}
	cout << cnt;

}