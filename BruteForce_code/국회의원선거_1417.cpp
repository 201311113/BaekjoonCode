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
int n;
int mem[1001];
int me;
int main() {
	cin >> n;
	cin >> me;
	for (int i = 0; i < n - 1; i++) {
		cin >> mem[i];
	}
	sort(mem, mem + n - 1);
	reverse(mem, mem + n - 1);
	int cnt = 0;
	while (1) {
		if (me > mem[0]) {
			break;
		}
		--mem[0];
		++me;
		cnt++;
		for (int i = 0; i < n - 2; i++) {
			if (mem[i] < mem[i + 1]) {
				int tmp = mem[i];
				mem[i] = mem[i + 1];
				mem[i + 1] = tmp;
			}
			else break;
		}
	}
	cout << cnt;
}