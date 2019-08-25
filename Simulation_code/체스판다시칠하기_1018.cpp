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
char map[51][51];
int min_ans = 123456789;
int chk_map(int x, int y) {
	char pivot = 'B';
	int bcnt = 0;
	for (int i = y; i < 8 + y; i++) {	//B로시작 W로 시작 두개를 해야대는지?시간복잡도 2배로
		for (int j = x; j < 8 + x; j++) {
			if (pivot != map[j][i]) bcnt++;
			if (pivot == 'B') pivot = 'W';
			else if (pivot == 'W') pivot = 'B';
		}
		if (pivot == 'B') pivot = 'W';
		else if (pivot == 'W') pivot = 'B';
	}
	pivot = 'W';
	int wcnt = 0;
	for (int i = y; i < 8 + y; i++) {
		for (int j = x; j < 8 + x; j++) {
			if (pivot != map[j][i])wcnt++;
			if (pivot == 'B') pivot = 'W';
			else if (pivot == 'W') pivot = 'B';
		}
		if (pivot == 'B') pivot = 'W';
		else if (pivot == 'W') pivot = 'B';
	}
	return min(bcnt, wcnt);
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[j][i];
		}
	}
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			min_ans = min(min_ans, chk_map(j, i));
		}
	}
	cout << min_ans;
}