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
int cal(int a, int max_dec, int cnt, int max_dec_cnt) {
	if (max_dec_cnt == 0) return cnt;
	if (max_dec_cnt < 0) return -1;
	int temp_num;
	temp_num = a - max_dec + 1;
	cnt += temp_num * max_dec_cnt;
	cal(max_dec - 1, max_dec / 10, cnt, max_dec_cnt - 1);
}
int main() {
	int a, max_dec, max_dec_cnt = 1, cnt;
	cin >> a;						//먼저 자릿수를 알고 
	for (int i = 10;; i *= 10) {
		if (a / i == 0) {
			max_dec = i / 10;
			break;
		}
		max_dec_cnt++;
	}
	cnt = cal(a, max_dec, 0, max_dec_cnt);
	cout << cnt << endl;
}