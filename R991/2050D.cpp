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
#define N 500005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m;
int k;
int t;
int a[N];
int bit[N];
set<int> ids[20];
int lowbit(int x) {
    return x&(-x);
}
void update(int x) {
    while(x <= n) {
        bit[x]++;
        x+=lowbit(x);
    }
}
int query(int x) {
    int res=0;
    while(x) {
        res += bit[x];
        x -= lowbit(x);
    }
    return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    n = (int)s.size();
    for (int i = 0; i <= n; ++i) {
        bit[i] = 0;
    }
    string ans="";
    for (int i = 0; i <= 10; ++i) {
        ids[i].clear();
    }
    int n0=0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            n0++;
            ids[s[i]-'0'].insert(i+1);
        } else ids[s[i]-'0'].insert(i+1);
    }
    for (int i = 1; i <= n; ++i) {
      //  cout<<"i="<<i<<endl;
        int mx=-1,x=-1;
        if (!ids[0].empty()) {
            auto z = *ids[0].begin();
            z += query(n)-query(z);
            if (z == i) {
                mx = 0;
                x = 0;
            }
        }
        for (int j = 1; j <= 9; ++j) {
          //  cout<<"j="<<j<<endl;
            if (!ids[j].empty()) {
                auto z = *ids[j].begin();
                z += query(n)-query(z);
                if (j-(z-i) > mx) {
                    mx = j-(z-i);
                    x = j;
                }
            }
        }
        if (x < 0) {
            ans += "0";
            n0--;
            continue;
        }
        ans.push_back(mx + '0');
        update(*ids[x].begin());
        ids[x].erase(ids[x].begin());
       // cout<<"i2="<<i<<endl;
    }
    n0 = (int)ids[0].size();
    for (int i = 1; i <= n0; ++i) {
        ans += "0";
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
