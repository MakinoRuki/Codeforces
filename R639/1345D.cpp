#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#define N 1005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
vector<string> mt;
bool has[N][N][4];
int par[N*N];
int find(int x) {
  return par[x]==x?x:par[x]=find(par[x]);
}
int main() {
  cin>>n>>m;
  mt.clear();
  memset(has, false, sizeof(has));
  for (int i = 0; i < n; ++i) {
    string s;
    cin>>s;
    mt.push_back(s);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (j==0) has[i][j][2] = (mt[i][j]=='#');
      else has[i][j][2] = (has[i][j-1][2]||(mt[i][j]=='#'));
    }
    for (int j = m-1; j >= 0; --j) {
      if (j==m-1) has[i][j][3] = (mt[i][j]=='#');
      else has[i][j][3] = (has[i][j+1][3] || (mt[i][j]=='#'));
    }
  }
  for (int j= 0; j <m; ++j) {
    for (int i = 0; i < n; ++i) {
      if (i==0) has[i][j][0] = (mt[i][j]=='#');
      else has[i][j][0]=(has[i-1][j][0]||(mt[i][j]=='#'));
    }
    for (int i=n-1; i>=0; --i) {
      if (i==n-1) has[i][j][1] = (mt[i][j]=='#');
      else has[i][j][1] = (has[i+1][j][1]||(mt[i][j]=='#'));
    }
  }
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mt[i][j]=='.') {
        if ((i>0&&has[i-1][j][0]&&i<n-1&&has[i+1][j][1]) || (j>0&&has[i][j-1][2]&&j<m-1&&has[i][j+1][3])) {
         // cout<<i<<" "<<j<<endl;
          ok=false;
        }
      }
    }
    if (mt[i][0]=='.' && !has[i][0][3]) {
      int j;
      for (j = 0; j < m; ++j) {
        if (!has[0][j][1]) break;
      }
      if (j>=m) ok = false;
    }
  }
  for (int j = 0; j < m; ++j) {
    if (mt[0][j]=='.' && !has[0][j][1]) {
    //  cout<<"???"<<j<<endl;
      int i;
      for (i = 0; i < n; ++i) {
        if (!has[i][0][3]) break;
      }
      if (i>=n) ok = false;
    }
  }
  if (!ok) {
    cout<<-1<<endl;
  } else {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        par[i*m+j] = i*m+j;
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mt[i][j]=='#') {
          if (i-1>=0 && mt[i-1][j]=='#') {
            int px= find(par[i*m+j]);
            int py = find(par[(i-1)*m+j]);
            if (px != py) par[px]=py;
          }
          if (i+1<n && mt[i+1][j]=='#') {
            int px = find(par[i*m+j]);
            int py = find(par[(i+1)*m+j]);
            if (px!=py) par[px]=py;
          }
          if (j-1>=0 && mt[i][j-1]=='#') {
            int px = find(par[i*m+j]);
            int py = find(par[i*m+j-1]);
            if (px!=py) par[px]=py; 
          }
          if (j+1<m && mt[i][j+1]=='#') {
            int px = find(par[i*m+j]);
            int py = find(par[i*m+j+1]);
            if (px!=py) par[px]=py; 
          }
        }
      }
    }
    int ans=0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        //cout<<i<<" "<<j<<" "<<find(i*m+j)<<endl;
        if (mt[i][j]=='#' && find(i*m+j)==i*m+j) {
          ans++;
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
