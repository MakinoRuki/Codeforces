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
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    int ns=-1,np=n+1;
    int cs=0,cp=0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 's') {
            ns = max(ns, i);
            if (i > 0 && i < n-1) cs++;
        }
        if (s[i] == 'p') {
            np = min(np, i);
            if (i > 0 && i < n-1) cp++;
        }
    }
    if (ns < 0 && np > n) {
        puts("YES");
    } else if (ns >= 0 && np > n) {
        puts("YES");
    } else if (ns < 0 && np <= n) {
        puts("YES");
    } else {
        if (ns > np) {
            puts("NO");
        } else {
            if (cs > 0 && cp > 0) {
                puts("NO");
            } else {
                puts("YES");
            }
        }
    }
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

