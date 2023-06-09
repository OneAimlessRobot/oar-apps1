

let rec validate g =
  if g.vexes = [] then
    false
  else
    let rec validateAux el =
      match el with
      | [] -> true
      | (a, b)  :: trail ->
          (belongs a g.vexes && belongs b g.vexes) && validateAux trail
    in
    validateAux g.edges

  

let makeChainGraph init num=

if num<init then
  failwith "num less than init!!!"
else
let rec makeVexes num=
  match num with
  |n when n= init ->[n]
  |x-> x::(makeVexes (x-1))
  in

let rec linkTogether list=
  match list with
  |[]->[]
  |[x]->[]
  |head::sHead::trail-> (head,sHead)::(linkTogether (sHead::trail))
in

{vexes= (invList (makeVexes num));edges= linkTogether (invList (makeVexes num))}


let next v g=
  if belongs v g.vexes = false then
    failwith "No such vertex to calculate next of in given graph"
  else
    let rec nextAux el=
      match el with
      |[]->[]
      |(a,b)::trail-> if a= v then
                      b::(nextAux trail)
      else
          nextAux trail
      in
    nextAux g.edges


let prev v g=
    if belongs v g.vexes = false then
      failwith "No such vertex to calculate next of in given graph"
    else
      let rec prevAux el=
        match el with
        |[]->[]
        |(a,b)::trail-> if b= v then
                        a::(prevAux trail)
        else
            prevAux trail
        in
      prevAux g.edges
  
  
let adjacent v g=
if belongs v g.vexes = false then
  failwith "No such vertex to calculate next of in given graph"
else
        union (next v g) (prev v g)

let linear = makeChainGraph (1)

let nextOfList nl g=
if validate g= false then 
  failwith "Invalid graph!!!!"
else
  let rec nextOfListAux nl =
    match nl with
    |[]->[]
    |head::trail->union (next head g) (nextOfListAux trail)
  in
  nextOfListAux nl

let reachable v g =
  if validate g= false then 
    failwith "Invalid graph!!!!"
  else
    let rec reachableAux nl=
      match nl with
      |[]->[]
      |head::trail-> union (nl) (reachableAux (next head g))
  in
  reachableAux (next v g)

let rec uniteGraphs g1 g2=

if validate g1= false ||validate g2= false then 
  failwith "Invalid graph!!!!"
else
  {vexes= union g1.vexes g2.vexes; edges= union g1.edges g2.edges}


let graphConnectsSets s1 s2 g= 

  if not( (isContained s1 g.vexes)&&(isContained s2 g.vexes)) then
    false
  else
let rec graphUnitesVexSetsAux s1 s2 es=
    match es with
    |[]->false
    |(a,b)::trail-> (belongs a s1 && belongs b s2) || (graphUnitesVexSetsAux s1 s2 trail)

    in
    graphUnitesVexSetsAux s1 s2 g.edges

let rec islands g=

if validate g= false then 
  failwith "Invalid graph!!!!"
else
    let rec adjacentList vl=
      match vl with
      |[]-> []
      |head::trail->union (adjacent head g) (adjacentList trail)
in
    let rec explore vl=
      let step= union vl (adjacentList vl) in
      match step with
      |n when n= vl -> vl
      |x-> explore step
      in
    let rec islandsAux vl=
      match vl with
      |[]->[]
      |head::trail->  (explore [head]) ::( islandsAux (minus vl (explore [head])) )
    in
  islandsAux g.vexes


let fixGraph g=

    if g.vexes =[] then
      failwith "Nothing to be done!"
    else
    let rec fixEdges es=
     match es with
     |[]->[]
     |(a,b)::trail-> if not(belongs a g.vexes)||not(belongs b g.vexes) then
                      fixEdges trail
                      else
                      (a,b)::(fixEdges trail)
                      in
    let rec fixVexes vs=
    match vs with
    |[]->[]
    |head::trail-> if adjacent head g=[] then
                    fixVexes trail
    else
                head::(fixVexes trail)
    in

    {vexes= fixVexes( make g.vexes); edges= fixEdges (make g.edges)}
