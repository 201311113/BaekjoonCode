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
int map[21][21] = { 0, };
int N, M, x, y, k;
int dice[6] = { 0, };	//idx = 2이 위, 5가 아래
void mv_dice(int op) {
	if (op == 1 && y + 1 < M) {
		y += 1;
		int tmp = dice[5];
		dice[5] = dice[3];
		dice[3] = dice[2];
		dice[2] = dice[1];
		dice[1] = tmp;
		if (map[x][y] == 0) {
			map[x][y] = dice[5];
		}
		else {
			dice[5] = map[x][y];
			map[x][y] = 0;
		}
	}
	else if (op == 2 && y - 1 >= 0) {
		y -= 1;
		int tmp = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[3];
		dice[3] = tmp;
		if (map[x][y] == 0)
			map[x][y] = dice[5];
		else {
			dice[5] = map[x][y];
			map[x][y] = 0;
		}
	}
	else if (op == 3 && x - 1 >= 0) {
		x -= 1;
		int tmp = dice[5];
		dice[5] = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[4];
		dice[4] = tmp;
		if (map[x][y] == 0)
			map[x][y] = dice[5];
		else {
			dice[5] = map[x][y];
			map[x][y] = 0;
		}
	}
	else if (op == 4 && x + 1 < N) {
		x += 1;
		int tmp = dice[5];
		dice[5] = dice[4];
		dice[4] = dice[2];
		dice[2] = dice[0];
		dice[0] = tmp;
		if (map[x][y] == 0)
			map[x][y] = dice[5];
		else {
			dice[5] = map[x][y];
			map[x][y] = 0;
		}
	}
	else return;
	cout << dice[2] << endl;

	return;
}
int main() {
	cin >> N >> M >> x >> y >> k;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	dice[5] = map[x][y];
	for (int i = 0; i < k; i++) {
		int op;
		cin >> op;
		mv_dice(op);
	}

}