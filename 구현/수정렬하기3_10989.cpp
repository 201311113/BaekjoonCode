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
#include<map>
#include<sstream>
using namespace std;
typedef long long ll;
int arr[10020];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		arr[num]++;
	}
	for (int i = 1; i < 10001; i++) {
		if (arr[i] == 0) continue;
		while (arr[i]--) {
			printf("%d\n", i);
		}
	}
}