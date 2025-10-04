
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
#define N 600005
#define M 305
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
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int l, r;
    scanf("%d%d", &n, &m);
    string s;
    cin>>s;
    set<int> ss;
    ss.clear();
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &a[i]);
      ss.insert(a[i]);
    }
    int cur=1;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'A') {
        cur++;
        if (ss.find(cur) == ss.end()) {
          ss.insert(cur);
        }
      } else {
        cur++;
        while(ss.find(cur) != ss.end()) {
          cur++;
        }
        ss.insert(cur);
        while(ss.find(cur) != ss.end()) {
          cur++;
        }
      }
    }
    int sz=(int)ss.size();
    printf("%d\n", sz);
    for (auto x : ss) {
      printf("%d ", x);
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
