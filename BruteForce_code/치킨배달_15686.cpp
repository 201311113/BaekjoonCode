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
bool chk[51];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
int min_distance = 123456789;

void dfs(int idx, int cnt) {				//cnt는 살린 치킨가게수
	if (idx > chicken.size()) return;
	if (cnt == M) {
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			int ind_min_dis = 123456789;
			for (int j = 0; j < chicken.size(); j++) {
				if (chk[j] == 1) {
					int ind_dis;
					ind_dis = abs(chicken[j].first - house[i].first) + abs(chicken[j].second - house[i].second);
					ind_min_dis = min(ind_min_dis, ind_dis);
				}
			}
			sum += ind_min_dis;
		}
		min_distance = min(min_distance, sum);
	}
	chk[idx] = 1;
	dfs(idx + 1, cnt + 1);
	chk[idx] = 0;
	dfs(idx + 1, cnt);
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[j][i];
			if (map[j][i] == 2) {
				chicken.push_back(make_pair(j, i));
			}
			else if (map[j][i] == 1) {
				house.push_back(make_pair(j, i));
			}
		}
	}
	dfs(0, 0);
	cout << min_distance;
}