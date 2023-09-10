open Sets;;
type 'a tree = Nil| Node of 'a * 'a tree * 'a tree

type inttree = int tree;;

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

























type 'a ntree= NNil | NNode of 'a * 'a ntree list;;

let rec nTreeList t=
			match t with
			| NNil -> []
			| NNode(x,l) -> x::(nTreeListL l)
			
and nTreeListL tl =
	
			match tl with
			| [] -> []
			| head::trail-> ((nTreeList head)@(nTreeListL trail))

;;


let rec nSubTrees t=
			match t with
			| NNil -> [NNil]
			| NNode(x,l) -> t::(nSubTreesL l)
			
and nSubTreesL tl =
	
			match tl with
			| [] -> []
			| head::trail-> (union (nSubTrees head) (nSubTreesL trail))

;;


let rec nSpring v t=
			match t with
			| NNil -> NNode(v,[])
			| NNode(x,l) -> NNode(x,(nSpringL v l))
			
and nSpringL v tl =
	
			match tl with
			| [] -> []
			| head::trail-> (nSpring v head)::(nSpringL v trail)

;;


let rec nFall t=
			match t with
			| NNil -> failwith "???????"
			| NNode(x,[]) -> NNil
			| NNode(x,l) -> NNode(x,(nFallL l))
			
and nFallL tl =
	
			match tl with
			| [] -> []
			| head::trail-> (nFall head)::(nFallL trail)

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


let getNodeValue t=
	match t with
	| Nil->Nil
	| Node(x,y,z)-> x
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
