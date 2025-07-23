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
#define N 1000005
#define M 1002
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
int b[N];
int mx[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
    }
    for (int i = n; i >= 1; --i) {
        mx[i] = i;
        if (i + 1 <= n && a[mx[i+1]] > a[i]) {
            mx[i] = mx[i+1];
        }
    }
    set<pair<int,int>> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
        ss.insert(make_pair(b[i], i+n));
    }
    int ans=0;
    for (int i = 1; i <= n; ++i) {
        ss.insert(make_pair(a[i], i));
        auto pr = *ss.begin();
        if (pr.second > n) {
            ans = i;
        } else {
            ss.erase(pr);
            if (i+1 <= n) {
                int id = mx[i+1];
               // if (i == 4) cout<<"id="<<id<<endl;
                ss.insert(make_pair(a[id], id));
                auto pr2 = *ss.begin();
            //    if (i==4) cout<<"pr2="<<pr2.first<<" "<<pr2.second<<endl;
                if (pr2.second > n) {
                    ans = i;
                }
                ss.erase(make_pair(a[id], id));
                ss.insert(pr);
            }
        }
        ss.erase(make_pair(b[n+1-i], n+1-i+n));
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
