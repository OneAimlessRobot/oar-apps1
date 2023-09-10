(* Maze module body *)
(* LAP (AMD 2023) *)

(* 
Student 1: ????? mandatory to fill
Student 2: ????? mandatory to fill

Comment:

?????????????????????????
?????????????????????????
?????????????????????????
?????????????????????????
?????????????????????????
?????????????????????????

*)

(*
0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789
	100 columns
*)


(* COMPILATION - How Mooshak builds this module:
		ocamlc -c Maze.mli Maze.ml
*)



(* AUXILIARY GENERAL FUNCTIONS - you can add more *)

(* Sorted lists with no repetitions *)
(* precondition for all the list arguments:
		isCanonical l && isCanonical l1 && isCanonical l2 *)
(* postcondition for all the list results: isCanonical result *)

let rec removeDups z = (* pre: z sorted *)
	match z with
	| [] -> []
	| [x] -> [x]
	| x::y::xs -> (if x = y then [] else [x])@ removeDups (y::xs)
;;

let canonize z = (* sort and remove duplicates *)
	removeDups (List.sort compare z)
;;

let isCanonical z = (* check if sorted and with no duplicates *)
	z = (canonize z)
;;

let belongs v l =
	List.mem v l
;;

let length =
	List.length
;;

let filter =
	List.filter
;;

let exists =
	List.exists
;;

let for_all =
	List.for_all
;;

let partition =
	List.partition
;;

let contained l1 l2 =
	for_all (fun x -> belongs x l2) l1
;;

let union l1 l2 =
	canonize (l1@l2)

let inter l1 l2 =
	filter (fun x -> belongs x l2) l1
;;

let diff l1 l2 =
	filter (fun a -> not (belongs a l2)) l1
;;

let map f l =
	canonize (List.map f l)
;;

let merge l =
	canonize (List.flatten l)
;;

let flatMap f l =
	merge (List.map f l)
;;

let showi l =
	let li = List.map string_of_int l in
	let body = String.concat "," li in
		Printf.printf "[%s]\n" body
;;

let showp l =
	let li = List.map (fun (a,b) -> Printf.sprintf "(%d,%d)" a b) l in
	let body = String.concat "," li in
		Printf.printf "[%s]\n" body
;;

(* TYPES & CONSTANTS *)

type room = int
type rooms = room list

type path = room list
type island = room list

type passage = room * room
type passages = passage list

type maze = {
    rooms: rooms;
	entrances: rooms;
    exits: rooms;
    passages: passages
}

let _NO_PATH = []


(* SOME EXAMPLES - you can add more *)

let myMaze = {
    rooms = [1; 2; 3; 4; 5; 6; 7; 8; 9; 10; 11; 12; 13];
	entrances = [1;4;11];
    exits = [6;12];
    passages = [(1,2);(1,4);(1,5);(2,5);(3,6);(4,5);(4,7);
				(5,6);(5,8);(6,9);(7,8);(8,9);(10,11);(11,12)]
};;

let otherMaze = {
    rooms = [1; 2; 3; 4; 5; 6; 7;8;9;10;11;12];
	entrances = [1;4;7];
    exits = [6];
    passages = [(1,2);(1,4);(1,3);(3,5);(3,6);(4,6);(7,4);
		(7,8);(8,9);(9,10);(10,11)]
};;

let loopMaze = {
    rooms = [1;2;3;4];
	entrances = [1];
    exits = [4];
    passages = [(1,2);(2,3);(3,4);(4,1)]
};;

(* FUNCTION isValid *)
let rec pathsAreValid m set=
		match set with
		| []-> true
		| head::trail-> let (a,b) = head in
										(belongs a m.rooms) && (belongs b m.rooms) && (pathsAreValid m trail)
;;
let isValid m =
	length (m.rooms) > 0 && length (m.entrances) >0 && (contained m.exits m.rooms) &&(contained m.entrances m.rooms)&&(pathsAreValid m m.passages)
;;

(* FUNCTION makeLineMaze *)
let rec makeList x y=
								if x>y then
								failwith "O a tem de ser <= que o b"
								else if x=y then
								[x]
								else
								x:: makeList (x+1) y
;;
let rec makeChain x= match x with	
									 					|[]-> failwith "a tem de ser < que o b"
														|[a]-> []
														|head::sHead::trail-> (head,sHead)::(makeChain (sHead::trail))
;;
let makeLineMaze a b = 
	{rooms= makeList a b;
								entrances= [a]; 
								exits= [b];
								passages= makeChain (makeList a b)}
;;

(* FUNCTION combine *)

let combine m1 m2 = 
	{rooms = union m1.rooms m2.rooms; 
	 entrances = union m1.entrances m2.entrances;
	 exits = union m1.exits m2.exits; 
	 passages= union m1.passages m2.passages}
;;
(* FUNCTION next *)

let rec nextAux set r=
	match set with
	| []->[]
	| (a,b)::trail-> if a= r then
										b::(nextAux trail r)
										else 
											nextAux trail r
;;

let next m r = 
	nextAux m.passages r
;;


(* FUNCTION next2 *)

let rec next2Aux passageSet roomSet=
	match roomSet with
	| [] -> []
	| head::trail->union (nextAux passageSet head) (next2Aux passageSet trail)
;;

