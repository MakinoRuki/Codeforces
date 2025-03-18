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
#define M 750
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
ll a[N];
int nxt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x;
    scanf("%d", &n);
    vector<vector<int>> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
        string s1,s2;
        cin>>s1;
        int x,y;
        scanf("%d", &x);
        cin>>s2;
        scanf("%d", &y);
        int op1=0,op2=0;
        if (s1=="x") op1=1;
        if (s2=="x") op2=1;
        vector<int> tmp = {op1, x, op2, y};
        v.push_back(tmp);
    }
    ll n1=1,n2=1;
    nxt[n+1]=0;
    for (int i = n; i >= 1; --i) {
        nxt[i] = 0;
        if (i+1<=n) nxt[i] = nxt[i+1];
        if ((v[i-1][0] == 0) && (v[i-1][2] == 0)) {
            continue;
        } else if (v[i-1][0] && v[i-1][2]) {
            if (v[i-1][1] > v[i-1][3]) {
                nxt[i] = 1;
            } else if (v[i-1][1] < v[i-1][3]) {
                nxt[i] = 2;
            }
        } else {
            if (v[i-1][0]) {
                nxt[i] = 1;
            } else {
                nxt[i] = 2;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        ll dt = 0;
        if (v[i-1][0]) {
            dt += (v[i-1][1]-1)*n1;
        } else {
            dt += v[i-1][1];
        }
        if (v[i-1][2]) {
            dt += (v[i-1][3]-1)*n2;
        } else {
            dt += v[i-1][3];
        }
        if (nxt[i+1] == 1) n1 += dt;
        else n2 += dt;
        // cout<<"i="<<i<<" "<<n1<<" "<<n2<<endl;
        // cout<<nxt[i]<<endl;
    }
    printf("%lld\n", n1+n2);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
