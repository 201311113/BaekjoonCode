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
int N, A, B;
vector<int> v;
bool flag = 0;
int final_roundnum = 0;
void dfs(int round_num, vector<int>& vec) {
	if (vec.size() == 1 || flag) {
		return;
	}
	vector<int> vec2;
	int vec_last = 0;
	if (vec.size() % 2 == 1) {
		vec_last = vec[vec.size() - 1];
	}
	for (int i = 0; i < vec.size() - 1; i += 2) {
		if ((vec[i] == A && vec[i + 1] == B) || (vec[i] == B && vec[i + 1] == A)) {
			final_roundnum = round_num;
			flag = 1;
		}
		if (vec[i] == A || vec[i + 1] == A) {
			vec2.push_back(A);
		}
		else if (vec[i] == B || vec[i + 1] == B) {
			vec2.push_back(B);
		}
		else {
			vec2.push_back(vec[i]);
		}
	}
	if (vec.size() % 2 == 1) {
		vec2.push_back(vec_last);
	}
	dfs(round_num + 1, vec2);
}
int main() {
	cin >> N >> A >> B;
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}
	dfs(1, v);
	if (flag) {
		cout << final_roundnum;
	}
	else {
		cout << "-1";
	}

}