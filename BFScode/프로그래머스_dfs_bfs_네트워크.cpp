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
bool chk[204];
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	vector<int> connection[203];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (computers[i][j]) {
				connection[i].push_back(j);
				connection[j].push_back(i);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (!chk[i]) {
			queue<int> q;
			q.push(i);
			chk[i] = 1;
			answer++;
			while (!q.empty()) {
				int tmp = q.front();
				q.pop();
				for (int j = 0; j < connection[tmp].size(); j++) {
					if (!chk[connection[tmp][j]]) {
						chk[connection[tmp][j]] = 1;
						q.push(connection[tmp][j]);
					}
				}
			}
		}
	}
	return answer;
}