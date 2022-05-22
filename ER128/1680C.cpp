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
#define N 300005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m;
int t;
int cnt[2][N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    vector<int> ids;
    ids.clear();
    n = (int)s.size();
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '0') {
        ids.push_back(i);
      }
    }
    if (ids.empty()) {
      puts("0");
      continue;
    }
    for (int i = 0; i <= n; ++i) {
      cnt[0][i] = 0;
      cnt[1][i] = 0;
    }
    for (int i = 0; i < n; ++i) {
      if (i > 0) cnt[0][i] += cnt[0][i-1];
      if (s[i] == '1') cnt[0][i]++;
    }
    for (int i = n-1; i >= 0; --i) {
      if (i < n-1) cnt[1][i] += cnt[1][i+1];
      if (s[i] == '1') cnt[1][i]++;
    }
    int l = 0, r = (int)ids.size();
    int n1 = (n-(int)ids.size());
    while(l < r) {
      int mid = (l+r)/2;
   //   cout<<l<<" "<<r<<" "<<mid<<endl;
      bool ok = false;
      if (mid == 0) {
        
        for (int i = 0; i < ids.size(); ++i) {
          if (i == 0) {
            if (n1-ids[i] <= mid) {
              ok=true;
              break;
            }
          }
          if (i == ids.size()-1) {
            if (n1-(n-1-ids[i]) <= mid) {
              ok=true;
              break;
            }
          }
          if (i + 1 < ids.size()) {
            if (n1-(ids[i+1]-ids[i]-1) <= mid) {
              ok=true;
              break;
            }
          }
        }
        if (ok) {
          r=mid;
        } else {
          l=mid+1;
        }
        continue;
      }
      
      int i;
      for (i = 0; i < ids.size(); ++i) {
        int j = i+mid-1;
        if (j >= ids.size()) break;
        int dt = 0;
        if (i > 0) dt += cnt[0][ids[i-1]];
        if (j < ids.size()-1) dt += cnt[1][ids[j+1]];
        if (dt <= mid) {
          ok=true;
          break;
        }
      }
      if (ok) {
        r = mid;
      } else {
        l = mid+1;
      }
    }
    printf("%d\n", r);
  }
  return 0;
}
