
open Random;;

init;;

let rec randList n bound=
		match n with
		| 0 ->[]
		| x-> (int (bound))::( randList (n-1) bound)
;;

let rec quickSort l=
		match l with
		| []->[]
		| head::trail-> let (a,b)= partition head trail in
							(quickSort a)	@[head]@ (quickSort b)
			
and partition x l=
		match l with
		| []-> ([],[])
		| head::trail-> let (a,b) = partition x trail in
		 							if head<x then
											(head::a,b)
										else
											(a,head::b)
;;

let rec belongs x list=
	match list with
	| [] -> false
	| head::trail -> head=x || belongs x trail
;;

let x= randList 10 400;;
let y= quickSort x;;


let rec cleanList set=
	match set with
	| []->[]
	| head::trail-> if belongs head trail then
										cleanList trail
									else 
										head::(cleanList trail)
;;

let canonizeList set=
		quickSort (cleanList (set));;
let z= [5;4;1;4;2;1;3;1;4;2;3;3;4];;
cleanList z;;

canonizeList z;;