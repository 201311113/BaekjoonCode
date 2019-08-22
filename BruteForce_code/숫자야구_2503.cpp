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
struct node {
	string n;
	int strike;
	int ball;
};
int N;
node game_info[101];
int cnt = 0;
void dfs(string num) {
	if (num >= "988") return;
	if (num[0] == num[1] || num[1] == num[2] || num[0] == num[2]);//같은 숫자 있으면 재끼고
	else {
		bool flag = 1;
		for (int i = 0; i < N; i++) {		//gameinfo만큼
			int tmps = 0, tmpb = 0;
			for (int j = 0; j < 3; j++) {	//현재 num각자리 비교
				for (int k = 0; k < 3; k++) {//gameinfo[i]의 각자리 비교
					if (num[j] == game_info[i].n[k]) {
						if (j == k) {//스트라잌
							++tmps;
						}
						else {//볼
							++tmpb;
						}
					}
				}
			}
			if (tmps == game_info[i].strike && tmpb == game_info[i].ball) continue;
			else {
				flag = 0;
				break;
			}
		}
		if (flag) cnt++;
	}
	for (int i = 2; i >= 0; i--) {
		++num[i];
		if (num[i] - '9' > 0) {
			num[i] = '1';
		}
		else {
			break;
		}
	}
	dfs(num);
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string num;
		int  s, b;
		cin >> num >> s >> b;
		game_info[i].n = num;
		game_info[i].strike = s;
		game_info[i].ball = b;
	}
	dfs("123");
	cout << cnt;
}