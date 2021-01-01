1) The maximum number of nodes at level ‘l’ of a binary tree is 2l.
Here level is number of nodes on path from root to the node (including root and node). Level of root is 0.
This can be proved by induction.
For root, l = 0, number of nodes = 20 = 1
Assume that maximum number of nodes on level ‘l’ is 2l
Since in Binary tree every node has at most 2 children, next level would have twice nodes, i.e. 2 * 2l

 
2) Maximum number of nodes in a binary tree of height ‘h’ is 2h – 1.
Here height of a tree is maximum number of nodes on root to leaf path. Height of a tree with single node is considered as 1.
This result can be derived from point 2 above. A tree has maximum nodes if all levels have maximum nodes. So maximum number of nodes in a binary tree of height h is 1 + 2 + 4 + .. + 2h-1. This is a simple geometric series with h terms and sum of this series is 2h – 1.
In some books, height of the root is considered as 0. In this convention, the above formula becomes 2h+1 – 1

 
3) In a Binary Tree with N nodes, minimum possible height or minimum number of levels is  ? Log2(N+1) ?  
This can be directly derived from point 2 above. If we consider the convention where height of a leaf node is considered as 0, then above formula for minimum possible height becomes   ? Log2(N+1) ? – 1

 
4) A Binary Tree with L leaves has at least   ? Log2L ? + 1   levels
A Binary tree has maximum number of leaves (and minimum number of levels) when all levels are fully filled. Let all leaves be at level l, then below is true for number of leaves L.

 
5) In Binary tree where every node has 0 or 2 children, number of leaf nodes is always one more than nodes with two children.

   L = T + 1
Where L = Number of leaf nodes
      T = Number of internal nodes with two children
      
      
      
  *****************************************************types of binary tree*************************************************************************************
 << 1>>  Full Binary Tree A Binary Tree is a full binary tree if every node has 0 or 2 children. The following are the examples of a full binary tree. We can also
	 say a full binary tree is a binary tree in which all nodes except leaf nodes have two children.

               18
           /       \  
         15         30  
        /  \        /  \
      40    50    100   40

             18
           /    \   
         15     20    
        /  \       
      40    50   
    /   \
   30   50

               18
            /     \  
          40       30  
                   /  \
                  100   40
				 
				 
	<<2>>Complete Binary Tree: A Binary Tree is a complete Binary Tree if all the levels are completely filled except possibly the last level and the last level
	 has all keys as left as possible	
	     18
           /       \  
         15         30  
        /  \        /  \
      40    50    100   40


               18
           /       \  
         15         30  
        /  \        /  \
      40    50    100   40
     /  \   /
    8   7  9 		
                 
                 
    3>>Perfect Binary Tree A Binary tree is a Perfect Binary Tree in which all the internal nodes have two children and all leaf nodes are at the same level.
The following are the examples of Perfect Binary Trees.

              18
           /       \  
         15         30  
        /  \        /  \
      40    50    100   40            
      
    4>>  
                 
                 
