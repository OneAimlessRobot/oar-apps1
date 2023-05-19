type 'a tree =  Nil 
	| Node of 'a * 'a tree *'a tree;;
	


let rec listSum l=
	match l with
	| []->0
	|head::trail -> head+ (listSum trail);;
	
	
let main () =
	let x= [1;2;3;4;5;6;7;8;9;10] in
		let m= listSum x in
		print_int m; print_newline ();;
		
main();;
