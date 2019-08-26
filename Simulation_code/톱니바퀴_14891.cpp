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
using namespace std;
int Gear[4][8];
int k;
void mv_Gear(int Gnum, int dir) {
	if (dir > 0) {
		int tmp = Gear[Gnum - 1][7];
		for (int i = 7; i > 0; i--) {
			Gear[Gnum - 1][i] = Gear[Gnum - 1][i - 1];
		}
		Gear[Gnum - 1][0] = tmp;
	}
	else {
		int tmp = Gear[Gnum - 1][0];
		for (int i = 0; i < 7; i++) {
			Gear[Gnum - 1][i] = Gear[Gnum - 1][i + 1];
		}
		Gear[Gnum - 1][7] = tmp;
	}
}
void cal_Gear(int Gnum, int dir) {
	int Gdir[4] = { 0, };
	Gdir[Gnum - 1] = dir;
	int tGnum = Gnum - 2;
	int tdir = dir * -1;
	while (tGnum >= 0) {
		if (Gear[tGnum][2] != Gear[tGnum + 1][6]) {
			Gdir[tGnum] = tdir;
			tdir *= -1;
			tGnum -= 1;
		}
		else break;
	}
	tGnum = Gnum;
	tdir = dir * -1;
	while (tGnum < 4) {
		if (Gear[tGnum][6] != Gear[tGnum - 1][2]) {
			Gdir[tGnum] = tdir;
			tdir *= -1;
			tGnum += 1;
		}
		else break;
	}
	for (int i = 0; i < 4; i++) {
		if (Gdir[i] != 0)
			mv_Gear(i + 1, Gdir[i]);
	}
}
int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &Gear[i][j]);
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int Gnum, dir;
		cin >> Gnum >> dir;
		cal_Gear(Gnum, dir);
	}
	int pivot = 1, sum = 0;
	for (int i = 0; i < 4; i++) {
		if (Gear[i][0] == 1) {
			sum += pivot;
		}
		pivot *= 2;
	}
	cout << sum << endl;
}