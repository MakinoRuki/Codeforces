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
#define N 500005
#define M 15
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int ans[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<pair<int,int>> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      v.push_back(make_pair(a[i], i));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    bool ok=true;
    for (int i = v[0].first+1; i <= n; ++i) {
      if (v[i-1].first != 0) {
        ok=false;
        break;
      }
    }
    for (int i = v[0].first+1; i <= n; ++i) {
      int id = v[i-1].second;
      ans[id] = -n;
    }
    int l = 1, r = v[0].first;
    if (!ok) {
      puts("NO");
      continue;
    }
    int cur=v[l-1].first;
    while(l <= r) {
    //  cout<<"lr="<<l<<" "<<r<<" "<<v[l-1].first<<" "<<v[l-2].first<<endl;
      if ((l == 1) || (v[l-1].first == v[l-2].first)) {
        ans[v[l-1].second] = cur;
        l++;
      } else {
        int dt = v[l-2].first - v[l-1].first;
      //  cout<<"dt="<<dt<<endl;
        for (int i = 1; i <= dt; ++i) {
          --cur;
          ans[v[r-1].second]= -cur;
        //  cout<<"id="<<v[r-1].second<<" "<<-cur<<endl;
          if (cur <= 0) {
            ok=false;
            break;
          }
          r--;
        }
        if (!ok) break;
        if (l <= r) {
          ans[v[l-1].second] = --cur;
          if (cur <= 0) {
            ok=false;
            break;
          }
          l++;
        }
      }
    }
    if (!ok) {
      puts("NO");
      continue;
    }
    v.clear();
    for (int i =1; i <= n; ++i) {
      v.push_back(make_pair(ans[i], i));
    }
    sort(v.begin(), v.end());
    r = (int)v.size();
    for (int i = 0; i < v.size(); ++i) {
      while(r >= 1 && v[i].first + v[r-1].first > 0) {
        r--;
      }
      if (n-r != a[v[i].second]) {
        ok=false;
        break;
      }
    }
    if (ok) {
      puts("YES");
      for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
      }
      cout<<endl;
    } else {
      puts("NO");
    }
  }
  return 0;
}
