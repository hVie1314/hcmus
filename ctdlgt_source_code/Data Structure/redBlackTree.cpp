/*
___________________________SUMMARY_________________________

* PROPERTY

- have same property with binary search tree
- additional property
    + each node has color either black or red
    + root node is always black
    + all NIL nodes are black
    + red nodes cannot have red children (red conflict) 
    + all paths from any node to leaf node have the same number of black nodes
        -> the longest path is not more than twice as long as the shortest path 

-----------------------------------------------------------

* INSERTION

- insert to an empty tree
    + insert node at the root and color it black 

- insert to a non-empty tree:
    + insert like bin-tree
    + color it red

- if the parent is black -> return 

- if the parent is red:
    + if the uncle is red
        + change color of parent and uncle -> black 
        + if the grandparent is not root: color it -> red
        + recheck for the violations 
    + if the uncle is black 
        + perform appropriate rotaion
        + recolor 

- rotations:
    + right-right case: color->swap(grandparent, parent)
    + left-left case: color->(grandprent, parent)
    + right-left case: color->swap(grandparent, newNode)
    + left-right case: color->swap(grandparent, newNode)
*/