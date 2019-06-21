#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int k;
int main() {
	cin>>k;
	int i;
	for (i = 5; i * i <= k; ++i) {
		if ((k % i == 0) && (k / i >= 5)) {
			break;
		}
	}
	if (i * i > k) {
		cout<<-1<<endl;
	} else {
		vector<string> ans;
		ans.clear();
		int r = i;
		int c = k / i;
		for (int j = 0; j < r; ++j) {
			ans.push_back(string(c, 'a'));
		}
		for (int i = 0; i < r; ++i) {
			if (i == 0) {
				ans[i][0] = 'a';
				ans[i][1] = 'e';
				ans[i][2] = 'i';
				ans[i][3] = 'o';
				ans[i][4] = 'u';
			} else {
				for (int j = 0; j < 4; ++j) {
					ans[i][j] = ans[i - 1][j + 1];
				}
				ans[i][4] = ans[i-1][0];
			}
		}
		for (int j = 5; j < c; ++j) {
			if (j == 5) {
				ans[0][j] = 'a';
				ans[1][j] = 'e';
				ans[2][j] = 'i';
				ans[3][j] = 'o';
				ans[4][j] = 'u';
			} else {
				for (int i = 0; i < 4; ++i) {
					ans[i][j] = ans[i + 1][j - 1];
				}
				ans[4][j] = ans[0][j - 1];
			}
		}
		string res = "";
		for (int i = 0; i < r; ++i) {
			res += ans[i];
		}
		cout<<res<<endl;
	}
	return 0;
}
