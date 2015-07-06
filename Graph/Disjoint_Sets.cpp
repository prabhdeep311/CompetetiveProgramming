//
//  Disjoint_Sets.cpp
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

#define REP(i,n) for (int i = 1; i <= n; i++)
#define in(i) scanf("%d",&i)
#define out(i) printf("%d\n",i)

typedef long long ll;
const ll MOD = 1000000007;
const int maxn=1e+5;
typedef vector<vector<ll> > matrix;

int g[1005];
int find(int x) //path compression
{
    return g[x]==x ? g[x] : g[x] = find(g[x]);
}
void Union(int x, int y)
{
    //check if find(x)!=find(y)
    g[find(x)] = find(y);
}

int n;

int main(int argc, const char * argv[])
{
    cin>>n;
    REP(i, n)   //Initialize
    {
        g[i]=i;
    }
    return 0;
}












