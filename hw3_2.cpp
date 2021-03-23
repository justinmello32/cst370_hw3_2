#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //Initial Variables
    int vertices;
    int edges;
    int intMax = 100;

    //Temp variables for conversion to int after user input
    string loc1;
    string loc2;

    //Vertices/edges information
    int intLoc1 = 0;
    int intLoc2 = 0;
    int distance = 0;
    
    //Gather number of vertices
    cin >> vertices;
    
    //Gather the Cities
    vector<string> cities(vertices);
    for(int i = 0; i < vertices; i++) {
        cin >> cities[i];
    }

    //Get number of edges
    cin >> edges;
    
    vector<vector<int> > graph(vertices, vector<int> (vertices, 0));

    //Gather user input for locations/cost, input conversion.
    //This section works correctly for all user input.
    for(int i = 0; i < edges ; i++) {

        //Gather first location and adjust to int
        cin >> loc1;
        for(int j = 0; j < cities.size(); j++) {
            if(loc1 == cities[j])
                intLoc1 = j;
        }

        //Gather second location and adjust to int
        cin >> loc2;
        for(int k = 0; k < cities.size(); k++) {
            if(loc2 == cities[k])
                intLoc2 = k;
        }

        //Cin cost for future use.
        cin >> distance;
        graph[intLoc1][intLoc2] = distance;
    }

    //Check if if even possible, otherwise return -1
    for (int i = 0; i < graph.size(); i++) {
        int emptyValues = 0;
        for (int j = 0; j < graph.size(); j++) {
            if(graph[i][j] == 0)
                emptyValues++;
            if(emptyValues == graph.size() ) {
                cout << "Path:" << endl;
                cout << "Cost:-1" << endl;
                exit(1);
            }
        }
    }

    //TSP Problem calculation here
    vector<int> ver;
    int min_path = intMax;
    for (int i = 0; i < graph.size(); i++)
        if (i != 0)
            ver.push_back(i);
            int m_p = intMax; // store minimum weight of a graph
    do {
      int cur_pth = 0;
      int k = 0;
      for (int i = 0; i < ver.size(); i++) {
         cur_pth += graph[k][ver[i]];
         k = ver[i];
      }
      cur_pth += graph[k][0];
      m_p = min(m_p, cur_pth); // to update the value of minimum weight
    }
    while (next_permutation(ver.begin(), ver.end()));
    cout << "COST:" << m_p << endl;


    return 0;
}

