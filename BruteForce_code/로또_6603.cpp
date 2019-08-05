#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int main() {
	int k;
	while (1) {
		cin >> k;
		if (k == 0) break;
		vector<int> a(k);
		vector<int> flag;
		for (int i = 0; i < k; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < 6; i++)
			flag.push_back(0);
		for (int i = 0; i < a.size() - 6; i++)
			flag.push_back(1);
		sort(flag.begin(), flag.end());
		do {
			for (int i = 0; i < flag.size(); i++) {
				if (flag[i] == 0)
					printf("%d ", a[i]);

			}
			printf("\n");
		} while (next_permutation(flag.begin(), flag.end()));
		printf("\n");
	}
}