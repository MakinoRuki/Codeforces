#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 1005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int t;
int a,b;
int main() {
 cin>>t;
 for (int cas=1; cas<=t; ++cas) {
   scanf("%d%d", &a, &b);
   set<int> ss;
   ss.clear();
   int c=a+b;
   if (c%2) {
     int d1 = c/2;
     int d2 = c-d1;
     for (int i = 0; i <= min(d1, a); ++i) {
        if (d1-i<=b) {
          ss.insert(b-(d1-i)+i);
        }
     }
     d1 = c/2+1;
     d2 = c-d1;
     for (int i = 0; i <= min(d1, a); ++i) {
        if (d1-i<=b) {
          ss.insert(b-(d1-i)+i);
        }
     }
   } else {
      int d = c/2;
      for (int i = 0; i <= min(d, a); ++i) {
        if (d-i<=b) {
          ss.insert(b-(d-i)+i);
        }
     }
   }
   printf("%d\n", (int)ss.size());
   vector<int> res(ss.begin(), ss.end());
   for (int i = 0; i < res.size(); ++i) {
    printf("%d", res[i]);
    if (i < res.size()-1) cout<<" ";
    else cout<<endl;
   }
 }
 return 0;
}
