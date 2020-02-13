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
int d[1010];
int arr[1010];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	d[1] = 1;
	for (int i = 2; i <= n; i++) {
		int max_cnt = 0;
		for (int j = i - 1; j >=0; j--) {
			if (arr[j] < arr[i]) {
				if (max_cnt < d[j]) max_cnt = d[j];
			}
		}
		d[i] = max_cnt + 1;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < d[i]) ans = d[i];
	}
	cout << ans;
}