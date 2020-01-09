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
typedef long long ll;
int main() {
	int n;
	cin >> n;
	int ans = 0;
	int tmp = n;
	ans += tmp / 5;
	bool flag = 0;
	while (ans != -1) {
		if ((n - ans * 5) % 3 == 0) {
			ans += (n - ans * 5) / 3;
			flag = 1;
			break;
		}
		else {
			ans--;
		}
	}
	if (flag)
		cout << ans;
	else cout << -1;
}