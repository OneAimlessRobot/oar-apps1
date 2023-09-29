type exp =
      Add of (float -> float)*exp   (* soma *)
    | Sub of (float -> float)*exp   (* subtração *)
    | Mult of (float -> float)*exp  (* multiplicação *)
    | Div of (float -> float)*exp   (* divisão *)
    | Power of (float -> float)*int (* potência *)
    | Sym of exp       (* simétrico *)
    | Const of (float -> float)   (* constante*)
    | Var              (* variável *)
;;

let rec power g e=
		if g < 0.0 then
			failwith "baseNegativa"
		else if e < 0 then
			failwith "Exponente negativo"
		else if e = 0 then 1.0
		else g *. power g (e-1)
		;;

let rec eval v e=
	match e with
	| Const(x)-> fun p -> x
	| Var -> fun x -> x
	| Add(x,y) -> fun x y -> x v +. eval v y
	| Sub(x,y) -> fun x y -> x v -. eval v y
	| Div(x,y) -> fun x y -> eval v x /. eval v y
	| Mult(x,y) -> fun x y -> eval v x *. eval v y
	| Power(x,y) -> fun x y -> power (eval v x) y
	| Sym(x) -> fun x y -> -1.0 *. eval v x

;;



(* type exp = const of float|var| sumexp of (fun exp -> exp +. exp)| subexp of (fun exp -> exp -.exp) | multexp of (fun exp-> exp *.exp) | negexp of (fun exp -> -1*.exp)| fracexp of (fun exp -> exp /. exp);;  *)
