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
#include <random>
#define eps 1e-7
#define M 21
#define N 20000
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int k;
int a[N];
int cnt[1000005];
int main() {
  cin>>t;
  memset(cnt, 0, sizeof(cnt));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= 2*n; ++i) {
    	scanf("%d", &a[i]);
    }
    sort(a+1, a+2*n+1);
    int x;
    vector<pair<int,int>> ans;
    ans.clear();
    for (int i = 1; i < 2*n; ++i) {
    	x=a[i]+a[2*n];
    	bool vis[N];
    	for (int j = 1; j <= 2*n; ++j) {
    		vis[j] = false;
    		cnt[a[j]]++;
    	}
    	int k;
    	for (k = 2*n; k >= 1; --k) {
    		if (cnt[a[k]]>0) {
    			cnt[a[k]]--;
    			if (cnt[x-a[k]]>0) {
    				ans.push_back(make_pair(a[k], x-a[k]));
    				cnt[x-a[k]]--;
    				x = max(a[k], x-a[k]);
    			} else {
    				break;
    			}
    		}
    	}
    	if (k>=1) {
    		ans.clear();
    		for (int j = 1; j <= 2*n; ++j) {
    			if (cnt[a[j]]>0) cnt[a[j]] = 0;
    		}
    		continue;
    	}
    	x=a[i]+a[2*n];
    	break;
    }
    if (ans.empty()) {
    	cout<<"NO"<<endl;
    } else {
    	cout<<"YES"<<endl;
    	printf("%d\n", x);
    	for (int i = 0; i < ans.size(); ++i) {
    		printf("%d %d\n", ans[i].first, ans[i].second);
    	}
    }
  }
  return 0;
}
