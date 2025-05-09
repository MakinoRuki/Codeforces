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
#define M 63
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
int mx[N], mn[N];
ll sum[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    int n0=0,n1=0;
    int w1=-1,wn=-1,wn2=-1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') {
            n0++;
            if (i==0) w1=0;
            if (i==n-1) wn=0;
            if (i==n-2) wn2=0;
        } else {
            n1++;
            if (i==0) w1=1;
            if (i==n-1) wn=1;
            if (i==n-2) wn2=1;
        }
    }
    if (wn==w1) {
        if (wn==0) puts("Alice");
        else puts("Bob");
    } else {
        if ((wn==0) && (w1==1)) {
            if (wn2==1) puts("Bob");
            else {
                puts("Alice");
            }
        } else {
            if (wn2 == 0) {
                if (n1==1) {
                    puts("Alice");
                } else {
                    puts("Bob");
                }
            } else {
                puts("Bob");
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
