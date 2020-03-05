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
typedef long long ll;
int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	if (x > w && y > h) {
		cout<<sqrt(pow(x - w, 2) + pow(y - h, 2));
		return 0;
	}
	else if (x >= w && y <= h) {
		cout << x - w;
		return 0;
	}
	else if (x <= w && y >= h) {
		cout << y - h;
		return 0;
	}
	else if (x < w && y < h) {
		int case_1 = x, case_2 = y, case_3 = w - x, case_4 = h - y;
		int min_num=123456789;
		min_num = min(min_num, case_1);
		min_num = min(min_num, case_2);
		min_num = min(min_num, case_3);
		min_num = min(min_num, case_4);
		cout << min_num;
		return 0;
	}
}