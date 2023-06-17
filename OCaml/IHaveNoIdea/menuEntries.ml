
type entry ={order :int ; input: string;description: string}

let entryfy tup=
  let (x,y,z)= tup in
  {order= x;input= y; description=z}

let tupfy ent=

  (ent.order,ent.input,ent.description)


type menu= entry list

let theMenu=[
entryfy(1,"foo","foo");
entryfy(2,"bar","bar");
entryfy(3,"baz","baz");
entryfy(4,"x","x");
entryfy(5,"viz","viz");
entryfy(6,"y","y");
entryfy(7,"poo","poo")

]