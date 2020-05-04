#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#define N 502
using namespace std;
typedef long long ll;
int h, w;
vector<string> mt;
bool vis[N][N];
int main() {
  cin>>h>>w;
  mt.clear();
  for (int i = 0; i < h; ++i) {
  	string s;
  	cin>>s;
  	mt.push_back(s);
  }
  memset(vis, false, sizeof(vis));
  int tot=0;
  for (int i = 0; i < h; ++i) {
  	for (int j = 0; j < w; ++j) {
  		if (mt[i][j] == '*') tot++;
  	}
  }
  bool found = false;
  int cnt=0;
  for (int i = 0; i < h; ++i) {
  	for (int j = 0; j < w; ++j) {
  		if (mt[i][j]=='*' && i-1>=0 && mt[i-1][j]=='*' && i+1<h && mt[i+1][j]=='*' && j-1>=0 && mt[i][j-1]=='*' && j+1<w && mt[i][j+1]=='*') {
  			found=true;
  			vis[i][j]=true;
  			cnt++;
  			for (int i2=i-1; i2>=0; --i2) {
  				if (mt[i2][j] == '.') break;
  				vis[i2][j]=true;
  				cnt++;
  			}
  			for (int i2=i+1; i2<h; ++i2) {
  				if (mt[i2][j] == '.') break;
  				vis[i2][j] = true;
  				cnt++;
  			}
  			for (int j2=j-1; j2>=0; --j2) {
  				if (mt[i][j2] == '.') break;
  				vis[i][j2] = true;
  				cnt++;
  			}
  			for (int j2= j+1; j2<w; ++j2) {
  				if (mt[i][j2] == '.') break;
  				vis[i][j2] = true;
  				cnt++;
  			}
  			break;
  		}
  	}
  	if (found) break;
  }
  if (!found) cout<<"NO"<<endl;
  else {
  	if (cnt==tot) cout<<"YES"<<endl;
  	else cout<<"NO"<<endl;
  }
  return 0;
}
