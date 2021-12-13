using AdjacencyMatrix = std::vector<std::vector<int>>;

// in the adcjacency matrix m, 1 represents an edge and 0 represents no edge
// the function returns true if a path exists between vertex v and vertex w
bool connected(const AdjacencyMatrix& m, int v, int w) {
    // if v and w are the same, then there is a path
    if (v == w) {
        return true;
    }

    // if v or w is out of bounds, then there is no path
    if (v < 0 || v >= m.size() || w < 0 || w >= m.size()) {
        return false;
    }

    // if there is an edge between v and w, then there is a path
    if (m[v][w] == 1) {
        return true;
    }

    // if there is no edge between v and w, then there is no path
    return false;
}


