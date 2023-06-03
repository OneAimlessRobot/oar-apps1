let x= "(ab+bb)*";;
let y= "(ab+bb)*(aa+ba)";;
(*
Operador ^ concatena	
*)
let z= "(ab+bb)" ;;
let w= z^y;;
let n= "(aa+ba+"^w^")*";;
let h= "(ab+bb)(ab+bb)*";;
let k= n^h;;
let total= y^x^k^"+"^x;;
