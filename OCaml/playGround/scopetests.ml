open RandLists
open TreeLiterals
open TimeFunctions
open SortingAlgorithms
open Operationalize

let main ()=
	let l= generate_random_list 10000 1000 in
	let m=time (quickSort) l in
	if (isSorted m false) then
		print_string "is sorted.\n"
	else
		print_string "does not work\n";
	()

let res= main ()


(*let main ()=
	let l= generate_random_list 10 1000 in
	let m=time (quickSort) l in
	List.map (fun x->print_int x;print_string " ") m
let res= main ()*)

