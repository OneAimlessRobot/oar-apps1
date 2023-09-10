
let rec pack x=
		match x with
		| [] -> []
		| head::trail -> (head,countEq head x):: skipSame head x
													
			
and countEq num x=
		match x with
		| [] -> 0
		| head::trail -> if head=num then
															1 + (countEq num trail)
														else
															countEq head []
																													

and skipSame x set=
		match set with
		| []->[]
		| head::trail-> if head=x then
														skipSame x trail
										else
												pack set  																	
;;
let rec unpack x=
		match x with
		| []->[]
		| head::trail-> (miniUnpack head) @ (unpack trail)

and miniUnpack (x,y)=
			match (x,y) with
			| (x,1)-> [x]
			| (x,y)-> x:: miniUnpack(x, y-1)
;;

