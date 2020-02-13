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
int d[10002];
int arr[10002];
int n;
int main() {		//d[n] = max(d[n-2] + arr[n], d[n-3] + arr[n-1] + arr[n]);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	d[1] = arr[1];
	d[2] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		d[i] = max(d[i - 2] + arr[i], d[i - 3] + arr[i] + arr[i - 1]);
		d[i] = max(d[i], d[i - 1]);
	}
	cout << d[n];
}