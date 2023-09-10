open Sets;;
type 'a tree = Nil| Node of 'a * 'a tree * 'a tree
type inttree= int tree
let rec howMany v t = match t with
	|Nil -> 0
	|Node(x,left,right)-> if x=v then
												0 + howMany v left + howMany v right
																				else 
																				1 + howMany v left + howMany v right;;
let rec eqPairs t = match t with
									|Nil -> 0
									|Node((x,y),left,right)-> if x=y then
																				0 + eqPairs left + eqPairs right
																				else 
																				1 + eqPairs left + eqPairs right;;
																																							
																				
let rec treeToList t=
	match t with
	| Nil -> []
	| Node(x,left,right)-> (x::treeToList left)@treeToList right
  ;;		  												
			

let rec height t =
    match t with
    | Nil -> 0
    | Node(x,left,right) ->
           1 + Stdlib.max (height left) (height right)
;;

let rec balanced t=
		match t with
		| Nil-> true
		| Node(x,left, right) ->abs( height left - height  right)<2 && balanced left && balanced right
;;


let rec subTrees t=
		match t with
		| Nil -> [Nil]
		| Node(x,left, right) -> t::(union (subTrees left) (subTrees right))
;;


let rec spring  v t=
		match t with
		| Nil -> Node(v,Nil,Nil)
		| Node(x,left, right) -> Node(x,spring v left,spring v right)
;;

let rec fall t=
		match t with
		| Nil -> failwith "what"
		| Node(x,Nil,Nil)->Nil
		| Node(x,left,right) -> Node(x,fall left,fall right)
;;




let rec make set=
		match set with
		| []->Nil
		| head::trail->Node(head,Nil,make trail)
;;

(* let rec maxTree t=                                                             *)
(* 		match t with                                                               *)
(* 		| Nil-> failwith "??????"                                                  *)
(* 		| Node(x,Nil,Nil) -> x                                                     *)
(* 		| Node(x,left,Nil)-> max x (maxTree left)                                  *)
(* 		| Node(x,Nil,right)-> max x (maxTree right)                                *)
(* 		| Node(x,left,right) -> max (max x (maxTree right)) (max x (maxTree left)) *)
		
(* ;;                                                                             *)

let rec max t=
		match t with
		| Nil-> failwith "??????"
		| Node(x,Nil,Nil) -> x
		| Node(x,left,Nil)-> Stdlib.max x (max left)
		| Node(x,Nil,right)->  Stdlib.max x (max right)
		| Node(x,left,right) ->  Stdlib.max ( Stdlib.max x (max right)) ( Stdlib.max x (max left))
		
;;


let rec makeBinInv set=
		match set with
		| []->Nil
		| head::trail->insert head (makeBinInv trail)
and insert elem t=
		match t with
		| Nil-> Node(elem,Nil,Nil)
		| Node(x,left,right)-> if  elem<x then
														Node(x, insert elem left,right)
														else if elem >x then
														Node(x, left,insert elem right)
															else
																t
;;

let makeBin set=
	makeBinInv (inverse set)
;;


let rec storeTreeAux scanner t=
	match t with
	| Nil -> output_char  scanner  '-'; output_char scanner '\n' 
	| Node(x,left,right) ->output_string  scanner (string_of_int x) ;output_char scanner '\n' ; storeTreeAux scanner right ; storeTreeAux scanner left
;;
let storeTree path t=
	let scanner = open_out path in
			storeTreeAux scanner t;
			close_out scanner;
;;
let rec readTreeAux scanner=
	let s= input_line scanner in
	 if s="-" then Nil
		else let left= readTreeAux scanner in
					let right= readTreeAux scanner in
					Node(int_of_string s, left,right)
	
	
;;


let readTree path=
	let scanner= open_in path in
	readTreeAux scanner
;;


let rec showAux t spaces=
	match t with
	|Nil -> outputNSpacesBefore (spaces+1) "-\n"
	|Node(v,Nil,Nil)-> outputNSpacesBefore (spaces) ((string_of_int v)^"\n")
	|Node(v,left,Nil) -> outputNSpacesBefore (spaces) ((string_of_int v)^"\n"); showAux left (spaces+1);outputNSpacesBefore (spaces+1) "\n"
	|Node(v,Nil,right) -> outputNSpacesBefore (spaces) ((string_of_int v)^"\n"); outputNSpacesBefore (spaces+1) "-\n";showAux right(spaces+1)
	|Node(v,left,right) ->outputNSpacesBefore (spaces) ((string_of_int v)^"\n"); showAux left (spaces+1);showAux right(spaces+1)

and outputNSpacesBefore spaces string =
		match spaces with
		| 0 -> print_string string
		| x -> print_string " ";outputNSpacesBefore (x-1) string
;;


let show t =
	showAux t 0;;



let path = "/media/oneaimlessrobot/Adriano/scripts/OCaml/SintoMeUmaMerda/bigTree.txt";;


let z = show (readTree path);;