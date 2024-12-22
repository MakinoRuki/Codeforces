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
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    int n0=0,n1=0;
    vector<pair<int,int>> v;
    v.clear();
    int b=-1,e=-1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 0) {
            n0++;
            if (b>0) {
                v.push_back(make_pair(b,e));
                b=-1,e=-1;
            }
        }
        else if (a[i]!=0) {
            n1++;
            if (b<0) b=i;
            e = i;
        }
    }
    if (b>0) {
        v.push_back(make_pair(b,e));
    }
    if (n0==n) {
        puts("0");
    } else if (n1==n) {
        puts("1");
    } else {
        if ((int)v.size()<=1) puts("1");
        else puts("2");
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

