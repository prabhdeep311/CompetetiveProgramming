//
//  SCC.cpp
//  O(n + m)
//
//  Created by Prabhdeep Singh Walia on 21/03/15.
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

#define REP(i,n) for (int i = 1; i <= n; i++)
#define in(i) scanf("%d",&i)
#define out(i) printf("%d\n",i)
#define pii pair<int, int>
//void fast_io() { cin.tie(0); ios::sync_with_stdio(false); }

typedef long long ll;
const ll MOD = 1000000007;
const int maxn=1e+5;
typedef vector<vector<ll> > matrix;

int n, m, u, v;
vector< int > g[100005], gr[100005];
vector<int> order;
bool used[100005];
vector<int> chck;

void dfs1(int i)
{
    used[i] = true;
    for(auto x : g[i])
    {
        if(!used[x])
        {
            used[x] = true;
            dfs1(x);
        }
    }
    order.push_back(i);
}

void dfs2(int i)
{
    used[i] = true;
    chck.push_back(i);
    for(auto x : gr[i])
    {
        if(!used[x])
        {
            used[x] = true;
            dfs2(x);
        }
    }
}

int main(int argc, const char * argv[])
{
    cin>>n;
    cin>>m;
    REP(i, m)
    {
        cin>>u>>v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }
    REP(i, n)
    {
        if(!used[i])    dfs1(i);
    }
    REP(i, n)   used[i] = false;
    for(int i = n-1; i>=0; i--)
    {
        chck.erase(chck.begin(), chck.end());
        if(!used[order[i]])
        {
            dfs2(order[i]);
        }
        //vector chck contains strongly connected component
    }
    return 0;
}










