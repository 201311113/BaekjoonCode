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
int n, m;//n=학생,m=관계
int cnt = 0;
vector<int> Friend[1002];
vector<int> Enemy[1002];
bool chk[1003];
void dfs(int node) {
	chk[node] = 1;
	for (int i = 0; i < Friend[node].size(); i++) {
		if (!chk[Friend[node][i]]) {
			dfs(Friend[node][i]);
		}
	}
	for (int i = 0; i < Enemy[node].size(); i++) {
		int e_node = Enemy[node][i];
		for (int j = 0; j < Enemy[e_node].size(); j++) {
			if (!chk[Enemy[e_node][j]]) {
				dfs(Enemy[e_node][j]);
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {//관계 입력
		char c;
		cin >> c;
		if (c == 'F') {
			int a, b;
			cin >> a >> b;
			Friend[a].push_back(b);
			Friend[b].push_back(a);
		}
		else {
			int a, b;
			cin >> a >> b;
			Enemy[a].push_back(b);
			Enemy[b].push_back(a);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!chk[i]) {
			cnt++;
			dfs(i);
		}
	}
	cout << cnt;
}