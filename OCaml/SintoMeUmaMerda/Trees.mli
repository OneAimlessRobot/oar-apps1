type 'a tree = Nil | Node of 'a * 'a tree * 'a tree
type inttree = int tree
val howMany : 'a -> 'a tree -> int
val eqPairs : ('a * 'a) tree -> int
val treeToList : 'a tree -> 'a list
val height : 'a tree -> int
val balanced : 'a tree -> bool
val subTrees : 'a tree -> 'a tree list
val spring : 'a -> 'a tree -> 'a tree
val fall : 'a tree -> 'a tree
type 'a ntree = NNil | NNode of 'a * 'a ntree list
val nTreeList : 'a ntree -> 'a list
val nTreeListL : 'a ntree list -> 'a list
val nSubTrees : 'a ntree -> 'a ntree list
val nSubTreesL : 'a ntree list -> 'a ntree list
val nSpring : 'a -> 'a ntree -> 'a ntree
val nSpringL : 'a -> 'a ntree list -> 'a ntree list
val nFall : 'a ntree -> 'a ntree
val nFallL : 'a ntree list -> 'a ntree list
val make : 'a list -> 'a tree
val max : 'a tree -> 'a
val getNodeValue : 'a tree tree -> 'a tree
val makeBinInv : 'a list -> 'a tree
val insert : 'a -> 'a tree -> 'a tree
val makeBin : 'a list -> 'a tree
