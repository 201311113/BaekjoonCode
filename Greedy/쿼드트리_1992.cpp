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
typedef long long ll;
int n;
int map[65][65];
void dfs(int pixel_size, int x, int y) {
	bool flag = 0;
	//cout << pixel_size << " " << x << " " << y << endl;
	int pivot = map[x][y];
	for (int i = y; i < pixel_size + y; i++) {
		for (int j = x; j < pixel_size + x; j++) {
			if (map[j][i] != pivot) {
				cout << '(';
				if (pixel_size == 2) {
					cout << map[x][y] << map[x + 1][y] << map[x][y + 1] << map[x + 1][y + 1];
					cout << ')';
					return;
				}
				
				dfs(pixel_size / 2, x, y);
				dfs(pixel_size / 2, x + pixel_size / 2 , y);
				dfs(pixel_size / 2, x , y + pixel_size / 2);
				dfs(pixel_size / 2, x + pixel_size / 2, y + pixel_size / 2);
				flag = 1;
				cout << ')';
				break;
			}
		}
		if (flag) break;
	}
	if (!flag) cout << pivot;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[j][i]);
		}
	}
	dfs(n, 0, 0);
}