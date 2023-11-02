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
#define N 300005
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    if (a[n] == 1) {
      puts("NO");
      continue;
    }
    vector<pair<int,int>> v;
    v.clear();
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
      if (i == 1 || a[i] == a[i-1]) {
        cnt++;
      } else {
        v.push_back(make_pair(a[i-1], cnt));
        cnt=1;
      }
    }
    if (cnt > 0) {
      v.push_back(make_pair(a[n], cnt));
    }
    puts("YES");
    int i = v.size()-1;
    while(i >= 0) {
      if (i-1>=0) {
        int tot = v[i-1].second + v[i].second;
        for (int j = 1; j < tot; ++j) {
          printf("0 ");
        }
        printf("%d ", v[i-1].second);
        i -= 2;
      } else {
        for (int j = 1; j <= v[i].second; ++j) {
          printf("0 ");
        }
        i--;
      }
    }
    cout<<endl;
  }
  return 0;
}
