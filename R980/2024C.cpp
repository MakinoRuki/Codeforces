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
#define N 500005
#define M 325
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<pair<int,int>> v;
    v.clear();
    for (int i =1; i <= n; ++i) {
      int x,y;
      scanf("%d%d", &x, &y);
      v.push_back(make_pair(x,y));
    }
    sort(v.begin(), v.end(), [](const pair<int,int>& x, const pair<int,int>& y) {
      int n1 = (x.first > y.first) + (x.first > y.second) + (x.second > y.first) + (x.second > y.second);
      int n2 = (y.first > x.first) + (y.first > x.second) + (y.second > x.first) + (y.second > x.second);
      if (n1==n2) {
        return max(x.first, x.second) <= max(y.first, y.second);
      }
      return n1<n2;
    });
    for (int i = 0; i < v.size(); ++i) {
      printf("%d %d ", v[i].first, v[i].second);
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

