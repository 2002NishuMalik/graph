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

    bool checkCyclic(int src, unordered_map<int, bool>&visited, int parent)
    {
        visited[src]=true;
        for(auto nbr: adjlist[src])
        {
            if(!visited[nbr])
            {
                
                bool check = checkCyclic(nbr, visited, src);
                if(check == true)
                {
                    return true;
                }
            }
            if(visited[nbr] && nbr != parent)
            {
                return true;
            }
            
        }
        return false; 
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
    unordered_map<int, bool>visited;
    int parent = -1;
    bool ans = false;
    g.printAdjList();
    for(int i = 0; i<n; i++)
    {
        if(!visited[i])
        {
            ans = g.checkCyclic(i, visited, -1);
            
            if(ans == true)
            {
                break;
            }
        }
          
    }
    if(ans == true)
    {
        cout << "cyclic" <<endl;
    }
    else{
        cout << "not cyclic" << endl;
    }
    unordered_map<int, bool>visited1;
    unordered_map<int, bool>visited2;
    for(int i = 0; i<=n; i++)
    {
        if(!visited1[i])
        {
            g.dfs(i, visited2);
        }
    }
    return 0;
} 
