   
	(*O objetivo de programacao funcional e simplificar problemas Uma funcao recursiva iconica em ocaml:*)
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

(* funcoes de categoria 1: *)

(* let rec f n=                                                *)
(* 	if n=0 then ...                                           *)
(* 	else ..... f(n-1).....                                    *)
(* ;;                                                          *)

(* let rec f l                                                 *)
(* 	match l with                                              *)
(* 	| []-> ...                                                *)
(* 	| x::xs -> ....f xs ....                                  *)
(* ;;                                                          *)

(* let rec f t =                                               *)
(* 		match t with                                            *)
(* 		| Nil-> ...                                             *)
(* 		| Node(x,left,right) -> ...... f left ......f right.... *)
(* ;;                                                          *)

(* let rec f t=                                           *)
(* 		match t with                                       *)
(* 		| NNil-> ....                                      *)
(* 		| NNode(x,l)-> ....... f x ..... fl l              *)
(* and fl l=                                              *)
(* 		match l with                                       *)
(* 		| []-> ......                                      *)
(* 		| head::trail -> ...... f head ..... fl trail..... *)
(* ;;                                                     *)
	
	
(*NOTA: Tudo o que esta  num let-in funciona para baixo do in *)

(*Estas funcoes sao as de categoria 1. Sao as mais simples. Sao as que obececem `Aqueles padroes. Podem envolver varias funcoes desta categoria podem envolver varios esquemas daqueles. E teem de obedecer aquele esquema exato para ser de categoria 1. *)
(* Mais delas:*)

(* stringAsList: converte string em lista de caracteres                      *)
(*     let cut s = (String.get s 0, String.sub s 1 ((String.length s)-1)) ;; *)
(*     let rec stringAsList s =                                              *)
(*         if s = "" then []                                                 *)
(*         else                                                              *)
(*             let (x,xs) = cut s in                                         *)
(*                 x::stringAsList xs                                        *)
(*     ;;                                                                    *)

(* sortList: ordena lista                                                    *)
(*     let rec insOrd v l =                                                  *)
(*         match l with                                                      *)
(*         | [] -> [v]                                                       *)
(*         | x::xs ->                                                        *)
(*               if v <= x then v::x::xs                                     *)
(*               else x::insOrd v xs                                         *)
(*     ;;                                                                    *)
(*     let rec sortList l =                                                  *)
(*         match l with                                                      *)
(*         | [] -> []                                                        *)
(*         | x::xs ->                                                        *)
(*               insOrd x (sortList xs)                                      *)
(*     ;;                                                                    *)




(*FUNCOES DE CATEGORIA 2:*)

(* halfHalf: reparte os elementos duma lista por duas listas, alternadamente                        *)
(*      (esta versão é programada com base na ideia de processar os elementos da lista dois a dois) *)
    (* let rec halfHalf l =                     *)
    (*     match l with                         *)
    (*     | [] -> ([],[])                      *)
    (*     | [x] -> ([x],[])                    *)
    (*     | x::y::xs ->                        *)
    (*             let (us,vs) = halfHalf xs in *)
    (*                 (x::us, y::vs)           *)
    (* ;;                                       *)

(*Dica para perceber mais facilmente este algoritmo: Se a lista for ordenada *)
(* de inteiros consecutivos e começar num par, os pares vao para a lista da *)
(* esquerda*)
(* E os impares vao para a direita. Os impares vao para a esquerda.  *)

(*Vee o output disto: *)

(* halfHalf [2;3;4;5;6;7];; *)


(*E uma categoria nova porque esta funcoes usam ferramentas de pensar que aumentam as nossas possibilidades.*)
(* Existem certos problemas que nao sao resoluveis em categoria 1.*)

(*Vou tentar resolver em categoria 1: *)

(* LET REC HALFHALFONE p=                        *)
(* 		MATCH p WITH                              *)
(* 		| ([],[])-> []                            *)
(* 		| HEAD::sHead::TRAIL-> (HEAD::HALFHALFONE *)

(*Habituaamo-nos a primeira categoria. Este e outro nivel. *)
(**)
(* *)
(* *)
(* CATEGORA 3 *)


(*E preciso ser-se mais organizado para resolver os problemas. Mais pensamento abstrato. *)


(*O quicksort e uma funcao de categoria 3:*)
(* *)
 let rec partition p l =
        match l with
        | [] -> ([],[])
        | x::xs ->
               let (a,b) = partition p xs in
                   if x <= p then (x::a,b) else (a, x::b)
    ;;
    let rec quickSort l =
        match l with
        | [] -> []
        | x::xs ->
               let (us,vs) = partition x xs in
                   (quickSort us) @ [x] @ (quickSort vs)
    ;;
 
let rec removeFromList v l =
        match l with
        | [] -> []
        | x::xs ->
                 if x = v then xs
                 else x::removeFromList v xs
    ;;

(* Categoria 1 -> segue um dos padroes rigidos enumerados acima *)
    let rec minList l =
        match l with
				| []-> failwith "??????"
        | [x] -> x
        | x::xs -> min x (minList xs)
    ;;

(* Categoria 2 -> Exste um pequeno desvio do padrao, pois nao existe caso base para o vazio. *)
    let rec minSort l =
        match l with
        | [] -> []
        | list ->
              let m = minList list in
                  m::minSort (removeFromList m list)
    ;;
(* Categoria 3 -> O argumento da chamada recursiva e obtido a partir de calculos do proprio  *)
(* Argumento em vez de ser um pattern matching.                                              *)

(* Esta funcao necessita de maior expressividade. E e menos eficiente. Esta e de categoria 3 *)
(* devido ao argumento da chamada recursiva da funcao principal                              *)
(* Categoria 3                                                                               *)
 
(*Os argumentos do passo das funcoes de categoria 3 sao calculados. Nao usamos diretamente os argumentos. E mais artificial. Menos intuitivo. *)
(* *)
(*  *)
(* *)

	let result1=quickSort superList;;
	let result2=minSort superList;;

	