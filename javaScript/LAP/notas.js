//As linguagens nao foram criadas inicialmente para gerar extensibilidade.
//Foram criadas para simular o mundo real.
//Sao com base em "Passar o testemunho (Running thread)"
//Mas extensibilidade é importante
//Um programa extensivel é um programa que nao precisa de ser mudado de durante muito tempo. O processo de manter o programa para que se adapte às novidades chama-se refactorizar.
//Por vezes, para refactorizar um programa, é preciso pensar em novos conceitos para simplificar certas partes do programa.
//Pode-se refatorizar o programa mais cedo ou mais tarde.
//Um programa desenhado para o futuro.
//O proposito é poder usar o mesmo codigo sem ter de o escrever varias vezes. (Ex: classes abstratas, hierarquia de classes, prototipos, funções)
//Queremos escrever codigo sem ter de alterar o que já foi escrito

//Obtem-se com abstração

//Programar em OCAML (ou qualquer linguagem funcional): Raciocionio Indutivo. (funçoes)
//Programar em C (ou qualquer linguagem imperativa): Pensar como a maquina. (Variaveis mutaveis)
//Programar em qualquer java (ou qualquer OOPL): Programas extensiveis. (Abstraçao)

//Ex: Se o programa falar de cães e gatos, faz sentido falar em animais no geral.
//Ex: Se o programa falar de Automoveis e motas, faz sentido falar em veiculos.
//Muita abstraçao tambem faz mal.
//Se no primeiro exemplo, de repente, se falar de ser vivo, já se está a perder tempo.

//Mas vantagens de programas adequadamente extensiveis.
/*
Interaçao entre objetos de tipo diferente de forma extensivel (?) (Muito provavelmente, até agora nao conseguimos)

Testes explicitos de tipo nao fazem o programa extensivel. (usar instanceof em java, por exemplo, num "if" gigante, mundo fechado. Como um ISA total de base de dados)

Podemos fazer uma interface de coisas saborosas. Tudo o que seja saboroso implementa uma interface "TastyThing", com um método booleano "isTasty". O Monstro pergunta "isTasty()" ao vizinho. Se true, come. Se falso, nao come. Todos os objetos que o monstro pode encontrar têm de implementar "TastyThing"

E podemos usar uma interface que tenha um metodo "feedLevel()" que compara que outras instancias dessa interface em relaçao à sua posição na cadeia alimentar.

Interfaces podem expressar propriedades de objetos. Isso é giro
(Mas tem de se usar o instanceof à mesma :P)

Existem marker interfaces em java que sao interfaces vazias que podemos usar para tomar certas decisoes em relaçao a esses objetos.


(Até podemos gerir uma lista de coisas que cada animal gosta de comer dentro da sua implementação)


Agora... para simular reproduçao:

Podemos perguntar se o vizinho (da matriz, mapa, mundo do jogo, etc.) é da mesma classe que o sujeito e se se reproduz de forma assexuada ou sexuada.

Podemos usar reflexão!!!!!!

Agora... Sem interfaces?

*/




/*

Uma coisa que compromente extensibilidade é falta de modularidade

Isso significa classes fazer o trabalho de umas das outras.




*/
/*
Fatorizaçao excessiva: Basicamente, ter dois animais, que comem de formas diferentes e distinguir a chamada na classe abstrata Animal acima com um instance of (isso n e fatorizaçao, mas pronto...)




Programar de forma minimalista é programar de forma a que o codigo esteja pronto para o futuro, mas ao mesmo tempo apenas programar para o objetivo que queremos.

Para o projeto, a parte grafica do programa ja está feita. O que é preciso de ser feito é a logica dele.

*/
class Animal{

	
	constructor()







}


let x = new Animal(555)


