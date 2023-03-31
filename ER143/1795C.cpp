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
#define N 200005
#define M 520
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int d;
int a[N];
int b[N];
ll cnt[N];
ll sum[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cnt[i] = 0;
    }
    for (int i =1; i <= n; ++i) {
      scanf("%d", &b[i]);
      sum[i] = sum[i-1] + (ll)b[i];
    }
    vector<pair<int, int>> sg;
    sg.clear();
    for (int i = 1; i <= n; ++i) {
      int l = i, r = n;
      if (b[i] > a[i]) {
        cnt[i] += a[i];
        continue;
      }
      while(l < r) {
        int mid = (l+r+1)/2;
        if (sum[mid] - sum[i-1] <= a[i]) {
          l = mid;
        } else {
          r = mid-1;
        }
      }
     // cout<<"i="<<i<<" "<<r<<endl;
      if (sum[r]-sum[i-1] == a[i]) {
        sg.push_back(make_pair(i, r));
      } else {
        ll dt = 0LL;
        sg.push_back(make_pair(i, r));
        dt += sum[r]-sum[i-1];
        if (r + 1 <= n) {
          cnt[r+1] += a[i]-dt;
        }
      }
    }
    // for (int i = 1; i <= n; ++i) {
    //   cout<<"i2="<<i<<" "<<cnt[i]<<endl;
    // }
    sort(sg.begin(), sg.end());
    int j= 0;
    set<pair<int,int>> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      while(j < sg.size() && sg[j].first <= i) {
        ss.insert(make_pair(sg[j].second, j));
        j++;
      }
      while(!ss.empty() && (*ss.begin()).first < i) {
        ss.erase(ss.begin());
      }
      int sz = (int)ss.size();
      cnt[i] += (ll)sz * (ll)b[i];
    }
    for (int i = 1; i <= n; ++i) {
      printf("%lld", cnt[i]);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
