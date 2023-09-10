val pack : 'a list -> ('a * int) list
val countEq : 'a -> 'a list -> int
val skipSame : 'a -> 'a list -> ('a * int) list
val unpack : ('a * int) list -> 'a list
val miniUnpack : 'a * int -> 'a list
