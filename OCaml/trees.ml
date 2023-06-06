
type 'a tree =  Nil | Node of 'a * 'a tree *'a tree
	

	
let listToBinTree l=
let rec listToBinTreeAux l=
	match l with
	|[] -> Nil
	|head::trail ->  insertInTree head ( listToBinTreeAux trail)
and insertInTree  x t=

	match t with
	|Nil-> Node(x,Nil,Nil)
	|Node(y,left,right)-> if x>y then
				Node(y,insertInTree x left,right)
				else if x<y then
				Node(y,left,insertInTree x right)
				else
				t
in


let rec invList l=
	match l with
	|[]->[]
	|head::trail -> (invList trail)@[head]
in

listToBinTreeAux (invList l)




let rec height t=
	match t with
	|Nil -> 0
	|Node(x,Nil,Nil) -> 1
	|Node(x,left,right)-> 1+ (Stdlib.max (height left) (height right))


let rec belongsInTree x t=
	match t with
	|Nil-> false
	|Node(y,left,right) -> y=x || belongsInTree x left || belongsInTree x right
