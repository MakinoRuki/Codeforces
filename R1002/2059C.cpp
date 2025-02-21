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
#define N 200005
#define M 310
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
int a[M][M];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        scanf("%d", &a[i][j]);
      }
    }
    vector<int> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
      int sum=0;
      for (int j = n; j >= 1; --j) {
        if (a[i][j]==1) sum++;
        else break;
      }
      if (sum) v.push_back(sum);
    }
    sort(v.begin(), v.end());
    int cur=1;
    for (int i = 0; i < v.size(); ++i) {
    //  cout<<"i="<<i<<" "<<v[i]<<endl;
      if (cur >= n) break;
      if (v[i] >= cur) {
        cur++;
      }
    }
    printf("%d\n", min(cur,n));
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
