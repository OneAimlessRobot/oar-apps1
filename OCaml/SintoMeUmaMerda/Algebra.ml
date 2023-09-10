type exp =
      Add of exp*exp   (* soma *)
    | Sub of exp*exp   (* subtração *)
    | Mult of exp*exp  (* multiplicação *)
    | Div of exp*exp   (* divisão *)
    | Power of exp*int (* potência *)
    | Sym of exp       (* simétrico *)
    | Const of float   (* constante*)
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

let rec eval f e=
	match e with
	| Const(x)-> x
	| Var -> f
	| Add(x,y) -> eval f x +. eval f y
	| Sub(x,y) -> eval f x -. eval f y
	| Div(x,y) -> eval f x /. eval f y
	| Mult(x,y) -> eval f x *. eval f y
	| Power(x,y) -> power (eval f x) y
	| Sym(x) -> -1.0 *. eval f x

;;



(* type exp = const of float|var| sumexp of (fun exp -> exp +. exp)| subexp of (fun exp -> exp -.exp) | multexp of (fun exp-> exp *.exp) | negexp of (fun exp -> -1*.exp)| fracexp of (fun exp -> exp /. exp);;  *)
