
(* Paradigmas de programa�ao:*)
(* O que e computa�ao?*)
(* Processamento automatico de informacao*)
(* Paradigmas:*)
(* Imperativo- a computacao e baseada em atribui�oes e na sua ordem.*)
(* Funcional- *)
(* Logico- Relacoes n arias e arvores de derivacao*)
(* Orienta�ao para objetos- comunicacao entre tipos complexos de dados. E como uma corrida de estafetas. O thread de execucao vai sendo passado como testemunho entre objetos. (O this chama instancia de Object1, que chama Object2, e em cada passagem, o thread muda o ficheiro e os dados a usar *)
(* ..... O que interessa e que a computacao nao existe no vacuo, ou seja, temos de ter regras e uma no�ao de*)
(* um mundo em constante mudanca sobre o qual executamos a�oes pre programadas. Programar e um verbo transitivo direto*)
(* Programar em varios paradigmas expande a nossa imaginacao e a nossa capacidade de resolver problemas. Torna-nos mais flexiveis.*)
(* Paradigma, por defini�ao e um conjunto limitado de conceitos que define um ponto de vista.*)
(* Um paradigma pode ser de computa�ao, politico, sobre a natureza da verdade... E um ponto de vista*)
(* Tenho de confiar nos meus paradigmas ate nao dar mais. Senao seria demasiado*)
(* Uma linguagem funcional tem funcoes como valores de primeira classe-*)
(* Deve permitir:*)
(* - Funcoes anonimas. (usar funcoes sem as inicializar)*)
(* -Passar funcoes como argumentos.*)
(* -Sao retornadas por outras funcoes.*)
(* Para se programar bem numa linguagem funcional devemos saber utilizar bem o metodo indutivo e USAR AS BIBLIOTECAS SUA BOLA DE INSEGURAN�A INTELECTUAL*)
(* Para qualidade de codigo, e sempre melhor usar as fun�oes biblioteca. Torna o codigo mais sociavel. *)

(*OCaml compara qualquer tipo de dados com "=".Pode comparar arvores. nao precisamos de programar nenhum ""equals"" entre arvores.*)


(*LINGUAGEM C:*)

(* A linguagem C tem uma boa combina�ao de alto nivel e baixo nivel. Nao tem concorrencia que tenha tido sucesso*)

(* A linguagem Rust e como C, so que com mais seguranca devido a burocracia de precondi�oes. *)

(*Em OCaml, nao ha pilha de execu�ao, devido a possibilidade de se devolver fun�oes usando fun�oes.*)

(*Em C, e possivel recriar polimorfismo usando "void*"'s (apontadores neutros)*)

(*C tem um sistema de tipos fraco (ou seja, o compilador nao nos "censura" *)
(*quando metemos certos dados em variaveis de certos tipos.*)
(*Tudo sao bits. O resto e burocracia) *)

(*Vai ser dificil. Usamos conhecimentos de FSO.*)

(*Vamos usar apontadores. Agora... nada de recursividade, pois temos de poupar a pilha de execucao.*)
(* Vamos programar operacoes em listas ligadas usando programacao de baixo nivel *)

(*Percorrer arvores sem pilhas auxiliares*)