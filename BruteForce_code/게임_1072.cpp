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
long long Z, cnt = 0;
long long X, Y;
int main() {
	cin >> X >> Y;
	Z = 100 * Y / X;
	int tmpz;
	if (Z >= 99) {
		cout << "-1";
		return 0;
	}
	long long f, l, mid = 0;
	f = 0;
	l = 1000000000;
	while (f <= l) {

		mid = (f + l) / 2;
		tmpz = 100 * (Y + mid) / (X + mid);
		if (tmpz > Z) {
			l = mid - 1;
		}
		else {
			f = mid + 1;
		}
	}
	cout << f;
}