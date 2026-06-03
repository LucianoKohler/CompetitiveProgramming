# Disjoint Set Union (DSU)

Complexity: 
- Union: **O(1)** (Follows reverse Ackermann function)
- Query: **O(1)** (Follows reverse Ackermann function)
- Pre-processing: **O(1)** (Always)

---

On **graph theory**, disjoint sets can help you to keep track of how many **components** (regions of nodes that don't reach another region) exist in a graph. To do so, we use the **parenting** technique (like in a tree), where two nodes are in a same component if their parent is the same.

_Note: Root notes have themselves as parents_

In sum, DSU consists of three functions:
- `unite(int node, int targ)`: Unites two nodes (can be node to node or node tocomponent)
- `create(int node)`: Creates a node that is parented to itself
- `find(int node)`: Finds a node's parent **(the most important!)** 

We also need to keep track of the size of the components to optimally find the best way to unite the nodes

---

### Related Problem and Algorithm's Code

```cpp
// https://cses.fi/problemset/task/1676

// parent of each node, size of the node's component
int parent[n];
int size[n];

void create(int nodo){
    parent[nodo] = nodo;
    size[nodo] = 1;
}

int find(int nodo){
    if(nodo == parent[nodo]) return nodo;
    parent[nodo] = find(parent[nodo]);
    return parent[nodo];
   // Returns the parent AND updates the parent of a node to improve efficiency
}

int unionDSU(int nodo, int alvo){
    int a = find(nodo);
    int b = find(alvo);

    if(a == b) return; // Already united
    if(size[a] < size[b]) swap(a, b); // Optimization: The biggest component joins to the smallest

    parent[b] = a;
    size[a] += size[b];
}
```

**Important**: It is easy to implement a variable "qtdComponents" to keep track of how many components the graph has, since you just need to decrement it for each valid union.