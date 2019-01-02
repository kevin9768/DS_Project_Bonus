#include <bits/stdc++.h>

using namespace std;

struct City{
    string name;
    int happiness;
    int ohr;
    int chr;
    City(string n, int h, int o, int c): name(n), happiness(h), ohr(o), chr(c){}

};

vector<City> cities;
int findidx(string &s){
    for(int i=0; i<cities.size(); i++)
        if(cities.at(i).name==s)    return i;
    return -1;
}

int main(){
    //init graph presenting by adjmat
    int total_cities, total_edges, total_time, starting_time;
    cin >> total_cities >> total_edges >> total_time >> starting_time;
    //init vector of cities
    for(int i=0; i<total_cities; i++){
        string n;
        int h,o,c;
        cin >> n >> h >> o >> c;
        City cur(n,h,o,c);
        cities.push_back(cur);
    }
    //init adjmat
    int adjmat[total_cities][total_cities];
    for(int i=0; i<total_cities; i++)
        for(int j=0; j<total_cities; j++)
            adjmat[i][j]=0;
    //build adjmat with edges
    for(int i=0; i<total_edges; i++){
        string a,b;
        cin >> a >> b;
        int x,y,dist;
        cin >> dist;
        x = findidx(a);
        y = findidx(b);
        adjmat[x][y] = dist;
        adjmat[y][x] = dist;
    }
    //store happiness idx for each node in adjmat[x][x]
    for(int i=0; i<total_cities; i++)
        adjmat[i][i] = cities.at(i).happiness;
}