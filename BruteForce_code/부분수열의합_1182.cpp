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
using namespace std;
int arr[21];
int cnt = 0;
void cal(int sum, int idx, int N, int S, int prv) {
	if (idx == N && sum != S) {
		return;
	}
	if (idx == N && sum == S) {
		if (prv == N);
		else	cnt += 1;
		return;
	}

	for (int i = idx; i < N; i++) {
		cal(sum + arr[i], i + 1, N, S, prv);
		cal(sum, i + 1, N, S, prv + 1);
		return;
	}
}
int main() {
	int N, S;
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	cal(0, 0, N, S, 0);
	cout << cnt << endl;
}