#define P_NUM 13

typedef struct place place;
typedef struct roads roads;

struct roads {
    int length;       // The length of the route
    place *place;     // Point to the end of the route
};

struct place { 
    int id;           // Index of place, 0 represents the cargo center, and 1~n represents the stores
    int demand;       // Each store has specific units of goods that are demanded to deliver.
    int numOfRoads;   // The number of places which has a road connected to it
    roads roads[P_NUM];
};

// Floyd–Warshall algorithm

void distance(place *p, int n);
long long minRoute(place *p, int n);