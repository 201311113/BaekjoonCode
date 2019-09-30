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
int cal(int n) {
	int sum = 0;
	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
int main() {
	int n;
	cin >> n;
	string s = to_string(n);
	int min_num = n - (9 * (int)s.size());
	int max_num = n - (int)s.size();
	bool flag = 0;
	int ans;
	for (int i = min_num; i <= max_num; i++) {

		if (n == i + cal(i)) {
			flag = 1;
			ans = i;
			break;
		}
	}
	if (flag) cout << ans;
	else cout << "0";
}