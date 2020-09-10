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
#define N 1005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int t, n;
int a[N];
bool vis[N];
int getgcd(int x, int y) {
	return y==0 ? x : getgcd(y, x%y);
}
int main() {
	cin>>t;
	for (int cas=1; cas <=t ; ++cas) {
		scanf("%d", &n);
		int id;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			if (i==1) id=1;
			else {
				if (a[i] > a[id]) {
					id=i;
				}
			}
		}
		memset(vis, false, sizeof(vis));
		vector<int> ans;
		ans.clear();
		int cg = a[id];
		ans.push_back(a[id]);
		vis[id]=true;
		for (int i = 2; i <= n; ++i) {
			int id2=0;
			int tg=cg;
			for (int j = 1; j <= n; ++j) {
				if (vis[j]) continue;
				int g1=getgcd(cg, a[j]);
				if (id2==0 || g1>tg) {
					id2=j;
					tg=g1;
				}
			}
			ans.push_back(a[id2]);
			vis[id2]=true;
			cg=tg;
		}
		for (int i = 0; i < ans.size(); ++i) {
			printf("%d", ans[i]);
			if (i<ans.size()-1) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
