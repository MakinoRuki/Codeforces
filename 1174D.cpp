// 转化成前缀xor
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
int main() {
	int n, x;
	cin>>n>>x;
	int ans[1000000];
	int cnt = 0;
	if (x >= (1<<n)) {
		for (int i = 1; i < (1<<n); ++i) {
			ans[cnt++] = i;
		}
	} else {
		set<int> xs;
		xs.clear();
		for (int i = 1; i < (1<<n); ++i) {
			if (i == x) continue;
			if (xs.find(i) == xs.end()) {
				ans[cnt++] = i;
				xs.insert(x ^ i);
			}
		}
	}
	for (int i = cnt - 1; i > 0; --i) {
		ans[i] = ans[i-1] ^ ans[i];
	}
	cout<<cnt<<endl;
	for (int i = 0; i < cnt; ++i) {
		cout<<ans[i];
		if (i < cnt - 1)cout<<" ";
		else cout<<endl;
	}
	return 0;
}
