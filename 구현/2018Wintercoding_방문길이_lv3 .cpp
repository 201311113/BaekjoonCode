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

typedef struct {
	bool e;
	bool w;
	bool s;
	bool n;
}node;
node chk[11][11];
int solution(string dirs)
{
	int answer = 7;
	int x = 5, y = 5;
	int cnt = 0;
	for (int i = 0; i < dirs.size(); i++) {
		if (dirs[i] == 'U') {
			if (chk[x][y].n) {//갔던길이면
				if (y + 1 <= 10) y++;
				continue;
			}
			else {//이동,chk,길카운트
				if (y + 1 <= 10) {
					chk[x][y].n = 1;
					chk[x][y + 1].s = 1;
					cnt++;
					y++;
				}
			}
		}
		else if (dirs[i] == 'D') {
			if (chk[x][y].s) {//갔던길이면
				if (y - 1 >= 0) y--;
				continue;
			}
			else {//이동,chk,길카운트
				if (y - 1 >= 0) {
					chk[x][y].s = 1;
					chk[x][y - 1].n = 1;
					cnt++;
					y--;
				}
			}
		}
		else if (dirs[i] == 'R') {
			if (chk[x][y].e) {//갔던길이면
				if (x + 1 <= 10) {
					x++;
				}
				continue;
			}
			else {//이동,chk,길카운트
				if (x + 1 <= 10) {
					chk[x][y].e = 1;
					chk[x + 1][y].w = 1;
					cnt++;
					x++;
				}
			}
		}
		else if (dirs[i] == 'L') {
			if (chk[x][y].w) {//갔던길이면
				if (x - 1 >= 0) {
					x--;
				}
				continue;
			}
			else {//이동,chk,길카운트
				if (x - 1 >= 0) {
					chk[x][y].w = 1;
					chk[x - 1][y].e = 1;
					cnt++;
					x--;
				}
			}
		}
	}
	answer = cnt;
	return answer;
}
int main() {
	string s;
	cin >> s;
	cout << solution(s);
}