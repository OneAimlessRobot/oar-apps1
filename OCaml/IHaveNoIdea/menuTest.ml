open MenuEntries

let rec printMenu menu=
  match menu with
  |[]->()
  |head::trail-> print_int (head.order);print_string " - ";print_string (head.description);print_string "\n"; printMenu trail

let rec processOption option menu=
  match menu with
  |[]-> ""
  |head::trail-> if String.equal head.input  option then
                    head.description
  else
                    processOption option trail

let rec main ()=
printMenu theMenu;
print_string (processOption (read_line ()) theMenu)
;;


main ()
