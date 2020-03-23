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
int n, m;
vector<int> carbin[20020];
bool chk[20020];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		carbin[a].push_back(b);
		carbin[b].push_back(a);
	}
	queue<pair<int,int>> q;
	q.push({1,0});
	int max_dis = 0;
	int max_cnt = 0;
	int ans = -1;
	chk[1] = 1;
	while (!q.empty()) {
		int tmp = q.front().first,cnt=q.front().second;
		q.pop();
		for (int i = 0; i < carbin[tmp].size(); i++) {
			if (!chk[carbin[tmp][i]]) {
				q.push({ carbin[tmp][i],cnt + 1 });
				if (max_dis < cnt + 1) {
					max_cnt = 1;
					max_dis = cnt + 1;
					ans = carbin[tmp][i];
				}
				else if (max_dis == cnt + 1) {
					max_cnt++;
					if (carbin[tmp][i] < ans) ans = carbin[tmp][i];
				}
				
				chk[carbin[tmp][i]] = 1;
			}
		}
	}
	cout << ans << " " << max_dis << " " << max_cnt << endl;
}