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

int main() {
	int a[6], min1, min2, min3;
	long long N, n1, n2, n3 = 4, sum = 0;
	cin >> N;
	for (int i = 0; i < 6; ++i) cin >> a[i];

	if (N == 1) {
		sort(a, a + 6);
		for (int i = 0; i < 5; ++i) sum += a[i];
	}
	else {
		a[0] = min(a[0], a[5]);
		a[1] = min(a[1], a[4]);
		a[2] = min(a[2], a[3]);
		sort(a, a + 3);
		min3 = a[0] + a[1] + a[2];
		min2 = a[0] + a[1];
		min1 = a[0];

		n1 = (N - 1) * (N - 2) * 4 + (N - 2) * (N - 2);
		n2 = (N - 1) * 4 + (N - 2) * 4;

		sum += n1 * min1;
		sum += n2 * min2;
		sum += n3 * min3;
	}
	cout << sum << endl;
	return 0;
}