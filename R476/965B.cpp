#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#define M 20005
#define N 1000002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, k;
vector<string> mat;
int cnt[202][202];
int main() {
	cin>>n>>k;
	mat.clear();
	for (int i = 0; i < n; ++i) {
		string s;
		cin>>s;
		mat.push_back(s);
	}
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j+k<=n) {
				bool ok=true;
				for (int k1=0; k1<k; ++k1) {
					if (mat[i][j+k1]!='.') {
						// if (i==2 && j==0) {
						// 	cout<<"???"<<i<<" "<<j<<" "<<k1<<endl;
						// }
						ok=false;
						break;
					}
				}

				if (ok) {
					//cout<<"pos="<<i<<" "<<j<<endl;
					for (int k1=0; k1<k; ++k1) {
						if (mat[i][j+k1]=='.') {
							cnt[i][j+k1]++;
						}
					}
				}
			}
			if (i+k<=n) {
				bool ok=true;
				for (int k1=0; k1<k; ++k1) {
					if (mat[i+k1][j]!='.') {
						ok=false;
						break;
					}
				}
				if (ok) {
					//cout<<"pos2="<<i<<" "<<j<<endl;
					for (int k1=0; k1<k; ++k1) {
						if (mat[i+k1][j]=='.') {
							cnt[i+k1][j]++;
						}
					}
				}
			}
		}
	}
	int idx=0,idy=0;
	int num=cnt[0][0];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (cnt[i][j]>num) {
				num=cnt[i][j];
				idx=i;
				idy=j;
			}
		}
	}
	cout<<idx+1<<" "<<idy+1<<endl;
	return 0;
}
