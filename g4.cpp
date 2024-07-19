#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class graph
{
    public:
    unordered_map<int, list<pair<int, int>>>adjlist;
    void addedge(int u, int v, int weight, bool direction)
    {
        //0-->undirected
        //1-->directed
        adjlist[u].push_back({v, weight});
        if(direction==0) 
        {
            adjlist[v].push_back({u, weight});
        }

    }

    void printAdjList()
    {
        for(auto node: adjlist)
        {
            cout << node.first << "->";
            for(auto neighbour : node.second)
            {
                cout << "(" << neighbour.first << ", " << neighbour.second <<")" <<",";
            }
            cout << endl;
        }
    }
};

//ADJACENCY LIST FOR DIRECTED GRAPH
int main(){
    graph g;
    g.addedge(0, 1, 5, 1);
    g.addedge(1,2, 8, 1);
    g.addedge(0, 2, 6, 1);
    cout<<endl;
    g.printAdjList();
    return 0;
} 
