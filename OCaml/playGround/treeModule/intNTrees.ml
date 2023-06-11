
open TreeLiterals
let rec tsum g =
	
	let rec nSum g =
		match g with
		| NNil ->0
		| NNode(x, l) -> x + nSumAux l
	
	and nSumAux l =
		match l with
		|[]->0
		| head:: trail -> nSum head + nSumAux trail
	in
	
	match g with
	|[]->0
	| head:: trail -> nSum head + tsum trail
