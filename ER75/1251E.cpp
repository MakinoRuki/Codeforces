#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#define N 200005
using namespace std;
typedef long long ll;
int t;
int n;
vector<int> cnt[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		for (int i = 0; i < n; ++i) {
			cnt[i].clear();
		}
		for (int i = 0; i < n; ++i) {
			int m, p;
			cin>>m>>p;
			cnt[m].push_back(p);
		}
		int pre = n;
		int buy = 0;
		ll tot=0LL;
		set<pair<int, int>> ss;
		ss.clear();
		int id = 0;
		for (int i = n-1; i >= 0; --i) {
		//	cout<<"i="<<i<<endl;
			pre -= cnt[i].size();
			for (int j = 0; j < cnt[i].size(); ++j) {
				ss.insert(make_pair(cnt[i][j], id++));
			}
		//	cout<<i<<" "<<pre<<" "<<buy<<endl;
			if (pre + buy < i) {
				int det = i - pre - buy;
			//	if (i == n-1) cout<<"det="<<det<<endl;
				while(det-->0) {
					int cur=(*ss.begin()).first;
					ss.erase(*ss.begin());
					tot += (ll)cur;
					buy++;
				}
			}
		}
		cout<<tot<<endl;
	}
	return 0;
}
