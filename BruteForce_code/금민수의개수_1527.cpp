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
long long A, B;
int cnt = 0;
int bcnt = 0;//--
void dfs(long long n) {
	bcnt++;//-
	if (n > B) return;
	if (n >= A && n <= B) 	cnt++;
	n *= 10;
	dfs((long long)(n + 4));
	dfs((long long)(n + 7));
}
int main() {
	cin >> A >> B;
	dfs(4);
	dfs(7);
	cout << cnt;
}