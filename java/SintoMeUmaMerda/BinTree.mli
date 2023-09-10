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
val make : 'a list -> 'a tree
val max : 'a tree -> 'a
val makeBinInv : 'a list -> 'a tree
val insert : 'a -> 'a tree -> 'a tree
val makeBin : 'a list -> 'a tree
val storeTreeAux : out_channel -> int tree -> unit
val storeTree : string -> int tree -> unit
val readTreeAux : in_channel -> int tree
val readTree : string -> int tree
val showAux : int tree -> int -> unit
val outputNSpacesBefore : int -> string -> unit
val show : int tree -> unit
val path : string
val z : unit
