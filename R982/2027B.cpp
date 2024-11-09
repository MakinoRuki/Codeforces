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
#define M 405
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, p;
int t;
int a[N];
vector<pair<int,int>> wh;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<int> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int ans= n;
    for (int i = 1; i <= n; ++i) {
      v.clear();
      int tmp = i-1;
      v.push_back(a[i]);
      for (int j = i+1; j <= n; ++j) {
        if (a[j] < v.back()) {
          continue;
        } else if (a[j] == v.back()) {
          v.push_back(a[j]);
        } else {
          tmp++;
        }
      }
      ans = min(ans, tmp);
    }
    printf("%d\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
