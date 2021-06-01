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
#include <time.h>
#define eps 1e-7
#define M 52
#define N 60
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= 2*n; ++i) {
			scanf("%d", &a[i]);
		}
		sort(a+1, a+2*n+1);
		int pos = (1+2*n)/2;
		vector<int> ans;
		ans.clear();
		ans.push_back(a[pos]);
		for (int i = 1; i <= pos-1; ++i) {
			ans.push_back(a[pos+i]);
			ans.push_back(a[pos-i]);
		}
		ans.push_back(a[2*n]);
		for (int i = 0; i < ans.size(); ++i) {
			printf("%d", ans[i]);
			if (i < ans.size()-1) cout<<" ";
			else cout<<endl;
		}
	}
  return 0;
}
