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
#include<sstream>
using namespace std;
char map[52][52];
bool col[51], row[51];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		bool flag = 0;
		for (int j = 0; j < m; j++) {
			cin >> map[j][i];
			if (map[j][i] == 'X') {
				col[j] = 1;
				row[i] = 1;
			}
		}
	}
	int row_cnt = 0, col_cnt = 0;
	for (int i = 0; i < m; i++) {
		if (!col[i]) col_cnt++;
	}
	for (int j = 0; j < n; j++) {
		if (!row[j]) row_cnt++;
	}
	int ans = max(row_cnt, col_cnt);
	cout << ans;
}