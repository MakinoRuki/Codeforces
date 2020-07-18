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
#define N 105
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
int x,y,z;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>x>>y>>z;
		if (x!=y && y!=z && x!=z) {
			cout<<"NO"<<endl;
		} else {
			vector<int> w = {x,y,z};
			sort(w.begin(), w.end());
			if (w[2] != w[1]) {
				cout<<"NO"<<endl;
			} else {
				cout<<"YES"<<endl;
				cout<<w[0]<<" "<<w[0]<<" "<<w[2]<<endl;
			}
		}
	}
  return 0;
}
