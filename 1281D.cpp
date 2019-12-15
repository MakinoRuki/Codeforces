#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#define N 200020
#define inf 1000000000
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
int t, r, c;
vector<string> mat;
int main() {
	cin>>t;
	for (int cas = 0; cas <t; ++cas){ 
		cin>>r>>c;
		mat.clear();
		int a=0;
		int p =0;
		for (int i = 0; i < r; ++i) {
			string s;
			cin>>s;
			mat.push_back(s);
			for (int j = 0; j <c;++j) {
				if (s[j] == 'A') a++;
				else p++;
			}
		}
		if (a == 0) {
			cout<<"MORTAL"<<endl;
		} else {
			if (p == 0) {
				cout<<0<<endl;
				continue;
			}
			int sumr[62][62];
			int sumc[62][62];
			memset(sumr, 0, sizeof(sumr));
			memset(sumc, 0, sizeof(sumc));
			for (int i = 0; i < r; ++i) {
				for (int j = 0; j < c; ++j) {
					sumr[i][j+1] = sumr[i][j] + (mat[i][j] == 'A');
				}
			}
			for (int j = 0; j < c; ++j) {
				for (int i = 0; i < r; ++i) {
					sumc[j][i+1] = sumc[j][i] + (mat[i][j] == 'A');
				}
			}
			if (sumr[0][c] == c || sumr[r-1][c] == c || sumc[0][r] == r || sumc[c-1][r] == r) {
				cout<<1<<endl;
			} else if (sumr[0][c] == 0 && sumr[r-1][c] == 0 && sumc[0][r] == 0 && sumc[c-1][r] == 0) {
				cout<<4<<endl;
			} else {
				bool ok = false;
				for (int j = 0; j < c; ++j) {
					if (mat[0][j] == 'A' && (sumr[0][j+1] == j+1 || sumr[0][c] - sumr[0][j+1] == c - j -1 || sumc[j][r] == r)) {
						ok = true;
						break;
					} else if (mat[r-1][j] == 'A' && (sumr[r-1][j+1] == j+1 || sumr[r-1][c]-sumr[r-1][j+1] == c-j-1 || sumc[j][r] == r)) {
						ok = true;
						break;
					}
				}
				for (int i = 0; i < r; ++i) {
					if (mat[i][0] == 'A' && (sumc[0][i+1] == i+1 || sumc[0][r]-sumc[0][i+1] == r-i-1 || sumr[i][c] == c)) {
						ok = true;
						break;
					} else if (mat[i][c-1] == 'A' && (sumc[c-1][i+1] == i+1 || sumc[c-1][r]-sumc[c-1][i+1] == r-i-1 || sumr[i][c] == c)) {
						ok = true;
						break;
					}
				}
				if (ok) cout<<2<<endl;
				else cout<<3<<endl;
			}
		}
	}
	return 0;
}
