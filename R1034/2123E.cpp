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
#include <random>
#include <ctime>
#include <list>
#include <stack>
#include <bitset>
#include <chrono>
#define N 500005
#define M 1002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int cnt[N];
int ans[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int j,k;
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i) {
      cnt[i]=0;
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
    }
    int mex=0;
    for (int i = 0; i <= n; ++i) {
      if (cnt[i] == 0) {
        mex=i;
        break;
      }
    }
    set<pair<int,int>> ss;
    ss.clear();
    int cur=0;
    for (int i = n; i >= 0; --i) {
      while(cur <= n-i && cur < mex) {
        if (cnt[cur]>0) {
          ss.insert(make_pair(cnt[cur], cur));
        }
        cur++;
      }
      while(!ss.empty()) {
        auto itr=*ss.rbegin();
        if (itr.first > i) {
          ss.erase(itr);
        } else {
          break;
        }
      }
      int sz=(int)ss.size();
      ans[i] = sz;
      if (mex <= n-i && cnt[mex]<=i) {
        ans[i]++;
      }
    }
    for (int i = 0; i <= n; ++i) {
      printf("%d ", ans[i]);
    }
    cout<<endl;
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
