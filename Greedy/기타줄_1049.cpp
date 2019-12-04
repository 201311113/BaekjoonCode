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
int t;
int main() {
	int n, m;
	cin >> n >> m;
	int min_package = 1002, min_ind = 1002;
	for (int i = 0; i < m; i++) {		//상품별 가장 값싼 값 변수에 저장
		int a, b;
		cin >> a >> b;
		min_package = min(min_package, a);
		min_ind = min(min_ind, b);
	}
	int pack_cnt = n / 6;	//n/6
	int ind_cnt = n % 6;	//나머지
	pack_cnt *= min_package;
	int pack_cnt2 = pack_cnt + ind_cnt * min_ind;
	if (ind_cnt) pack_cnt += min_package;
	pack_cnt = min(pack_cnt, pack_cnt2);
	min_ind *= n;
	int ans = min(pack_cnt, min_ind);
	cout << ans;
}