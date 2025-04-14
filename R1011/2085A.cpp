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
#define N 600005
#define M 10000005
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
    scanf("%d%d", &n, &k);
    string s;
    cin>>s;
    bool found=false;
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[0]) {
            found=true;
            break;
        }
    }
    if (!found) puts("No");
    else {
        int l = 0, r = n-1;
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            if (s[l] < s[r]) {
                ok=true;
                break;
            } else if (s[l] > s[r]) {
                break;
            } else {
                l++;
                r--;
            }
        }
        if (k >= 2) {
            puts("Yes");
        } else if (k == 1) {
            puts("Yes");
        } else {
            if (ok) puts("Yes");
            else puts("No");
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
