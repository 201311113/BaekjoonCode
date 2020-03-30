#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
vector<int> arr;
int ans = 0;
void dfs(int idx, int sum, int n, int k) {
	if (sum == k) {
		ans++;
		return;
	}
	if (sum > k) return;
	for (int i = idx + 1; i < n; i++) {
		dfs(i, sum + arr[i], n, k);
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		arr.clear();
		int n, k;
		cin >> n >> k;
		ans = 0;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			arr.push_back(num);
		}
		sort(arr.begin(), arr.end());
		for (int i = 0; i < n; i++) {
			dfs(i, arr[i], n, k);
		}
		cout << "#" << test_case << " " << ans << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}