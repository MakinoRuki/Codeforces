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
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (abs(a[i]) == 1) cnt++;
    }
    if (cnt%2) {
      puts("-1");
      continue;
    }
    vector<pair<int,int>> ans;
    ans.clear();
    int i = 1;
    while(i <= n) {
      if (abs(a[i]) == 1) {
        if (i + 1 <= n && abs(a[i+1]) == 1) {
          if (a[i] + a[i+1] == 0) {
            ans.push_back(make_pair(i, i));
            ans.push_back(make_pair(i+1, i+1));
          } else {
            ans.push_back(make_pair(i, i+1));
          }
          i += 2;
        } else {
          int j=i+1;
          while(abs(a[j]) == 0) {
            j++;
          }
          if (a[i] + a[j] == 0) {
            ans.push_back(make_pair(i, i));
            ans.push_back(make_pair(i+1, j-1));
            ans.push_back(make_pair(j, j));
          } else {
            ans.push_back(make_pair(i, i));
            if (i+1<=j-2) ans.push_back(make_pair(i+1, j-2));
            ans.push_back(make_pair(j-1, j));
          }
          i = j+1;
        }
      } else {
        ans.push_back(make_pair(i ,i));
        i++;
      }
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d %d\n", ans[i].first, ans[i].second);
    }
  }
  return 0;
}
