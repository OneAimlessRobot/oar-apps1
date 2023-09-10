type exp =
    Add of exp * exp
  | Sub of exp * exp
  | Mult of exp * exp
  | Div of exp * exp
  | Power of exp * int
  | Sym of exp
  | Const of float
  | Var
val power : float -> int -> float
val eval : float -> exp -> float
