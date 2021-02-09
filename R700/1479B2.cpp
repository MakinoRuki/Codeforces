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
#define M 21
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int q;
int t, n, m;
int a[N];
int b[N];
int id[N];
int pre[N];
int nxt[N];
int main() {
	cin>>n;
	for (int i =1 ; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	vector<pair<int,int>> sgs;
	sgs.clear();
	vector<int> v1, v2;
	v1.clear();
	v2.clear();
	int cnt=0;
	for (int i = 1; i <= n; ++i) {
		// if (i == 1 || a[i] == a[i-1]) {
		// 	cnt++;
		// } else {
		// 	sgs.push_back(make_pair(a[i-1], cnt));
		// 	cnt = 1;
		// }
		if (i == 1 || a[i] != a[i-1]) {
			b[++cnt] = a[i];
		}
	}
	memset(pre, -1, sizeof(pre));
	memset(nxt, -1, sizeof(nxt));
	for (int i = 1; i <= cnt; ++i) {
		if (pre[b[i]] >= 0) {
			nxt[pre[b[i]]] = i;
			pre[b[i]] = i;
		} else {
			pre[b[i]] = i;
		}
	}
	v1.push_back(1);
	for (int i = 2; i <= cnt; ++i) {
		int num = b[i];
		if (v1.empty()) {
			v1.push_back(i);
		} else if (v2.empty()) {
			v2.push_back(i);
		} else {
			if (num == b[v1.back()]) {
				v1.push_back(i);
			} else if (num == b[v2.back()]) {
				v2.push_back(i);
			} else {
				int id1 = nxt[v1.back()];
				int id2 = nxt[v2.back()];
				if (id1<0) v1.push_back(i);
				else if (id2 < 0) v2.push_back(i);
				else {
					if (id1<id2) v2.push_back(i);
					else v1.push_back(i);
				}
			}
		}
	}
	int tot=0;
	for (int i = 0; i < v1.size(); ++i) {
		if (i == 0 || b[v1[i]] != b[v1[i-1]]) {
			tot++;
		}
	}
	for (int i = 0; i <v2.size(); ++i) {
		if (i==0 || b[v2[i]] != b[v2[i-1]]) {
			tot++;
		}
	}
	printf("%d\n", tot);
  return 0;
}
