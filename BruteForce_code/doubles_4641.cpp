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
int arr[16];
int main() {
	while (1) {
		int n;
		for (int i = 0; i < 16; i++) {
			cin >> arr[i];
			n = i;
			if (i == 0 && arr[i] == -1) return 0;
			else if (arr[i] == 0) break;
		}
		sort(arr, arr + n);

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int left = 0, right = n;
			int mid;
			while (left < right) {
				mid = (left + right) / 2;
				if (arr[i] * 2 < arr[mid]) {
					right = mid;
				}
				else if (arr[i] * 2 == arr[mid]) {
					cnt++;
					break;
				}
				else {
					left = mid + 1;
				}
			}
		}
		cout << cnt << endl;
	}
}