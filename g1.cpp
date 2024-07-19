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
};

//ADJACENCY LIST FOR DIRECTED GRAPH
int main(){
    graph g;
    g.addedge(0, 1, 0);
    g.addedge(1,2, 0);
    g.addedge(0, 2, 0);
    cout<<endl;
    g.printAdjList();
    return 0;
} 
