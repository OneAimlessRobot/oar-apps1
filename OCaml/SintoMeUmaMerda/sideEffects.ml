open Sys ;;
open Unix;;

command "ls -l"


let rec copyChannel ci co =
    try
        let s = input_line ci in
            output_string co s ;
            output_string co "\n" ;
            copyChannel ci co
    with End_of_file -> ()
;;

(* copyFile: abre os ficheiros ni e depois usa a função copyChannel *)

let copyFile ni no =
    let ci = open_in ni in
        let co = open_out no in
            copyChannel ci co ;
            close_in ci ;
            close_out co
;;
chdir ("/media/oneaimlessrobot/"^"Seagate Basic"^"/Adriano/scripts/OCaml/SintoMeUmaMerda");;
let file1= "file1";;
let file2= "file2";;
let x=copyFile file1 file2;;