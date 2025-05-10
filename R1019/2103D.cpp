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
#define N 3000005
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
vector<int> ids[N];
int ans[N];
int nxt[N];
int pre[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <=n; ++i) {
        ids[i].clear();
        scanf("%d", &a[i]);
    }
    vector<int> stk;
    stk.clear();
    for (int i = 1; i <= n; ++i) {
        nxt[i]=n+1;
        pre[i]=0;
    }
    for (int i = 1; i <= n; ++i) {
        while(!stk.empty() && (a[stk.back()]!=-1) &&(a[i] > a[stk.back()] || a[i]<0)) {
            int id = stk.back();
            nxt[id]=i;
            stk.pop_back();
        }
        stk.push_back(i);
    }
    stk.clear();
    for (int i = n; i >= 1; --i) {
        while(!stk.empty() && (a[stk.back()]!=-1) && (a[i]>a[stk.back()] || a[i]<0)) {
            int id = stk.back();
            pre[id]=i;
            stk.pop_back();
        }
        stk.push_back(i);
    }
    int id0=-1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] < 0) {
            id0 = i;
        } else {
            ids[a[i]].push_back(i);
        }
    }
    int l=1,r=n;
    int cur=1;
    while(!ids[cur].empty()) {
        if (cur&1) {
            int bd=0;
            if (pre[ids[cur][0]]<=0) {
                bd = 1;
                while(bd < ids[cur].size() && nxt[ids[cur][bd-1]] > ids[cur][bd]) {
                    bd++;
                }
                int l1 = 0,r1=bd-1;
                while(l1<r1) {
                    swap(ids[cur][l1], ids[cur][r1]);
                    l1++;
                    r1--;
                }
            }
            for (int i = ids[cur].size()-1; i >= 0; --i) {
                ans[ids[cur][i]] = r--;
            }
        } else {
            int sz=(int)ids[cur].size();
            if (nxt[ids[cur][sz-1]] > n) {
                int bd = sz-2;
                while(bd >= 0 && pre[ids[cur][bd+1]] < ids[cur][bd]) {
                    bd--;
                }
                int l1=bd+1,r1=sz-1;
                while(l1<r1) {
                    swap(ids[cur][l1], ids[cur][r1]);
                    l1++;
                    r1--;
                }
            }
            for (int i = 0; i < ids[cur].size(); ++i) {
                ans[ids[cur][i]] = l++;
            }
        }
        cur++;
    }
    ans[id0] = r;
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    cout<<endl;
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
