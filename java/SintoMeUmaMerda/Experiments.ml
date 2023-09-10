let rec firstNat x=
		match x with
		|0 -> []
		|x -> x-1::(firstNat (x-1))
	
;;

firstNat 7

let rec modAux(m,n)= if (m-n)<=0 then n-m else modAux(m-n, n);;

let rec f  (m,n) = if n=0 then m else f(n,modAux(m,n));;
let inc n= (n+1);;

let rec quotientAux (m,n,x) = if (m-n)<=0 then x else quotientAux(m-n, n,inc x);;

let quotient(m,n) = quotientAux(m,n,0);;



let bitMoreThan x =
	x +. 0.001

;;

let prev n =
	n-1
;;
let rec nDeriv f n x =
	if n =0 then
		f x
	else 
		((nDeriv f (prev n) (bitMoreThan x)) -. (nDeriv f (prev n ) (x)))/.((bitMoreThan x) -. x )

;;
