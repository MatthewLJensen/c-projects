#include "DisjointSet.h"

// Construct size sets, each in its own equivalent class
DisjointSet::DisjointSet(int size) : number_of_sets(1), set(size) {
    for( int i = 0; i <= size; i++ )
    set.push_back(i);
}

// Find the equivalence class of n.
// Uses path compression to reduce the search path
// of all the elements on the path from n to its
// representative element.
int DisjointSet::Find(int i) {
    if (set[i] != i){
        set[i] = Find(set[i]);
    }
    return set[i];
}

// Merge the two equivalence classes s1 and s2.
// No optimization performed during the union.
int DisjointSet::Union(int s1, int s2) {
    int p1 = Find(s1),
        p2 = Find(s2);
        set[p1] = p2;
        number_of_sets--;
        return 1;
}

// Number of equivalence classes (sets)
int DisjointSet::Cardinality() const {
    return number_of_sets;
}

// Makes a set in its own equivalence class
void DisjointSet::Make_Set(int i) {
    set[i] = i;
}

// Unmerge all elements into separate sets.
// Each element will be a singleton in its 
// own equivalence class.
void DisjointSet::Split() {
    for(int i = 0; i <= set.size(); i++){
        Make_Set(i);
    }
    number_of_sets = set.size();
}
