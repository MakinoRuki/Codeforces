
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
#define M 50
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const ll mod3 = 1000003;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x,y;
    scanf("%d%d", &n,&k);
    set<int> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      ss.insert(a[i]);
    }
  //  cout<<"nk="<<n<<" "<<k<<endl;
    int v = 0;
    for (int i = 1; i <= n; ++i) {
      if (ss.find(i) == ss.end()) {
        v = i;
        break;
      }
    }
    if (v != 0) {
      a[n+1] = v;
      for (int i = 2; i <= k; ++i) {
        int v2;
        for (v2=1;v2<=3; ++v2) {
          if (a[n+i-1] != v2 && a[n+i-2] != v2) {
            break;
          }
        }
        a[n+i] = v2;
      }
    } else {
      for (int i = 1; i <= k; ++i) {
        a[n+i] = a[i];
      }
    }
    for (int i =1; i <= k; ++i) {
      printf("%d ", a[n+i]);
    }
    cout<<endl;
  }
  return 0;
}
