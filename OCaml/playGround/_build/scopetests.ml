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
	print_int (Ntrees.height [Ntrees.g]);print_newline ();print_int (Operationalize.computeDifficulty Operationalize.example); print_newline ();;
main ()
