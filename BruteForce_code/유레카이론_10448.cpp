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
int T, N;
int trinum[46];
bool chk[46];
bool flag = 0;
void dfs(int num, int cnt) {
	if (cnt == 3 && N == num) {
		flag = 1;
		return;
	}
	if (cnt > 3) return;
	for (int i = 0; i < 45; i++) {
		if (num + trinum[i] > N) break;
		dfs(num + trinum[i], cnt + 1);
	}
}
int main() {
	cin >> T;
	int s = 0, i = 1;
	while (s <= 1000) {
		s += i;
		trinum[i - 1] = s;
		i++;
	}

	while (T--) {
		flag = 0;
		cin >> N;
		dfs(0, 0);
		if (flag) cout << "1" << endl;
		else cout << "0" << endl;
	}
}