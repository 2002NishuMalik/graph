#include<bits/stdc++.h>
#include<iostream>

using namespace std;

//ADJACENCY LIST FOR DIRECTED GRAPH
int main(){
    int n, m;
    cin>>n >>m;
    vector<int> adj[n+1];
    for(int i = 0; i<m; i++)
    {
        int u, v;
        cin>> u >>v;
        adj[u].push_back(v);
        
    }
    return 0;
} 
