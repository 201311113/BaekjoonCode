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
int arr[21][21];
bool chk[21];
int N;
int min_ans = 123456789;
int cal() {
	int ta = 0, tb = 0;
	vector<int> TA, TB;
	for (int i = 0; i < N; i++) {
		if (chk[i]) TA.push_back(i);
		else TB.push_back(i);
	}
	for (int i = 0; i < TA.size(); i++) {
		for (int j = 0; j < TA.size(); j++) {
			if (i == j) continue;
			ta += arr[TA[i]][TA[j]];
		}
	}
	for (int i = 0; i < TB.size(); i++) {
		for (int j = 0; j < TB.size(); j++) {
			if (i == j) continue;
			tb += arr[TB[i]][TB[j]];
		}
	}
	return abs(ta - tb);
}
void dfs(int idx, int cnt) {
	if (cnt == N / 2) {// 팀원 다구성
		min_ans = min(min_ans, cal());
		return;
	}
	if (cnt > N / 2) return;//오류시 종료
	for (int i = idx + 1; i < N; i++) {
		chk[i] = 1;
		dfs(i, cnt + 1);
		chk[i] = 0;
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[j][i];
		}
	}
	for (int i = 0; i < N / 2; i++) {
		chk[i] = 1;
		dfs(i, 1);
		chk[i] = 0;
	}
	cout << min_ans;
}