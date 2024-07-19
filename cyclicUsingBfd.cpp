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

    void bfs(int src)
    {
        queue<int>q;
        unordered_map<int, bool>visited;
        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            int frntNode = q.front();
            q.pop();
            cout<<frntNode<<" ,";
            for(auto neighbour : adjlist[frntNode])
            {
                if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour]=true;
                }
            }
        }
    }

    bool checkCyclic(int src, unordered_map<int, bool>&visited)
    {
        queue<int>q;
        unordered_map<int, int> parent;
        q.push(src);
        parent[src] = -1;

        while(!q.empty())
        {
            int frntNode = q.front();
            q.pop();

            for(auto nbr : adjlist[frntNode])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frntNode;
                }
                else{
                    if(nbr!=parent[frntNode ])
                    {
                        return true;
                    }
                }
            }

        }
        return false;
    }
};

//ADJACENCY LIST FOR DIRECTED GRAPH
int main(){
    graph g;
    int n = 8;
    g.addedge(0, 1, 0);
    g.addedge(1,2, 0);
    g.addedge(1, 3, 0);
    g.addedge(3, 5, 0);
    g.addedge(3, 7, 0);
    g.addedge(7, 6, 0);
    g.addedge(7, 4, 0);
    cout<<endl;
    unordered_map<int, bool>visited;
    bool ans = false;
    g.printAdjList();
    for(int i = 0; i<n; i++)
    {
        if(!visited[i])
        {
            ans = g.checkCyclic(i, visited);
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
    g.bfs(0);
    return 0;
} 
