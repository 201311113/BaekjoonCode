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
long long n, m;
long long jewel[300001];
int main() {
	cin >> n >> m;
	long long max_num = 0;
	for (int i = 0; i < m; i++) {
		cin >> jewel[i];
		max_num += jewel[i];
	}
	long long f = 1, l = max_num;
	long long ans = 1000000001;
	while (f <= l) {
		long long mid = (f + l) / 2;	//보석나눠주는 개수
		long long total = 0;	//사람수
		for (int i = 0; i < m; i++) {
			total += jewel[i] / mid;
			if (jewel[i] % mid != 0) total++;
		}
		if (total > n) {
			f = mid + 1;
		}
		else {
			if (mid < ans) ans = mid;
			l = mid - 1;
		}
	}
	cout << ans;
}