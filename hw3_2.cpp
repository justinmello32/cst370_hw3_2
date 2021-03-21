#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main()
{
    //Gather number of vertices
    int vertices;
    int edges;
    cin >> vertices;
    
    //vector<vector<int>> graph( vertices , vector<int> (vertices, INT_MAX));
    
    //Gather the Cities
    vector<string> cities(vertices);
    for(int i = 0; i < vertices; i++) {
        cin >> cities[i];
    }
    
    cin >> edges;
    
    string loc1, loc2;
    int intLoc1 =0;
    int intLoc2 = 0;
    
    int cost;
    
    for(int i = 0; i < edges ; i++) {
        
        cin >> loc1; 
        
        for(int i = 0; i < cities.size(); i++) {
            if(loc1 == cities[i])
                intLoc1 = i;
        }
        
        cin >> loc2;
        for(int i = 0; i < cities.size(); i++) {
            if(loc2 == cities[i])
                intLoc2 = i;
        }
        
        cin >> cost;
        
        
        
    }
        cout << "Location 1 is " << intLoc1 << endl;
        cout << "Location 2 is " << intLoc2 << endl;
       
        
        return 0;
}

