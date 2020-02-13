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
ll d[102];
ll arr[100002];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	d[1] = 1;
	d[2] = 1;
	d[3] = 1;
	for (int i = 4; i <= 100; i++) {
		d[i] = d[i - 3] + d[i - 2];
	}
	for (int i = 0; i < n; i++) {
		cout << d[arr[i]] << endl;
	}
}