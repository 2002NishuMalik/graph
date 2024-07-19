#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class graph
{
    public:
    unordered_map<int, list<int>>adjlist;
    void addedge(int u, int v, bool direction)
    {
        //0-->undirected
        //1-->directed
        adjlist[u].push_back(v);
        if(direction==0)
        {
            adjlist[v].push_back(u);
        }

    }

    void printAdjList()
    {
        for(auto node: adjlist)
        {
            cout << node.first << "->";
            for(auto neighbour : node.second)
            {
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }

    void dfs(int src, unordered_map<int, bool>& visited)
    {
        cout << src <<", ";
        visited[src] = true;
        for(auto neighbour: adjlist[src])
        {
            if(!visited[neighbour])
            {
                dfs(neighbour, visited);
            }
        }
    }
};

//ADJACENCY LIST FOR DIRECTED GRAPH
int main(){
    graph g;
    int n = 3;
    g.addedge(0, 1, 1);
    g.addedge(1,2, 1);
    g.addedge(0, 2, 1);
    cout<<endl;
    g.printAdjList();
    unordered_map<int, bool>visited;
    unordered_map<int, bool>visited2;
    for(int i = 0; i<=n; i++)
    {
        if(!visited[i])
        {
            g.dfs(i, visited2);
        }
    }
    return 0;
} 
