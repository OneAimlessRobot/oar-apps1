open RandLists
open TreeLiterals
open TimeFunctions
open SortingAlgorithms

let main ()=
	let l= generate_random_list 1000 1000 in
	time (bubbleSort) l;
	time (quickSort) l;
	()

let res= main ()