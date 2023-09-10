	    
type intelPoint = Point of float*float*float;;
type growthStep = Step of intelPoint*intelPoint;;
type intelligence = Path of growthStep list ;;
	    
(*	  *)
(*let myPath = Path([Step((Point((2.0,3.0,4.0)),Point((2.1,2.3,2.5))));Step((Point((2.1,2.3,2.5)),Point((2.4,7.3,5.5))));Step((Point((2.4,7.3,5.5)),Point((5.4,3.3,2.5))))])*)
(*;;*)


type task = Challenge of int
	    | Component of task list
	    ;;

let x = Component([Challenge(1);Component([Challenge(7);Challenge(10);Challenge(9);Challenge(10)]);Component([Challenge(0);Component([]);Challenge(3);Challenge(4);Challenge(5)]);Challenge(3);Challenge(4);Challenge(5)]);;

let rec difficulty task = 

	match task with
	| Challenge(x) -> x
	| Component([]) -> 0
	| Component(head::trail) -> difficulty head + ldifficulty trail
and ldifficulty taskl=

	match taskl with
	| [] ->0
	| head::trail-> difficulty head + ldifficulty trail
;;
	
			
let growthDistance step =
			
		match step with
		| Step((Point(x,y,z),Point(a,b,c))) -> sqrt((x-.a)*.(x-.a)+.(y-.b)*.(y-.b)+.(z-.c)*.(z-.c))
			
		;;
let rec totalGrowth path=

	match path with
	|Path([])->0.0
	|Path(head::trail) -> (growthDistance head) +. (totalGrowthl trail)
and totalGrowthl set =
	match set with
	|[] -> 0.0
	|head::trail -> growthDistance head +. totalGrowthl trail
	
;;

(*let x = Intel.Path([Intel.Step((Intel.Point(2.0,3.0,4.0),Intel.Point(2.1,2.3,2.5)));Intel.Step((Intel.Point(2.1,2.3,2.5),Intel.Point(2.4,7.3,5.5)));Intel.Step((Intel.Point(2.4,7.3,5.5),Intel.Point(5.4,3.3,2.5)))]);;*)
(*	*)

