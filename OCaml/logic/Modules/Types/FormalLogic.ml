
type logicExpr =
		Literal 
		|Value of bool
		|Neg of logicExpr
		|Conj of logicExpr*logicExpr
		|Disj of logicExpr*logicExpr
		|Impl of logicExpr*logicExpr	

			
	

let rec eval  e=
        match e with
        | Value(x)-> x
        | Literal -> f
        | Disj(x,y) -> eval x || eval y
        | Conj(x,y) -> eval x && eval y
        | Impl(x,y) -> (not eval x)  || (eval y)
        | Neg(x) -> not eval x

;;
	
		
			}




