#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int main() {
	cin>>n;
	string s;
	cin>>s;
	int maxd = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') cnt++;
		else cnt--;
		maxd = max(maxd, cnt);
	}
	int b = (maxd+1)/2;
	int r = maxd-b;
	int nb = 0;
	int nr = 0;
	string ans = "";
	vector<int> stk;
	stk.clear();
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			if (nb < b) {
				nb++;
				ans += "0";
				stk.push_back(0);
			} else {
				nr++;
				ans += "1";
				stk.push_back(1);
			}
		} else {
			if (stk.back() == 0) {
				nb--;
				ans += "0";
			} else {
				nr--;
				ans += "1";
			}
			stk.pop_back();
		}
	}
	cout<<ans<<endl;
	return 0;
}
