
let rec invList l=
	match l with
	|[]->[]
	|head::trail -> (invList trail)@[head]


let rec belongs x l=
  match l with
  |[]->false
  |head::trail-> if head= x then
                  true
                  else
                    belongs x trail


let rec clean l=
  match l with
  |[]->[]
  |head::trail-> if belongs head trail then
                  clean trail
                  else
                    head:: (clean trail)

let union l1 l2=
let rec unionAux l1 l2=
    match l1 with
    | []-> l2
    |head::trail-> if belongs head trail then
                    unionAux trail l2
                    else
                  head::(unionAux trail l2)
    in
    clean (unionAux l1 l2)






let rec sort l=

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
                        (sort l)@ [head]@ (sort r)


let make l=
      sort (clean l)
                
