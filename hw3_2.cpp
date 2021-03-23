/*
 * Title: hw3_2.cpp
 * Abstract: This program reads an input graph data from a user first. 
             Then, it should present a path for the travelling salesman 
             problem.
 * Author: Justin Mello
 * ID: 2002
 * Date: 03/23/2021
*/

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
    vector<string> cities;
    vector<string> path(vertices);
    vector<int>pos;
    
    for(int i = 0; i < vertices; i++) {
        string city;
        cin >> city;
        cities.push_back(city);
        pos.push_back(i);
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
    int min_path = intMax;
    do {
      int current_path = 0;
      int k = 0;
      for (int i = 0; i < vertices; i++) {
         current_path += graph[k][pos[i]];
         k = pos[i];
      }
      current_path += graph[k][0];
      if (current_path < min_path) {
            min_path = current_path;
            for (int i = 0; i < vertices; i++) {
                path[i] = cities[pos[i]];
            }
        }
    } while (next_permutation(pos.begin(), pos.end()));

    cout << "Path:";
    for (string s : path) {
        cout << s << "->"; 
    }
    cout << cities.at(0) << endl;
    cout << "Cost:" << min_path << endl;
}

