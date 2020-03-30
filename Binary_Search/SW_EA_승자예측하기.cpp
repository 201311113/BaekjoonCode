#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		long long N;
		scanf("%lld", &N);
		int cnt = 0;
		long long tmp = 1;
		string ans;
		if (N == 1) 		printf("#%d Bob\n", test_case);
		else if (N == 2 || N == 3) printf("#%d Alice\n", test_case);
		else {
			int cnt = 2;
			long long tmp = 4;
			while (1) {
				if (N >= tmp && N < (tmp << 1)) {
					break;
				}
				tmp = tmp << 1;
				cnt++;
			}
			if (cnt % 2) {
				long long x = 1;
				for (int i = 1; i <= cnt; i++) {
					if (i % 2) x = x << 1;
					else x = (x << 1) + 1;
				}
				if (x <= N) {
					printf("#%d Alice\n", test_case);
				}
				else {
					printf("#%d Bob\n", test_case);
				}
			}
			else {
				long long x = 1;
				for (int i = 1; i <= cnt; i++) {
					if (i % 2) x = (x << 1) + 1;
					else x = x << 1;
				}
				if (x <= N) {
					printf("#%d Bob\n", test_case);
				}
				else {
					printf("#%d Alice\n", test_case);
				}
			}
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}