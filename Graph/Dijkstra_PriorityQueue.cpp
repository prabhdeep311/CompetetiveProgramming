//
//  Dijkstra_PriorityQueue.cpp
//  O(V^2)
//
//  Created by Prabhdeep Singh Walia on 09/06/15.
//  Copyright (c) 2015 Prabhdeep Singh Walia. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <list>
#include <fstream>
#include <set>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)
#define in(i) scanf("%d",&i)
#define out(i) printf("%d\n",i)
#define pii pair<int, int>
void fast_io() { cin.tie(0); ios::sync_with_stdio(false); }

typedef long long ll;
const ll MOD = 1000000000007;
const int maxn=1e+5;
typedef vector<vector<ll> > matrix;
int par[100005];
ll dist[100005];
priority_queue< pair<ll, int> > pq;

vector<int> ans;
int n, m;
vector<pii> gr[100005];
int main(int argc, const char * argv[])
{
    cin>>n>>m;
    int a, b, w;
    REP(i, m)
    {
        cin>>a>>b>>w;
        a--;
        b--;
        gr[a].push_back({b, w});
        gr[b].push_back({a, w});
    }
    dist[0] = 0;
    for(int i=1; i<n; i++)  dist[i] = MOD;
    pq.push({0, 0});
    while(!pq.empty())
    {
        int from = pq.top().second;
        pq.pop();
        for(auto x : gr[from])
        {
            int to = x.first;
            ll len = x.second;
            if(dist[to]>dist[from]+len)
            {
                dist[to] = dist[from] + len;
                par[to] = from;
                pq.push({-dist[to], to});
            }
        }
    }
    
    //Display shortest path from 1 to n
    if(dist[n-1] == MOD)
    {
        cout<<-1;
        return 0;
    }
    int c = n-1;
    while (c!=0) {
        ans.push_back(c+1);
        c=par[c];
    }
    ans.push_back(1);
    for(auto it = ans.rbegin(); it != ans.rend(); it++)
        cout << *it << " ";
    return 0;
}










