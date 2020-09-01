#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 200
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int t, n;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		int tot=0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			tot+=a[i];
		}
		int pre=-1;
		set<pair<int,int>> ss;
		for (int i = 1; i <= n; ++i) {
			ss.insert(make_pair(-a[i], i));
		}
		int cur=0;
		for (int i = tot; i >= 1; --i) {
			if (ss.empty()) {
				break;
			}
			auto top=*ss.begin();
			ss.erase(top);
			int x=top.first;
			int id=top.second;
			a[id]--;
			if (pre>0 && a[pre] > 0) {
				ss.insert(make_pair(-a[pre], pre));
			}
			pre = id;
			cur = !cur;
		}
		if (cur) {
			cout<<"T"<<endl;
		} else {
			cout<<"HL"<<endl;
		}
	}
	return 0;
}
