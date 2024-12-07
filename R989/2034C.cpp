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
int n, m;
int k;
int t;
int a[N];
int mat[M][M];
vector<string> mp;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    mp.clear();
    for (int i = 0; i < n; ++i) {
        string s;
        cin>>s;
        mp.push_back(s);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            mat[i][j] = -1;
        }
    }
    queue<pair<int,int>> q;
    for (int i = 0; i < n; ++i) {
        if (mp[i][0] =='L') {
            q.push(make_pair(i,0));
            mat[i][0]=1;
        }
        if (mp[i][m-1] == 'R') {
            q.push(make_pair(i, m-1));
            mat[i][m-1]=1;
        }
    }
    for (int j = 0; j < m; ++j) {
        if (mp[0][j] == 'U') {
            q.push(make_pair(0, j));
            mat[0][j]=1;
        }
        if (mp[n-1][j] == 'D') {
            q.push(make_pair(n-1, j));
            mat[n-1][j]=1;
        }
    }
    while(!q.empty()) {
        auto pr = q.front();
        q.pop();
        int x = pr.first;
        int y = pr.second;
     //   cout<<"xy="<<x<<" "<<y<<endl;
        if (x-1>=0 && mp[x-1][y] == 'D' && mat[x-1][y] < 0) {
            q.push(make_pair(x-1, y));
            mat[x-1][y]=1;
        }
        if (x+1 < n && mp[x+1][y] == 'U' && mat[x+1][y] < 0) {
            q.push(make_pair(x+1, y));
            mat[x+1][y]=1;
        }
        if (y-1>=0 && mp[x][y-1] == 'R' && mat[x][y-1] < 0) {
            q.push(make_pair(x, y-1));
            mat[x][y-1]=1;
        }
        if (y+1<m && mp[x][y+1] == 'L' && mat[x][y+1] < 0) {
            q.push(make_pair(x, y+1));
            mat[x][y+1]=1;
        }
    }
    int ans=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mp[i][j] == '?') {
                int num=0;
                int tot=0;
                if (i-1>=0) {
                    tot++;
                    if (mat[i-1][j]==1) num++;
                }
                if (i+1<n) {
                    tot++;
                    if (mat[i+1][j]==1)num++;
                }
                if (j-1>=0) {
                    tot++;
                    if (mat[i][j-1]==1) num++;
                }
                if (j+1<m) {
                    tot++;
                    if (mat[i][j+1]==1) num++;
                }
                if (num < tot) ans++;
            } else {
                if (mat[i][j]==1) continue;
                ans++;
            }
        }
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

