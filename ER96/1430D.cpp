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
int t,n,k;
int a[N];
string s;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		cin>>s;
		set<pair<int,int>> ss;
		ss.clear();
		int id=0;
		int cnt=0;
		vector<int> vs(n, 0);
		for (int i = 0; i < n; ++i) {
			if (i==0) {
				id=0;
				cnt++;
			} else {
				if (s[i]==s[i-1]) {
					cnt++;
				} else {
					ss.insert(make_pair(-cnt, id));
					vs[id] = cnt;
					id=i;
					cnt=1;
				}
			}
		}
		if (cnt) {
			ss.insert(make_pair(-cnt, id));
			vs[id]=cnt;
		}
		int ans=0;
		int p1=0,p2=0;
		while(true) {
			while(p1<n && vs[p1]<2) {
				p1++;
			}
			if (p1<n) {
				ans++;
				vs[p1]--;
				while(p2<n && !vs[p2]) {
					p2++;
				}
				vs[p2] = 0;
			} else {
				while(p2<n && !vs[p2]) {
					p2++;
				}
				if (p2>=n) {
					break;
				}
				ans++;
				vs[p2]--;
				while(p2<n && !vs[p2]) {
					p2++;
				}
				if (p2>=n) break;
				vs[p2]=0;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
