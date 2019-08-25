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
int N, K, L;
int map[101][101] = { 0, };	//사과 1 몸통 -1 빈칸 0 벽은 범위초과
vector<pair<int, char>> op;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} }; // 동 남 서 북
int t = 0;
void gaming(int h_r, int h_c, int t_r, int t_c, int d) {
	queue<pair<int, int>> tail;
	tail.push(make_pair(h_r, h_c));
	for (int i = 0; i < op.size(); i++) {
		for (int j = 0; j < op[i].first; j++) {		//명령어 시간만큼 반복
			h_r += dir[d][0];
			h_c += dir[d][1];
			tail.push(make_pair(h_r, h_c));
			if (h_r >= N || h_c >= N || h_r < 0 || h_c < 0 || map[h_r][h_c] == 2) {	//종료 조건
				t += 1;
				return;
			}
			if (map[h_r][h_c] != 1) {	//꼬리 줄이기
				t_r = tail.front().first;
				t_c = tail.front().second;
				map[t_r][t_c] = 0;
				tail.pop();
			}
			map[h_r][h_c] = 2;			//머리 늘리기
			t += 1;
		}
		if (op[i].second == 'L') {			//왼쪽으로 가면 dir 인덱스 -1
			d -= 1;
			if (d < 0) d = 3;
		}
		else if (op[i].second == 'D') {		//오른쪽으로 가면 dir 인덱스 +1
			d += 1;
			if (d > 3) d = 0;
		}

	}
	h_r += dir[d][0];
	h_c += dir[d][1];
	tail.push(make_pair(h_r, h_c));
	while (!(h_r >= N || h_c >= N || h_r < 0 || h_c < 0 || map[h_r][h_c] == 2)) {
		h_r += dir[d][0];
		h_c += dir[d][1];
		tail.push(make_pair(h_r, h_c));
		t_r = tail.front().first;
		t_c = tail.front().second;
		map[t_r][t_c] = 0;
		tail.pop();
		t += 1;
	}
	t += 1;
}
int main() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;
		map[r - 1][c - 1] = 1;
	}
	cin >> L;
	int pivot = 0;
	for (int i = 0; i < L; i++) {
		int t;
		char dir_;
		cin >> t >> dir_;
		t = t - pivot;
		op.push_back(make_pair(t, dir_));
		pivot += t;
	}
	map[0][0] = 2;
	gaming(0, 0, 0, 0, 0);
	cout << t;
}