
open Random

let init_seed () =
  let seed = int_of_float (Unix.time ()) in
  Random.init seed

let random_int_bound bound =
  Random.int bound

let generate_random_list size bound =
  let rec aux n acc =
    if n <= 0 then
      acc
    else
      let random_num = random_int_bound bound in
      aux (n - 1) (random_num :: acc)
  in
  aux size []

let bounded_random_list size bound =
  init_seed ();
  generate_random_list size bound