type 'a tree = Nil | Node of 'a * 'a tree * 'a tree
val listToBinTree : 'a list -> 'a tree
val height : 'a tree -> int
val belongsInTree : 'a -> 'a tree -> bool
