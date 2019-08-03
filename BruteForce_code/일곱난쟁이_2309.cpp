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
int main() {
	int arr[10], lie1, lie2;
	for (int i = 0; i < 9; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + 9);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int sum = 0;
			if (i == j) continue;
			for (int k = 0; k < 9; k++) {
				if (k == i || k == j) continue;
				sum += arr[k];
			}
			if (sum == 100) {
				lie1 = i;
				lie2 = j;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		if (i == lie1 || i == lie2) continue;
		printf("%d\n", arr[i]);
	}
}