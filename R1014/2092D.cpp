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
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    int nt=0,ni=0,nl=0;
    for (int i = 0; i < n; ++i) {
        if (s[i]=='T')nt++;
        if (s[i]=='L')nl++;
        if (s[i]=='I')ni++;
    }
    vector<pair<int,char>> rk;
    rk.clear();
    if ((nt==n) || (ni==n) || (nl==n)) {
        puts("-1");
        continue;
    }
    rk.push_back(make_pair(ni, 'I'));
    rk.push_back(make_pair(nt, 'T'));
    rk.push_back(make_pair(nl, 'L'));
    sort(rk.begin(), rk.end());
    int nxt=1;
    int id=-1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == rk.back().second) {
            if (i+1 < n && (s[i+1] != s[i])) {
                id=i;
                break;
            }
            if (i-1>=0 && (s[i-1] != s[i])) {
                id=i;
                nxt=0;
                break;
            }
        }
    }
    int dt1=rk[2].first-rk[0].first;
    int dt2=rk[1].first-rk[0].first;
    int tot=2*(dt1+dt2);
    vector<int> ans;
    ans.clear();
    if (nxt) {
        for (int i = 1; i <= 2*dt1; ++i) {
            ans.push_back(id+1);
        }
        if (s[id+1] == rk[0].second) {
            for (int i = 1; i <= 2*dt2; ++i) {
                ans.push_back(id+1+2*dt1);
            }
        } else {
            for (int i =1; i <= 2*dt2; ++i) {
                ans.push_back(id+2);
            }
        }
    } else {
        for (int i = 1; i <= 2*dt1; ++i) {
            ans.push_back(id+i-1);
        }
        if (s[id-1] == rk[0].second) {
            for (int i = 1; i <= 2*dt2; ++i) {
                ans.push_back(id+i-1);
            }
        } else {
            for (int i = 1; i <= 2*dt2; ++i) {
                ans.push_back(id);
            }
        }
    }
    printf("%d\n", tot);
    for (auto x : ans) {
        printf("%d\n", x);
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
