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
#define M 202
#define N 510
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
vector<pair<int,int>> ans1;
vector<int> ans2;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    map<int, int> cnt;
    cnt.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
    }
    bool ok = true;
    for (auto itr : cnt) {
      if (itr.second % 2) {
        ok=false;
        break;
      }
    }
    if (!ok) {
      puts("-1");
      continue;
    }
    ans1.clear();
    ans2.clear();
    int m = n;
    int tot=0;
    for (int i = 1; i <= n/2; ++i) {
      int j;
      for (j = 2; j <= m; ++j) {
        if (a[j] == a[1]) {
          break;
        }
      }
      if (j == 2) {
        ans2.push_back(2);
        tot += 2;
        for (int j2 = 3; j2 <= m; ++j2) {
          a[j2-2] = a[j2];
        }
        m -= 2;
      } else {
        int len = j - 2;
        for (int j2 = 0; j2 < len; ++j2) {
          ans1.push_back(make_pair(tot + j + j2, a[2+j2]));
        }
        ans2.push_back(2 * (j-1));
        tot += 2 * (j-1);
        for (int j2 = 2; j2 < j; ++j2) {
          a[j2 - 1] = a[j2];
        }
        int l = 1, r = len;
        while(l < r) {
          swap(a[l], a[r]);
          l++;
          r--;
        }
        for (int j2 = j + 1; j2 <= m; ++j2) {
          a[j2 - 2] = a[j2];
        }
        m -= 2;
      }
    }
    printf("%d\n", (int)ans1.size());
    for (int i = 0; i < ans1.size(); ++i) {
      printf("%d %d\n", ans1[i].first, ans1[i].second);
    }
    printf("%d\n", (int)ans2.size());
    for (int i = 0; i < ans2.size(); ++i) {
      printf("%d", ans2[i]);
      if (i < ans2.size()-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
