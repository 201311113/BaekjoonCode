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
#include<map>
#include<sstream>
using namespace std;
char arr[51][51];
char cmparr[51][51];

int n, m;
void flip(int x,int y) {
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			if (arr[i][j] == '1') arr[i][j] = '0';
			else arr[i][j] = '1';
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[j][i];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cmparr[j][i];
		}
	}
	int cnt = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (arr[j][i] != cmparr[j][i]) {
				flip(j, i);
				cnt++;
			}
		}
	}
	bool flag = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[j][i] != cmparr[j][i]) {
				flag = 0;
				break;
			}
		}
	}
	
	if (flag) {
		cout << cnt;
	}
	else {
		cout << -1;
	}
}