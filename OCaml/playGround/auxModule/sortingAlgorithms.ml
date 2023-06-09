



let rec quickSort l=

let rec partition x l=
    match l with
    |[]->([],[])
    |head::trail-> let (a,b) = partition x trail in
                    if head>=x then
                      (a,head::b)
                    else
                      (head::a,b)
                    in
    match l with
    |[]->[]
    |head::trail-> let (l,r)= partition head trail in
                        (quickSort l)@ [head]@ (quickSort r)
       
                        


let rec bubbleSort lst =
  let rec bubblePass lst =
    match lst with
    | x :: y :: rest ->
        if x > y then
          y :: bubblePass (x :: rest)
        else
          x :: bubblePass (y :: rest)
    | _ -> lst
  in
  let sortedLst = bubblePass lst in
  if sortedLst = lst then
    lst
  else
    bubbleSort sortedLst