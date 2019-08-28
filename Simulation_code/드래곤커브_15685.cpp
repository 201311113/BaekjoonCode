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
int map[101][101];
int dir[4][2] = { {1,0},{0,-1},{-1,0},{0,1} };
void check_dir(int x, int y, int d, int g) {
	vector<int> op;

	op.push_back(d);	//0技措 规氢 历厘
	while (g--) {
		vector<int> top;
		for (int i = 0; i < op.size(); i++) {			//规氢蔼 历厘
			int res;
			res = (op[i] + 1) % 4;
			top.push_back(res);
		}
		reverse(top.begin(), top.end());
		op.insert(op.end(), top.begin(), top.end());
	}
	map[x][y] = 1;
	for (int i = 0; i < op.size(); i++) {
		if (op[i] == 0 && x + dir[0][0] <= 100) {
			x = x + dir[0][0];
			map[x][y] = 1;
		}
		else if (op[i] == 1 && y + dir[1][1] >= 0) {
			y = y + dir[1][1];
			map[x][y] = 1;
		}
		else if (op[i] == 2 && x + dir[2][0] >= 0) {
			x = x + dir[2][0];
			map[x][y] = 1;
		}
		else if (op[i] == 3 && y + dir[3][1] <= 100) {
			y = y + dir[3][1];
			map[x][y] = 1;
		}
	}
}
int main() {					//0=悼率 1=合率 2=辑率 3=巢率
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		check_dir(x, y, d, g);
	}
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1) {
				cnt++;
			}
		}
	}
	cout << cnt;
}