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


struct Node {
    int l, r, idx;
};

bool comp(Node& n1, Node& n2) {
    if(n1.l == n2.l) return n1.r < n2.r;
    return n1.l < n2.l;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Node> a;
    for(int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        int right = r;
        int left = n - c + 1; 
        a.push_back({left, right, i + 1});
    }

    sort(a.begin(), a.end(), comp);
    
    /*for(auto& no : a) {
        cout << no.l << " " << no.r << endl;
    }*/
    
    int j = 0;
    vector<int> res;
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    
    for(int i = 1; i <= n; i++) {
        while(j < a.size() && a[j].l <= i ) {
            int l = a[j].l, r = a[j].r;
            pq.push({r, a[j].idx});
            j++;
        }
        
        while(pq.size() > 0 && pq.top().first < i) pq.pop();
        if(pq.size() > 0) {
            pair<int, int> p = pq.top(); pq.pop();
            res.push_back(p.second);
        }
    }

    cout << res.size() << endl;
    for(int i : res) {
        cout << i << " ";
    }

}

int main() {
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0; 
}
