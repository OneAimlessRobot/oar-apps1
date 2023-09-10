open Random
let rec fib n=
		if n=0 then 1
		else if n=1 then 1
		else
			fib(n-1)+fib(n-2)
;;
init;;
let x= fib 5;;

let rec randList n bound=
		match n with
		| 0 ->[]
		| x-> (int (bound))::( randList (n-1) bound)
;;

let superList=randList 10000 100;;

let rec len set =
	match set with
	| [] -> 0
	| start ::trail -> 1+ len trail
	
;;

 
let rec succAll set=
	match set with
	| [] -> []
	| start ::trail -> (start+1) :: (succAll trail)
	
;;

let succAll l =
	List.map (fun x -> x+1) l
;;
	
	
	
let rec belongs set x =

	match set with
	|[] -> false
	|head::trail->if head=x then true else belongs trail x	
;;

let rec union setOne setTwo=

	match setOne with
	| [] -> setTwo
	| head::trail -> if (belongs setTwo head) then 
				union trail setTwo
			  else 
			  	head::union trail ( setTwo)
			  	
;;


let rec inter setOne setTwo =

	match setOne  with
	|[]-> []
	|head::trail -> if belongs setTwo head then
				head::inter trail setTwo
			else
				inter trail setTwo
				

;;



let rec conc setOne setTwo =

	match setOne with
	|[] -> setTwo
	|head::trail -> head::conc trail setTwo
;;

 let rec map f x=
 	match x with
 	|[] -> []
 	| head:: trail -> (f head):: (map f trail)
 	
;;
  
let rec powerSet set=
	
	match set with
	|[]->[[]]
	| head::trail -> (powerSet trail)@(map (fun x -> head::x) (powerSet trail))
  			
  
  ;;
  
let rec diff setOne setTwo=
	
	match setOne with
	|[]-> [];
	| head::trail -> if belongs setTwo head then
				diff trail setTwo
			else 
				head:: diff trail setTwo
  ;;
  
(* let rec clear l =                                     *)
(*     match l with                                      *)
(*     | [] -> []                                        *)
(*     | x::xs -> let cl = clear xs in                   *)
(*                 (if belongs x cl then [] else [x])@cl *)
(* ;;                                                    *)

(* let make l = *)
(*     clear l  *)
(* ;;           *)

let rec inverse set=
		match set with
		| []->[]
		| head::trail-> (inverse trail)@[head]
;;

let rec partition p l =
        match l with
        | [] -> ([],[])
        | x::xs ->
               let (a,b) = partition p xs in
                   if x < p then (x::a,b) else (a, x::b)
    ;;
    let rec quickSort l =
        match l with
        | [] -> []
        | x::xs ->
               let (us,vs) = partition x xs in
                   (quickSort us) @ [x] @ (quickSort vs)
    ;;


let rec splitlist l=
	match l with
	| []-> ([],[])
	| [x]->([x],[])
	| [x;y]->([x],[y])
	| head::sHead::trail-> let (a,b) = splitlist trail in
										(head::a,sHead::b)
;;

let rec threePartiteList l=
	match l with
	| []->([],[],[])
	| [x]->([x],[],[])
	| [x;y]->([x],[y],[])
	| [x;y;z]->([x],[y],[z])
	| head::sHead::tHead::trail -> let (a,b,c)= threePartiteList trail in
																(head::a,sHead::b,tHead::c)
	
	
	;;
let rec nSizePartsOfList n set=
	match set with
	| [] -> []
	| head::trail -> let (a,b) = countFirstN n set in
									a::(nSizePartsOfList n b)
									
										
and countFirstN n l=
	match l with
	|[]->([],[])
	| head::trail -> let (a,b) = countFirstN (n-1) trail in
										if n=0 then
											([],l)
										else
											(head::a,b)
;;
  

let nPartiteList n l=
	let size=float_of_int( len l) in
		let partSize= Stdlib.int_of_float( Float.round(size/.(float_of_int n)))  in
			nSizePartsOfList partSize l
;;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
	
