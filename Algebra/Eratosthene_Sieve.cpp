//
//  Eratosthene_Sieve.cpp
//  O(n*log(log(n)))
//
//  Created by Prabhdeep Singh Walia on 15/03/15.
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

typedef long long ll;
const ll MOD = 1000000007;
const int maxn=1e+5;
typedef vector<vector<ll> > matrix;

bool isprime[maxn]; //used in sieving
vector<int> primes; //stores all primes till n

void sieve(int n)
{
    memset(isprime, true, sizeof(isprime));
    isprime[0] = false;
    isprime[1] = false;
    for(int i = 2; i <= n; i++)
    {
        if(isprime[i])
        {
            primes.push_back(i);
            for(int j = i*i; j <= n; j += i)
            {
                isprime[j] = false;
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    int n;
    cin>>n;
    sieve(n);
    for(auto x : primes)    cout<<x<<"\n";
    return 0;
}


