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
int n, m;
int map[101][101];
long long cal(int x1, int x2, int y1, int y2) {
	long long sum = 0;
	for (int i = y1; i <= y2; i++) {
		for (int j = x1; j <= x2; j++) {
			sum += map[j][i];
		}
	}
	return sum;
}
int main() {
	cin >> n >> m;
	long long max_num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[j][i]);
		}
	}
	if (m >= 3) {//세로방향 3등분
		for (int i = 0; i < m - 2; i++) {
			for (int j = i + 1; j < m - 1; j++) {
				long long a, b, c;
				a = cal(0, i, 0, n - 1);
				b = cal(i + 1, j, 0, n - 1);
				c = cal(j + 1, m - 1, 0, n - 1);
				if (max_num < a * b * c) {
					max_num = a * b * c;
				}
			}
		}
	}
	if (n >= 3) {//가로방향 3등분
		for (int i = 0; i < n - 2; i++) {
			for (int j = i + 1; j < n - 1; j++) {
				long long a, b, c;
				a = cal(0, m - 1, 0, i);
				b = cal(0, m - 1, i + 1, j);
				c = cal(0, m - 1, j + 1, n - 1);
				if (max_num < a * b * c) {
					max_num = a * b * c;
				}
			}
		}
	}
	if (n >= 2 && m >= 2) {//21 세로방향
		for (int i = 0; i < n - 1; i++) {//세로 이분의일 보장
			for (int j = 0; j < m - 1; j++) {//가로 이분의일 보장
				long long a, b, c;
				a = cal(0, m - 1, i + 1, n - 1);
				b = cal(0, j, 0, i);
				c = cal(j + 1, m - 1, 0, i);
				if (max_num < a * b * c) {
					max_num = a * b * c;
				}
				a = cal(0, m - 1, 0, i);
				b = cal(0, j, i + 1, n - 1);
				c = cal(j + 1, m - 1, i + 1, n - 1);
				if (max_num < a * b * c) {
					max_num = a * b * c;
				}
				a = cal(0, j, 0, i);
				b = cal(0, j, i + 1, n - 1);
				c = cal(j + 1, m - 1, 0, n - 1);
				if (max_num < a * b * c) {
					max_num = a * b * c;
				}
				a = cal(0, j, 0, n - 1);
				b = cal(j + 1, m - 1, 0, i);
				c = cal(j + 1, m - 1, i + 1, n - 1);
				if (max_num < a * b * c) {
					max_num = a * b * c;
				}
			}
		}
	}
	cout << max_num;
}