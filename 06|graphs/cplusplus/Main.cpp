#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <limits.h>
using namespace std;

/*
update the distances and parents from the 1st square.
*/
void bfs(int n, vector<int> &distances, vector<int> &parents, vector<int> jumpto)
{
    int x = distances.size() - 1;
    for (int i = 0; i < x; i++)
    {
        distances[i] = INT_MAX;
        parents[i] = -1;
    }
    queue<int> q;
    q.push(1);
    distances[1] = 0;
    while (!q.empty())
    {
        int currentSquare = q.front();
        q.pop();
        if (jumpto[currentSquare] != -1)
        {
            continue;
        }
        for (int die = 1; die <= n; die++)
        {
            int nextSquare = currentSquare + die;
            if (nextSquare <= x && distances[nextSquare] == INT_MAX)
            {
                distances[nextSquare] = distances[currentSquare] + 1;
                parents[nextSquare] = currentSquare;
                q.push(nextSquare);
                //the nextSquare is at the mouth of a snake/base of a ladder
                while (jumpto[nextSquare] != -1 && distances[nextSquare] < distances[jumpto[nextSquare]])
                {
                    distances[jumpto[nextSquare]] = distances[nextSquare];
                    parents[jumpto[nextSquare]] = nextSquare;
                    q.push(jumpto[nextSquare]);
                    nextSquare = jumpto[nextSquare];
                }
            }
        }
    }
}

/*
print the path to out upto destination
assumes that square not having parents has -1 in parents array
*/
void printPath(ostream &out, vector<int> &parents, int destination)
{
    stack<int> path;
    int currentSquare = destination;
    while (currentSquare != -1)
    {
        path.push(currentSquare);
        currentSquare = parents[currentSquare];
    }
    while (!path.empty())
    {
        out << path.top();
        path.pop();
        out << (path.empty() ? "\n" : " -> ");
    }
}

/*
print unreachable squares from start to end
assumes that having distances equal to INT_MAX means unreachable
*/
void printUnreachable(ostream &out, vector<int> distances, int start, int end)
{
    vector<int> unreachable;
    for (int i = start; i <= end; i++)
    {
        if (distances[i] == INT_MAX)
        {
            unreachable.push_back(i);
        }
    }
    if (unreachable.size() == 0)
    {
        out << "All reachable\n";
    }
    else
    {
        for (int i = 0; i < unreachable.size(); i++)
        {
            out << unreachable[i] << (i == unreachable.size() - 1 ? "\n" : " ");
        }
    }
}

int main()
{
    ifstream in("input.txt", ios::in);
    ofstream out("output.txt", ios::out);
    int t;
    in >> t;
    while (t--)
    {
        int n, x, l, s;
        in >> n >> x >> l;
        vector<int> jumpto(x + 1, -1), distances(x + 1, INT_MAX), parents(x + 1, -1);
        for (int i = 0; i < l; i++)
        {
            int ll, lr;
            in >> ll >> lr;
            jumpto[ll] = lr;
        }
        in >> s;
        for (int i = 0; i < s; i++)
        {
            int sl, sr;
            in >> sr >> sl;
            jumpto[sr] = sl;
        }
        bfs(n, distances, parents, jumpto);
        if (distances[x] == INT_MAX)
        {
            out << "-1\nNo solution\n";
        }
        else
        {
            out << distances[x] << "\n";
            printPath(out, parents, x);
        }
        printUnreachable(out, distances, 1, x);
        out << "\n";
    }
    in.close();
    out.close();
    return 0;
}