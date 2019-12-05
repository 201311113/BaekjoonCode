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
int map[502][502];
int main() {
	int n;
	cin >> n;
	int movie = 666;
	int cnt = 1;

	while (cnt != n) {
		movie++;
		int tmp = movie;
		int cnt6 = 0;
		while (tmp) {
			if (cnt6 == 3) break;
			int tmp_num = tmp % 10;
			tmp /= 10;
			if (tmp_num == 6) {
				cnt6++;
			}
			else {
				cnt6 = 0;
			}
		}
		if (cnt6 >= 3) cnt++;
	}
	cout << movie;

}