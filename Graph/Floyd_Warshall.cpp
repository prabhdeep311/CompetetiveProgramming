//
//  Floyd_Warshall.cpp
//  O(V^3)
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
const ll MOD = 1000000007;
const int maxn=1e+5;
typedef vector<vector<ll> > matrix;

int m[1000][1000];   //weighted graph
int n, b;   //no of vertices and edges
int main(int argc, const char * argv[])
{
    cin>>n;
    REP(i, n)  REP(j, n)  m[i][j] = maxn; //initialize weights to max
    int p, q, w;
    cin>>b;
    REP(i, b)
    {
        cin>>p>>q>>w;
        m[p][q] = w;
    }
    //floyd warshall
    REP(k, n)
    {
        REP(i, n)
        {
            REP(j, n)
            {
                if(m[i][j]>m[i][k]+m[k][j])
                    m[i][j] = m[i][k]+m[k][j];
            }
        }
    }
    
    return 0;
}










