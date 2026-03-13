
#include <iostream>
#include <sstream>
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
#define N 3000005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod1 = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
ll b[N];
ll c[N];
int lowbit(int x) {
  return x&(-x);
}
bool check(int x) {
  int pw=0;
  while((1<<pw) <= x) pw++;
  pw--;
  if ((1<<pw) == x) return true;
 // if (x == (1<<pw)-1) return pw;
  return false;
}
// bool check2() {
//   bool ok=true;
//   for (int i = 1; i < n; ++i) {
//     int j;
//     for (j = i; j <= n; ++j) {
//       if (a[j] == (a[i] ^ i)) break;
//     }
//     if (j > n) return false;
//   }
//   return true;
// }
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
 // cin>>x;
 // cout<<lowbit(6)<<endl;

  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    if (check(n)) {
      puts("-1");
    } else {
      a[n] = 1;
      set<int> ss;
      ss.clear();
      for (int i = 2; i <= n; ++i) {
        ss.insert(i);
      }
      for (int i = n-1; i > 1; --i) {
        a[i] = i ^ 1;
        ss.erase(a[i]);
      }
      a[1] = *ss.begin();
      if ((a[1]^1) > n || (a[1]^1) < 1) {
        int x = lowbit(n);
        int id;
        for (int i = 2; i < n; ++i) {
          if (a[i] == x) {
            id = i;
            break;
          }
        }
        swap(a[1], a[id]);
      }
      for (int i =1 ; i <= n; ++i) {
        printf("%d ", a[i]);
      }
      cout<<endl;
    }
    //int pw= check(n);
    // if (pw < 0) puts("-1");
    // else {
    //   a[n] = (1<<pw)-1;
    //   for (int i = 1; i < n; ++i) {
    //     a[i] = (1<<pw)-1-i;
    //     printf("%d ", a[i]);
    //   }
    //   printf("%d\n", a[n]);
    // }
  }

  // cin>>n;
  // for (int i= 1; i <= n; ++i) {
  //   a[i]=i;
  // }
  // do {
  //   if (check2()) {
  //     for (int i = 1; i <= n; ++i) {
  //       printf("%d ", a[i]);
  //     }
  //     cout<<endl;
  //   }
  // } while(next_permutation(a+1, a+n+1));
  return 0;
}

