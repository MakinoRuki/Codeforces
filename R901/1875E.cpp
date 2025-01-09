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
#define M 405
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
int dis[N];
int pw[M];
int mt[N][4];
void bfs() {
    for (int i = 0; i < N; ++i) {
        dis[i] = inf;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for (int i = 0; i < (1<<8); ++i) {
        int st=0;
        for (int j = 0; j < 8; ++j) {
            if ((1<<j)&i) st += 4*pw[j];
            else st += (j/2)*pw[j];
        }
        dis[st]=0;
        pq.push(make_pair(0, st));
    }
    while(!pq.empty()) {
        auto pr = pq.top();
        pq.pop();
        int ds = pr.first;
        int cur = pr.second;
        if (ds > dis[cur]) {
            continue;
        }
        for (int i = 0; i < 4; ++i) {
            int nxt = mt[cur][i];
            if (dis[nxt] > dis[cur] + 1) {
                dis[nxt] = dis[cur]+1;
                pq.push(make_pair(dis[nxt], nxt));
            }
        }
    }
}
int main() {
  pw[0]=1;
  for (int i = 1; i <= 10; ++i) {
    pw[i]=pw[i-1]*5;
  }
  for (int i = 0; i < pw[8]; ++i) {
    vector<int> bs;
    bs.clear();
    int x=i;
    for (int j = 0; j < 8; ++j) {
        bs.push_back(x%5);
        x/=5;
    }
    for (int op = 0; op < 4; ++op) {
        int res=0;
        for (int j = 0; j < 8; ++j) {
            if (op == 0) {
                if (bs[j] != 2) {
                    res += bs[j]*pw[j];
                }
            }
            if (op == 1) {
                if (bs[j] == 1) res += 3*pw[j];
                else res += bs[j]*pw[j];
            }
            if (op == 2) {
                if (bs[j] == 2) res += 3*pw[j];
                else if (bs[j] == 3) res += 2*pw[j];
                else res += bs[j]*pw[j];
            }
            if (op == 3) {
                if (j%2) {
                    if (bs[j] == 0) res += pw[j];
                    else if (bs[j] == 2) res += 3*pw[j];
                    else if (bs[j] == 3) res += 2*pw[j];
                    else if (bs[j] == 4) res += bs[j]*pw[j];
                } else {
                    res += bs[j]*pw[j];
                }
            }
        }
        mt[i][op] = res;
    }
  }
  bfs();
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int a,b,c,d;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &m);
    bool ok=true;
    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 30; ++j) {
            if (i==j) continue;
            int a1 = ((1<<i)&a)>0;
            int a2 = ((1<<j)&a)>0;
            int b1 = ((1<<i)&b)>0;
            int b2 = ((1<<j)&b)>0;
            int m1 = ((1<<i)&m)>0;
            int m2 = ((1<<j)&m)>0;
            int c1 = ((1<<i)&c)>0;
            int c2 = ((1<<j)&c)>0;
            int d1 = ((1<<i)&d)>0;
            int d2 = ((1<<j)&d)>0;
            if ((a1==a2) && (b1==b2) && (m1==m2)) {
                // if (i==1 && j == 2) {
                //     cout<<"ok!!"<<endl;
                //     cout<<((1<<i)&c)<<" "<<((1<<j)&c)<<endl;
                // }
                if ((c1 != c2) || (d1 != d2)) {
                    ok=false;
                    break;
                }
            }
        }
    }
    if (!ok) {
        puts("-1");
        continue;
    }
    
    vector<int> bs = {4,4,4,4,4,4,4,4};
    for (int i = 0; i < 30; ++i) {
        int id=0;
        int res=0;
        if ((1<<i)&a) {
            id += 4;
        }
        if ((1<<i)&b) id+=2;
        if ((1<<i)&m) id++;
        if ((1<<i)&c) res += 2;
        if ((1<<i)&d) res++;
        bs[id] = res;
    }
    int res=0;
    for (int i = 0; i < 8; ++i) {
        res += bs[i]*pw[i];
    }
    //printf("%d\n", dis[res]);
    if (dis[res] < inf) printf("%d\n", dis[res]);
    else puts("-1");
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

