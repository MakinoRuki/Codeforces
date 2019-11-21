#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1002
using namespace std;
typedef long long ll;
int T;
int n,m;
int a[N];
int main() {
	cin>>T;
	for (int cas = 1; cas <= T; ++cas) {
		cin>>n>>m;
		vector<pair<int, int>> rk;
		int tot=0;
		for (int i = 0; i < n; ++i) {
			cin>>a[i];
			tot += a[i];
			rk.push_back(make_pair(a[i], i));
		}
		if (n == 2) {
			cout<<"-1"<<endl;
			continue;
		}
		if (m < n) {
			cout<<"-1"<<endl;
			continue;
		}
		tot *= 2;
		vector<int> ans;
		for (int i = 0; i < n; ++i) {
			ans.push_back(i);
			ans.push_back((i+1)%n);
		}
		cout<<tot<<endl;
		for (int i = 0; i < ans.size(); i += 2) {
			cout<<ans[i]+1<<" "<<ans[i+1]+1<<endl;
		}
	}
	return 0;
}
