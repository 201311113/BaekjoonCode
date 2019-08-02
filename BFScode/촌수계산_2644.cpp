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
int N, A, B, M;
vector<int> c_p[101];
vector<int> p_c[101];
bool chk[101];
bool flag = 0;
int ans = 0;
void dfs(int tmp, int degree) {
	if (tmp == B) {
		flag = 1;
		ans = degree;
		return;
	}
	if (chk[tmp]) {
		return;
	}
	if (!c_p[tmp].empty()) {
		chk[tmp] = 1;
		dfs(c_p[tmp][0], degree + 1);
	}
	if (!p_c[tmp].empty()) {
		for (int i = 0; i < p_c[tmp].size(); i++) {
			chk[tmp] = 1;
			dfs(p_c[tmp][i], degree + 1);

		}
	}
}
int main() {
	cin >> N >> A >> B >> M;
	for (int i = 0; i < M; i++) {
		int c, p;
		cin >> p >> c;
		c_p[c].push_back(p);
		p_c[p].push_back(c);
	}
	dfs(A, 0);
	if (flag)
		cout << ans;
	else
		cout << "-1";
}