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
#define N 100005
#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
string a, b;
int par[30];
bool vis[30];
int find(int u) {
	return u==par[u] ? u : par[u] = find(par[u]);
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>a>>b;
		for (int i = 0; i < 26; ++i) {
			par[i] = i;
			vis[i] = false;
		}
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			if (a[i] > b[i]) {
				ok = false;
				break;
			} else {
				int ca = a[i]-'a';
				int cb = b[i]-'a';
				vis[ca] = true;
				vis[cb] = true;
				int pa = find(ca);
				int pb = find(cb);
				if (pa != pb) {
					par[pa] = pb;
				}
			}
		}
		if (!ok) cout<<-1<<endl;
		else {
			int tot=0;
			int cnt=0;
			for (int i = 0; i < 26; ++i) {
				par[i] = find(i);
				if (vis[i]) {
					tot++;
					if (par[i]==i) {
						cnt++;
					}
				}
			}
			cout<<tot-cnt<<endl;
		}
	}
  return 0;
}
