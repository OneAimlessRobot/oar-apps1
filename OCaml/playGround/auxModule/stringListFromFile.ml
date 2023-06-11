




let fileInString fileName=
  let input= open_in fileName in
    let rec convertIntoString ch=
      input_line ch 
in
  convertIntoString input



let convertStringIntoSet str=
    String.split_on_char ' ' str