

type task = string * int

type challenge = Choice of challenge list | Option of task



let example = Choice [Choice [Option("estudar Lap",1);Option("lavar roupa",9);Option("ir as compras",10);Choice([])] ;Option("Treinar haskell",6);Choice [Choice [Option("",9);Option("mais uma tarefa",10);Option("vinte e nove",29);Option("seis",6);Option("quase a acabar",10);Option("pedir ao chatGPT para fazer literais disto",10)]]]

let complex_challenge =
  Choice [
    Option ("Option 1", 5);
    Option ("Option 2", 7);
    Option ("Option 3", 10);
    Choice [
      Option ("Option 4", 3);
      Option ("Option 5", 8)
    ]
  ]
