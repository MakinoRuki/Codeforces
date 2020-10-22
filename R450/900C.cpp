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
#define N 100002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n,m,k;
int a,b,c;
int p[N];
int cnt[N];
bool ok[N];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &p[i]);
	}
	set<int> ss;
	ss.clear();
	memset(cnt, 0, sizeof(cnt));
	memset(ok, false, sizeof(ok));
	int tot=0;
	for (int i = 1; i <= n; ++i) {
		if (ss.empty()) {
			tot++;
			ok[i]=true;
		} else {
			auto itr=ss.upper_bound(p[i]);
			if (itr==ss.end()) {
				tot++;
				ok[i]=true;
			} else {
				auto itr2=itr;
				itr2++;
				if (itr2 == ss.end()) {
					cnt[*itr]++;
				}
			}
		}
		ss.insert(p[i]);
	}
	int id=-1;
	int maxv=-1;
	for (int i = 1; i <= n; ++i) {
		if (ok[i]) {
			int res=tot-1+cnt[p[i]];
			if (res>maxv) {
				maxv=res;
				id=p[i];
			} else if (res==maxv && p[i]<id) {
				id=p[i];
			}
		} else {
			int res=tot+cnt[p[i]];
			if (res>maxv) {
				maxv=res;
				id=p[i];
			} else if (res==maxv && p[i]<id) {
				id=p[i];
			}
		}
	}
	cout<<id<<endl;
	return 0;
}
