type 'a ntree = NNil | NNode of 'a * 'a ntree list
val g : int ntree
type 'a forest = 'a ntree list
val h : int ntree
val example_tree : int ntree
val tree_of_height_ten : int ntree
val f : int ntree list
val size : 'a ntree list -> int
val height : 'a ntree list -> int
val map : ('a -> 'b) -> 'a ntree list -> 'b ntree list
val sum : int ntree list -> int
