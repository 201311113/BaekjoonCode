#include<iostream>
#include<cstring>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		string x;
		cin >> n >> x;
		long long sum = 0;
		for (int i = x.size() - 1; i >= 0; i--) {
			int num = x[i] - '0';
			sum += num;
		}
		cout << "#" << test_case << " " << sum % (n - 1) << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}