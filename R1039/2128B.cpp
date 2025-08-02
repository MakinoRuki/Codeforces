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
#define M 5002
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
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    int l = 2, r = n;
    string ans="L";
    int pre=1;
    while(l < r) {
       // cout<<"lr="<<l<<" "<<r<<endl;
        if (a[l] > a[pre] && a[r] > a[pre]) {
            if (a[l] > a[r]) {
                ans += "LR";
                pre=l;
            } else {
                ans += "RL";
                pre=r;
            }
        } else if (a[l] < a[pre] && a[r] < a[pre]) {
            if (a[l] > a[r]) {
                ans += "RL";
                pre=r;
            } else {
                ans += "LR";
                pre=l;
            }
        } else {
            ans += "LR";
            pre=l;
        }
        l++;
        r--;
    }
    if (l == r) {
        ans += "L";
    }
    cout<<ans<<endl;
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
