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
int n, m;
int main() {
	cin >> n >> m;
	if (n == 1 || n == 5) printf("%lld", 8LL * m + (n == 5) * 4);
	else cout << 4LL * m + 1 + (m & 1 ? 4 - n : n - 2);
	return 0;
}