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
using namespace std;
int N, M;
int map[51][51];
int px, py;
int max_ans = 0;
void dfs(int cnt, int pivot, int x, int y) {
	if (cnt == 3 && map[x][y] == pivot) {
		int xx = (abs(px - x) + 1); int yy = (abs(py - y) + 1);
		if (xx != yy) return;
		int tmp = xx * yy;
		max_ans = max(max_ans, tmp);
	}

	if (cnt == 1) {	//가로 검사
		for (int i = px + 1; i < M; i++) {
			if (map[i][py] == pivot) {
				dfs(cnt + 1, pivot, i, y);
			}
		}
	}
	else if (cnt == 2) {//세로 검사
		for (int i = py + 1; i < N; i++) {
			if (map[px][i] == pivot) {
				dfs(cnt + 1, pivot, x, i);
			}
		}
	}


}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[j][i]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			px = j, py = i;
			dfs(1, map[j][i], 0, 0);
		}
	}
	if (max_ans == 0) cout << "1";
	else
		cout << max_ans << endl;
}