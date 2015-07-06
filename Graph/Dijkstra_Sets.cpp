//
//  Dijkstra_Sets.cpp
//  O(V^2)
//
//  Created by Prabhdeep Singh Walia on 09/06/15.
//  Copyright (c) 2015 Prabhdeep Singh Walia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;
#define INF 1000000000000

vector <pair <int, long long>> G[int(1e5)];
vector <int> path;
set <pair <long long, int>> q;
long long dlina[100000];
int parent[100000];
vector <int> ans;

int main() {
    //ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int from, to, len;
        cin >> from >> to >> len;
        from--;
        to--;
        G[to].push_back(make_pair(from, len));
        G[from].push_back(make_pair (to, len));
    }
    dlina [0]=0;
    for (int i=1; i<n; i++) {
        dlina[i]=INF;
    }
    q.insert (make_pair (dlina[0], 0));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase (q.begin());
        for (int i=0; i<G[v].size(); i++) {
            int to = G[v][i].first, len = G[v][i].second;
            if (dlina[v]+len<dlina[to]) {
                q.erase (make_pair (dlina[to], to));
                dlina[to] = dlina[v]+len;
                parent[to] = v;
                q.insert (make_pair (dlina[to], to));
            }
        }
    }
    //Display shortest path from 1 to n
    
    if (dlina[n-1]==INF) {
        cout << "-1";
        return 0;
    }
    int c=n-1;
    while (c!=0) {
        ans.push_back(c+1);
        c=parent[c];
    }
    ans.push_back(1);
    for(auto it = ans.rbegin(); it != ans.rend(); it++)
        cout << *it << " ";
    return 0;
}