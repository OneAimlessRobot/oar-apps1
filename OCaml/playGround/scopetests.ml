
open NTrees
let weirdSum x=
let rec g x=
	h (x+1)
	
and h x =
	if x>=3 then
	 x
	else
	 g x
in
let f x=
	
	g (x+1)
	
in
f x

let main ()=
	let nums= [1;8;10;2;12;40;30;20] in
	print_int (Trees.height (Trees.listToBinTree nums)); print_newline ();;
main ()
