
let rec size g =
	
	let rec nSize g =
		match g with
		| NNil ->0
		| NNode(x, l) -> 1 + nSizeAux l
	
	and nSizeAux l =
		match l with
		|[]->0
		| head:: trail -> nSize head + nSizeAux trail
	in
	
	match g with
	|[]->0
	| head:: trail -> nSize head + size trail

let rec height g =
	
	let rec nHeight g =
		match g with
		| NNil ->0
		| NNode(x, l) -> 1 + nHeightAux l
	
	and nHeightAux l =
		match l with
		|[]->0
		| head:: trail -> Stdlib.max (nHeight head) (nHeightAux trail)
	in
	
	match g with
	|[]->0
	| head:: trail -> Stdlib.max (nHeight head) (height trail)

let rec tmap f l =
	
	let rec nMap m t =
		match t with
		| NNil -> failwith "?????"
		| NNode(x,[NNil]) -> NNode(m x,[NNil])
		| NNode(x, tl) -> NNode(m x , nMapAux m tl)
	
	and nMapAux g tl =
		match tl with
		|[]->[]
		| head:: trail -> (nMap g head):: (nMapAux g trail)
	in
	
	match l with
	|[]->[]
	| head:: trail -> (nMap f head):: (tmap f trail)

let rec ntreelist l =
	let rec nTreeToList t =
		match t with
		| NNil ->[]
		| NNode(x, l) -> x :: nTreeToListAux l
	
	and nTreeToListAux l =
		match l with
		|[]->[]
		| head:: trail -> (nTreeToList head) @ (nTreeToListAux trail)
	in
	
	match l with
	|[]->[]
	| head:: trail -> (nTreeToList head )@ (ntreelist trail)



let p= ntreelist [tree_of_height_ten;example_tree];;