let next2 m r = 
	
		next2Aux m.passages r
	
;;

(* FUNCTION prev *)

let rec prevAux set r=
	match set with
	| []->[]
	| (a,b)::trail-> if b = r then
										a::(prevAux trail r)
										else 
											prevAux trail r
;;

let prev m r = 
	prevAux m.passages r
;;

(* FUNCTION adjacent *)

let adjacent m r = 
	union (next m r) (prev m r)
;;

(* FUNCTION reachable *)
let rec reachableAux m set=
		match set with
		| []-> []
		| head::trail -> let l= next m head in
										head::(union (reachableAux m trail) (reachableAux m l))

;;                                                                          
let reachable m=
	reachableAux m m.entrances
;;

(* FUNCTION solitary *)
let rec solitaryAux m set=
	match set with
	| []-> []
	| head::trail -> if (adjacent m head) = [] then
										head::(solitaryAux m trail)
									else 
										solitaryAux m trail
;;
let solitary m = 
	solitaryAux m m.rooms
;;

(* FUNCTION leafRoom *)

let isLeafRoom m r=
	next m r = []
;;

(* FUNCTION islands *)


let rec explore m set=
	let x= adjacent2 m set in
	if x=set then
		set
	else
		explore m x
		
and adjacent2 m set=
	match set with
	| []->[]
	| head::trail-> union (union [head] (adjacent m head)) (adjacent2 m trail)
;;

let rec islandsAux m set=
	match set with
	| []->[]
	| head::trail -> let x= explore m [head] in
									x::(islandsAux m (diff set x))
;;
let rec islands m=
	islandsAux m m.rooms
;;

(* FUNCTION shortest *)
let rec distanceFromAux m set room2=
		if set =[] then
			failwith "Unreachable room in distance function"
	 else if belongs room2 set then
		0
		else
		1+ (distanceFromAux m (next2 m set) room2)
;;
let distanceFrom m room1 room2=
	distanceFromAux m [room1] room2
;;
(* Vou ter de fazer uma funcao que aceita todos os rooms do maze como argumento.*)
(* Depois percorro alguns deles e retiro-os na proxima chamada*)
(* Vou armazenando todas as paths.*)
(* Tenho de criar uma funçao que calcule a path mais pequena... Mas como?*)
(* Posso, se calhar, pegar numa room, depois fazer o next. Mas como faço as paths?*)
(* Sera que posso... olha nao faço ideia... *)
let shortest m =
	_NO_PATH
;;

(* FUNCTION paths *)


let rec auxNextaux set r=
	match set with
	| []->[]
	| (a,b)::trail-> if a= r then
										[b]::(auxNextaux trail r)
										else 
											auxNextaux trail r
;;

let auxNext m r = 
	auxNextaux m.passages r
;;

let rec concatSep ll l=
	match ll with
	| []->[]
	| head::trail-> let (a,b)= xtracHead l in
									(a::head)::(concatSep trail b)
		
and xtracHead l=
	match l with
	| []->failwith "cabeca de lista vazia em concatSep"
	| head::trail-> (head,trail)
;;

let rec countPaths m en ex=
	match en with
	| []->0
	| head::trail-> let ls= next m head in
									if belongs head ex then
											1+(countPaths m ls ex) +(countPaths m trail ex)
											else
											0+ (countPaths m ls ex) +(countPaths m trail ex)
	
;;

let rec conc ll x= 
	match ll with
	| []->[]
	| head::trail-> (x::head)::(conc trail x)
;;

(* let rec producePaths m en ex=                                          *)
(* 	match en with                                                        *)
(* 	| []->[]                                                             *)
(* 	| head::trail->	let ls= auxNext m head in                           *)
(* 									if belongs head ex then                              *)
(* 											1+(countPaths m ls ex) +(countPaths m trail ex)  *)
(* 											else                                             *)
(* 											0+ (countPaths m ls ex) +(countPaths m trail ex) *)
				
let rec getLast l=
	match l with
	| []-> failwith "Lista vazia no getLast"
	| [x]->x
	| head::trail -> getLast trail
;;

let rec multListAux m l lr=
	match lr with
	| []->[]
	| head::trail->(l@[head])::(multListAux m l trail)
										
and multListOfLists m ll=
	match ll with
	| []->[]
	| head::trail-> 
										(multList m head)@(multListOfLists m trail)
and multList m l=
	let x= getLast l in
	let y= next m x in
	multListAux m l y
and multListOfListsMore m en ex=
	match en with
	| []->[]
	| head::trail-> let x= multList m [head] in
									let y= multListOfLists m x in
x@(multListOfLists m x)@(multListOfLists m y)@(multListOfListsMore m trail ex)
	
	
;;

let paths m = 
	[]
;;

(* FUNCTION hasLoop *)

let hasLoop m = 
	false
;;

(* FUNCTION shortest2 *)

let shortest2 m = 
	_NO_PATH
;;



(*Este e o meu take 2 de resolver isto. ja nao vai dar mais pontos. Mas vou, pelo menos, fazer o paths *)
let time f x =
    let t = Sys.time() in
    let fx = f x in
    Printf.printf "Execution time: %fs\n" (Sys.time() -. t);
    fx
;;
let main ()=
	time islands myMaze
;;

let y= main ();;

(*GG i give up fn *)