#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <list>
   
using namespace std;  
using ll = long long;
using ull = unsigned long long;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define ve vector
typedef pair<int, int> PII;
typedef pair<double, double> PDD;


const int N  = 3e5 + 10, M = 9;
int a[N][M];
int n, m;
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    int tot = (1 << m) - 1;
    int ans1 = -1, ans2 = -1;

    int l = 0, r = 1e9;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        unordered_map<int, int> f;
        for(int i = 0; i < n; i++) {
            int v = 0;
            for(int j = 0; j < m; j++) {
                if(a[i][j] >= mid) v |= (1 << j);
            }
            f[v] = i;
        }

        bool find = false;
        int p1 = -1, p2 = -1;
        for(int i = 0; i <= tot && !find; i++) {
            for(int j = 0; j <= tot &&!find; j++) {
                if((i | j) == tot) {
                    if(f.find(i) != f.end() && f.find(j) != f.end()) {
                        p1 = f[i];
                        p2 = f[j];
                        find = true;
                        break;
                    }
                }
            }
        }
        if(find) {
            ans1 = p1; ans2 = p2;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans1 + 1 << " " << ans2 + 1 << endl;

}

int main() {
    solve();
    return 0; 
}
