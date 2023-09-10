
	
	
let rec f set =
	match set with
	| [] -> 0
	| xs :: xl -> xs + f xl
;;	



let rec nDeleteAux set it=
	if it <0 || it =0 then set else
	match set with
	| [] -> []
	| x:: finish -> nDeleteAux finish (it-1)
	
;;

let rec nGetAux set it elem=
	if it <0 || it =0 then elem else
	match set with
	| [] -> 0
	| x:: finish -> nGetAux finish (it-1) x
	
;;
let nGet set n=
	
	nGetAux set n 0

;;

let nDelete set n=
	nDeleteAux set n
;;

(* let rec splitListAux  aux set n initLen=                                        *)

(* 	if n=initLen                                                                  *)
(* 	then                                                                          *)
(* 		[aux;set]                                                                   *)
(* 	else                                                                          *)
(* 		splitListAux (nGet set ((len set) -n)::aux) (nDelete set 1) (n+1) (initLen) *)
		
(* ;;                                                                              *)
		

let rec printListAux set =
	
	if set = [] 
	then 
	() 
	else
	print_int (nGet set 1);
	printListAux (nDelete set 1)
	
;;

let printList set =

		
	print_string "\n";
	printListAux set;
	
;;


let rec belongsAux x current set=
	
	if set=[] then
		false
	else if x=current then
			true
		else
			belongsAux x (nGet set 1) (nDelete set 1)
			
;;

(*let rec rem set x=*)
(*	match x with*)
(*	| [] -> []*)
(*	|*)
(*	| start :: trail ->*)
print_int (f [1;2;3;4;5]);;
print_string "\n";;



(*printList ([1;2;3;4;5]);;*)

(*Metodo indutivo: pensar de forma abstrata: como? E se nao receber apoio? Sinto dificuldade... O stor estava a brincar... mas... algo no que ele disse fez sentido para mim. A mentalidade de 1º ciclo dos meus colegas tambem nao ajuda muito... Mas esta forma de pensar faz-me muita falta... o meu erro e pensar operacionalmente. E mais facil pensar de forma abstrata nestes casos, aceitar que as abstracoes estao feitas para nos ajudar, e que nao sao coisas em que nos devemos focar muito no concreto... chegou a altura de enfrentar algo que me assusta bastante. *)



(*ex:*)


let rec map f l=
	match l with
	|[] -> []
	| x::xs -> f x::map f xs
;;

(*Ser expedito... como ser expedito... sera uma questao de coragem? Genetica? Educacao? Eu estou demasiado consciente de que nao sou capaz de ser expedito. E um vazio muito grande em mim. *)

let rec ins v l =

	match l with
	|[] -> [v]
	| x::xs -> if v < x then v::l
		   else x:: ins v xs
		   
;;
let rec sortList l =
	match l with
	| [] -> []
	| x::xs -> ins x (sortList xs)
;;

(*Bem... tenho algo em que refletir... se ha alguma altura em que tenho de encontrar coragem para nao colapsar em desordem, e de certeza agora...

Tenho de pensar... sera que estou aqui por coincidencia? Sera que nao poderiam estar pessoas mais competentes no meu lugar?.... anyways. Como criar variaveis "nao acumulaveis" dentro de funcoes?
 Temos uma funcao Assim:*)


(*como obtemos essa var se precisarmos?*)


 
 
 


