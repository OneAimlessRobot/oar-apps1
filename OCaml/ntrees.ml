type 'a ntree = NNil | NNode of 'a * 'a ntree list

let g= NNode(8,[NNode(7,[NNode(3,[NNil])]);NNode(10,[NNil]);NNode(9,[NNil])])

type 'a forest = 'a ntree list

let h =
  NNode (20, [
    NNode (6, [
      NNode (7, [NNil]);
      NNode (15, [NNil]);
      NNode (25, [NNil]);
      NNode (40, [NNil]);
      NNode (10, [NNil]);
      NNode (14, [
        NNode (7, [NNil])
      ])
    ])
  ])

let example_tree =
  NNode (1,
    [ NNode (2, []);
      NNode (3,
        [ NNode (4, []);
          NNode (5, []);
          NNode (6, [])
        ]
      );
      NNode (7,
        [ NNode (8, []);
          NNode (9, [])
        ]
      )
    ]
  )
  
let tree_of_height_ten=
  NNode (10, [
    NNode (9, [
      NNode (8, [
        NNode (7, [
          NNode (6, [
            NNode (5, [
              NNode (4, [
                NNode (3, [
                  NNode (2, [
                    NNode (1, [
                      NNode (0, [])
                    ])
                  ])
                ])
              ])
            ])
           ])
          ])
         ])
        ])
       ])
let f= [h;example_tree;tree_of_height_ten];;

let rec size g=


let rec  nSize g=
	match g with
	|NNil->0
	|NNode(x,l)-> 1+ nSizeAux l
	
and nSizeAux l=
	match l with
	|[]->0
	|head::trail-> nSize head + nSizeAux trail
in

match g with
	|[]->0
	|head::trail-> nSize head + size trail





let rec height g=



let rec  nHeight g=
	match g with
	|NNil->0
	|NNode(x,l)-> 1+ nHeightAux l
	
and nHeightAux l=
	match l with
	|[]->0
	|head::trail-> Stdlib.max (nHeight head)  (nHeightAux trail)
in

match g with
	|[]->0
	|head::trail-> Stdlib.max (nHeight head) (height trail)





let rec map f l=

let rec  nMap m t =
	match t with
	|NNil-> failwith "?????"
	|NNode(x,[NNil])-> NNode(m x,[NNil])
	|NNode(x,tl)-> NNode(m x ,nMapAux m tl)
	
and nMapAux g tl=
	match tl with
	|[]->[]
	|head::trail-> (nMap g head):: (nMapAux g trail)
in

match l with
	|[]->[]
	|head::trail-> (nMap f head):: (map f trail)



let rec sum g=

let rec  nSum g =
	match g with
	|NNil->0
	|NNode(x,l)-> x+ nSumAux l
	
and nSumAux l=
	match l with
	|[]->0
	|head::trail-> nSum head + nSumAux trail
in

match g with
	|[]->0
	|head::trail-> nSum head + sum trail


