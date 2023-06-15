
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



let rec belongsWithStringSets x l=
match l with
|[]->false
|head::trail-> if String.equal head x then
                true
                else
                  belongs x trail







let make l=

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
                  in

let rec clean l=
  match l with
  |[]->[]
  |head::trail-> if belongs head trail then
                  clean trail
                  else
                    head:: (clean trail)
                  in
      sort (clean l)



let union l1 l2=
let rec unionAux l1 l2=
    match l1 with
    | []-> l2
    |head::trail-> if belongs head trail then
                    unionAux trail l2
                    else
                  head::(unionAux trail l2)
    in
    make (unionAux l1 l2)


let minus l1 l2=

    let rec minusAux l1 l2=
      match l1 with
      |[]->[]
      |head::trail-> let set= minusAux trail l2 in
                      if belongs head l2 then
                        set
                      else 
                        head::set
                      in
make (minusAux l1 l2)
let rec isContained l1 l2=  
      match l1 with
      |[]-> true
      |head::trail-> if belongs head l2 = false then
                      false
                      else
                      isContained trail l2



let rec isContainedWithStringSets l1 l2=  
      match l1 with
      |[]-> true
      |head::trail-> if belongsWithStringSets head l2 = false then
                      false
                      else
                      isContained trail l2

                      
  let rec invMap f l e=
  match l with
  |[]-> e
  |head::trail-> f head (invMap f trail e)


let inter l1 l2=   
let rec interAux l1 l2=
        match l1 with
        | []->[]
        |head::trail-> if belongs head l2 then
                        head:: (interAux trail l2)
        else
        interAux trail l2
        in
make (interAux l1 l2)

let map f l=
let rec mapAux f l=
        match l with
        |[]->[]
        |head::trail-> (f head)::(mapAux f trail)
      in
(mapAux f l)


let mapForAll f bf l=

let rec mapForAllAux l=
        match l with
        |[]->[]
        |head::trail-> if bf head then
                    (f head)::(mapForAllAux trail)
        else

          (head)::(mapForAllAux trail)
      in
make (mapForAllAux l)



let power l=
let rec powerAux l=
      match l with
      |[]->[[]]
      |head::trail-> let a= powerAux trail in
                      (map (fun x -> head::x) a)@a
    in
powerAux (make l)


let rec length s=
    match s with
    | []->0
    |head::trail -> 1+ length trail

let rec sum s=
    match s with
    | []->0
    |head::trail -> head+ sum trail

let equalSets s1 s2=
let s1m= make s1 in
let s2m=make s2 in
(isContainedWithStringSets s1m s2m) && (isContainedWithStringSets s2m s1m)

let rec filter bf l=
    match l with
    |[]->[]
    |head::trail-> if bf head then
                    head::(filter bf trail)
    else
                  filter bf trail