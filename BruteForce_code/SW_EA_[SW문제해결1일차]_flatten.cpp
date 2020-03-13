#include<iostream>
#include<algorithm>
using namespace std;
int arr_h[103];
int main(int argc, char** argv)
{
	int test_case;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int dump_num;
		cin >> dump_num;
		for (int i = 0; i < 100; i++) {
			cin >> arr_h[i];
		}
		sort(arr_h, arr_h + 100);
		while (dump_num--) {
			if (arr_h[99] == arr_h[0]) break;
			arr_h[99]--;
			arr_h[0]++;
			for (int i = 99; i >= 1; i--) {
				if (arr_h[i - 1] > arr_h[i]) {
					int ttmp = arr_h[i - 1];
					arr_h[i - 1] = arr_h[i];
					arr_h[i] = ttmp;
				}
				else break;
			}
			for (int i = 0; i < 99; i++) {
				if (arr_h[i] > arr_h[i + 1]) {
					int ttmp = arr_h[i];
					arr_h[i] = arr_h[i + 1];
					arr_h[i + 1] = ttmp;
				}
				else break;
			}
		}
		cout << "#" << test_case << " " << arr_h[99] - arr_h[0] << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}