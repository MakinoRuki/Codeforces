#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 20005
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int a[N];
int nxt[N], pre[N];
int len[N];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	memset(nxt, -1, sizeof(nxt));
	memset(pre, -1, sizeof(pre));
	memset(len, 0, sizeof(len));
	int pp=-1;
	for (int i = 1; i <= n; ++i) {
		if (i==1 || a[i]!=a[i-1]) {
			pre[i]=pp;
			if (pp>0) {
				len[pp]=i-pp;
				nxt[pp]=i;
			}
			pp=i;
		}
	}
	len[pp]=n+1-pp;
	set<pair<int,int>> ss;
	ss.clear();
	int ans=0;
	for (int i = 1; i <= n; ++i) {
		if (len[i]>0) {
			ss.insert(make_pair(-len[i], i));
		}
	}
	while(!ss.empty()) {
		auto pr=*ss.begin();
		ss.erase(pr);
		int id=pr.second;
		int ll=-pr.first;
		ans++;
		if (pre[id]<0) {
			if (nxt[id]<0) continue;
			int id2=nxt[id];
			pre[id2]=-1;
		} else {
			if (nxt[id]<0) {
				nxt[pre[id]]=-1;
			} else {
				int id2=pre[id];
				int id3=nxt[id];
				if (a[id2]==a[id3]) {
					ss.erase(make_pair(-len[id2],id2));
					ss.erase(make_pair(-len[id3],id3));
					nxt[id2]=nxt[id3];
					if (nxt[id3]>0) {
						pre[nxt[id3]]=id2;
					}
					len[id2] += len[id3];
					ss.insert(make_pair(-len[id2], id2));
				} else {
					pre[id3]=id2;
					nxt[id2]=id3;
				}
			}
		}
		// cout<<ans<<endl;
		// for (auto itr : ss) {
		// 	cout<<itr.second<<" "<<(-itr.first)<<endl;
		// }
	}
	cout<<ans<<endl;
	return 0;
}
