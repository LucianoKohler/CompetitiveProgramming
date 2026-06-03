# Segmented Tree

Complexity: 
- Processing (updating and querying): **O(log n)**
- Pre-processing: **O(n)**
- Memory: **O(4*n)**

![seg tree representation](image.png)

<div align="center">

Source: [Competitive Programmer's Handbook](https://cses.fi/book/book.pdf)

</div>

The Segmented Tree is the a **great** data structure to efficiently calculate **range queries**, because, contrary to the prefix sum, which needs to keep the array static, we can:

- Calculate many other things other than sums like **minimum, maximum and bitwise operations** in a range
- Update values without excessive time cost (called *dynamic queries*)

# Structure

The segmented tree, although called tree, is, most of the time, represented by a vector of size **4*n**, where we have, for each element:

- `leftChild(k) = tree[2k]` 
- `rightChild(k) = tree[2k+1]`
- `parent(k) = tree[k/2]`

**Note: k/2 = floor(k/2), but int truncates it already*

---

### Related Problem and Algorithm's Code

The code is really big, so refer to [segTree.cpp](https://github.com/LucianoKohler/CompetitiveProgramming/blob/main/destaques/segTree/segTree.cpp)