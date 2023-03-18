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


const int N  = 4010, INF = 1e9;
vector<int> g[N];
bool st[N];
int n;
char s[N];

void dfs(int u, vector<int>& v) {
    v.push_back(u);
    st[u] = true;
    for(int& nxt : g[u]) {
        if(!st[nxt]) {
            dfs(nxt, v);
        }
    }
}

void solve() {
    cin >> n;
    for(int i = 0; i <= n; i++) g[i].clear(), st[i] = false;

    for(int i = 0; i < n; i++) {
        scanf("%s", s);
        for(int j = i; j < n; j++) {
            if(s[j] == '1') {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }


    vector<vector<int>> all;
    for(int i = 0; i < n; i++) {
        if(!st[i]) {
            vector<int> v;
            dfs(i, v);
            all.push_back(v);
        }
    }

    if(all.size() == 1) {
        cout << 0 << endl;
        return;
    }
    
    for(auto& v : all) {
        if(v.size() == 1) {
            cout << 1 << endl;
            cout << v[0] + 1 << endl;
            return;
        }

        int mn = INF;
        int p = -1;
        for(int u : v) {
            //不能是割点
            if(g[u].size() < mn) {
                mn = g[u].size();
                p = u;
            }
        }
        if(mn + 1 != v.size()) {
            cout << 1 << endl;
            cout << p + 1 << endl;
            return;
        }
    }
    





    if(all.size() == 1) {
        
    } else if(all.size() == 2){
        if(all[0].size() > all[1].size()) swap(all[0], all[1]);
        cout << all[0].size() << endl;
        for(int v : all[0]){
            cout << v + 1 << " ";
        }
        return;
    } else {
        cout << 2 << endl;
        for(int i = 0; i < 2; i++) {
            cout << all[i][0] + 1 << " ";
        }
        cout << endl;
    }

}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0; 
}
