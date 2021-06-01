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
#define M 25
#define N 2002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, q;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		vector<int> es, os;
		es.clear();
		os.clear();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			if (a[i] % 2) os.push_back(a[i]);
			else es.push_back(a[i]);
		}
		for (int i = 0; i < es.size(); ++i) {
			os.push_back(es[i]);
		}
		for (int i = 0; i < os.size(); ++i) {
			printf("%d", os[i]);
			if (i < os.size()-1) cout<<" ";
			else cout<<endl;
		}
	}
  return 0;
}
