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
int n;
int arr[4] = { 2,3,5,7 };
int inum[4] = { 1,3,7,9 };
bool chk(int num) {
	for (int i = 2; i * i < num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}
void dfs(int tmp, int cnt) {
	if (cnt == n) {
		cout << tmp<<endl;
		return;
	}
	tmp *= 10;
	for (int i = 0; i < 4; i++) {//1379¸¸¿Ã¼ö 
		if (chk(tmp+inum[i])) {
			dfs(tmp + inum[i], cnt + 1);
		}
	}
}
int main() {
	cin >> n;

	for (int i = 0; i < 4; i++) {
		dfs(arr[i],1);
	}
}