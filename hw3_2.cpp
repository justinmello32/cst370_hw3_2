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
    // store all vertex apart from source vertex
    vector<int> vertex;
    for (int i = 0; i < 4; i++)
        if (i != 0)
            vertex.push_back(i);

    // store minimum weight Hamiltonian Cycle.
    int min_path = intMax;
    do {

        // store current Path weight(cost)
        int current_pathweight = 0;

        // compute current path weight
        int k = 0;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][0];

        // update minimum
        min_path = min(min_path, current_pathweight);

    } while (
            next_permutation(vertex.begin(), vertex.end()));

    cout << min_path << endl;





    return 0;
}

