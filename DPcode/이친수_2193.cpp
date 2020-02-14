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
ll d[92];
int main() {
	int n;
	cin >> n;
	d[1] = 1;
	d[2] = 1;
	d[3] = 2;
	for (int i = 4; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}
	cout << d[n];
}