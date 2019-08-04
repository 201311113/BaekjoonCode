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
using namespace std;							//https://www.acmicpc.net/problem/14501
vector<pair<int, int>> arr(17);
int max_ = 0;
void cal(int value_, int day_, int retire) {
	if (retire < day_) return;
	if (retire == day_) {
		if (max_ < value_) max_ = value_;
		return;
	}
	cal(value_, day_ + 1, retire);
	cal(value_ + arr[day_].second, day_ + arr[day_].first, retire);
	return;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t, p;
		cin >> t >> p;
		arr[i].first = t;
		arr[i].second = p;
	}
	cal(0, 0, n);
	cout << max_ << endl;
}