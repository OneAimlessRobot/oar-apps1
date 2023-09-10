#Este programa cumprimenta o utlizador, pedindo-lhe o nome e imprimindo uma saudação junto com a sequência de caracteres que foi escrita.

#Esta é a secção de defines. Vou colocar aqui as cenas a serem usadas nas chamadas ao sistema.:

EXIT=1 #"Macro" para Sinal de saida.
WRITE=4 #Macro para sinal de escrita.
READ=3 #Macro para leitura.
SYSOUT=1 #Macro para o descritor de ficheiro da standard output
SYSIN=0 #Macro para o descritor de ficheiro da standard intput
LINUX_SYSTEMCALL=128 #Numero inteiro com o qual se usa o comando "int" para que o sistema seja chamado com a função que está no registo eax, e com os argumentos em ebx, ecx e edx. (Esta é a ordem com que se tem de colocar os argumentos). Por ex:

#Imaginemos que uma função executável como chamada ao sistema é identificada com o número x.
#E que no header onde está definida, a sua assinatura é esta:
#int func(datatype0 arg0, datatype1 arg1, datatype2 arg2);
#para chamar esta função em assembly, o que se faz é isto:

# movl $x, %eax
# movl $valuey ,%ebx
# movl $valuez, %ecx
# movl $valuet, %edx
# int 128

#O que vai acontecer explicado em linguagem C é:

# func(%ebx,%ecx,%edx);

#O systemcall funciona com os 4 registos: 
# - O valor do registo eax diz ao systemcall QUE função chamar;
# - O valor do registo ebx diz ao systemcall qual o valor do primeiro parâmetro;
# - O valor do registo ecx corresponde ao segundo parâmetro
# - O edx é o valor do terceiro parâmetro.

.data


	greeting: .ascii "Olah, \0"
	len: .int (.-greeting)
	intro: .ascii "Quem ehs tu?\n"
	len2: .int (.-intro)
	newline: .ascii "! Seu fofo :)\n"
	len4: .int (.-newline)	
	buff: .ascii "           "

.global _start

.text

_start:

	movl $WRITE, %eax
	movl $1, %ebx
	movl $intro, %ecx
	movl (len2),%edx
	int $LINUX_SYSTEMCALL
jmp read


read:
	movl $READ, %eax #Este syscall vai ter a sys_read como função
	movl $SYSIN,%ebx #Este primeiro parâmetro vai ser o descritor de ficheiro de onde ler dados. Neste caso, vai ser a Standard Input
	movl $buff, %ecx #Este Segundo parâmetro vai ser o buffer onde guardar os dados.
	movl $10,%edx #Aqui está guardado o numero máximo de caracteres a ler.
	int $LINUX_SYSTEMCALL
jmp template

template:
	movl $WRITE, %eax
	movl $SYSOUT, %ebx
	movl $greeting, %ecx
	movl (len),%edx
	int $LINUX_SYSTEMCALL
jmp name

name:
	movl $WRITE, %eax
	movl $SYSOUT, %ebx
	movl $buff, %ecx
	movl $10, %edx
	int $LINUX_SYSTEMCALL
jmp line

line:
	movl $WRITE, %eax
	movl $SYSOUT, %ebx
	movl $newline, %ecx
	movl (len4), %edx
	int $LINUX_SYSTEMCALL
	
	.include "test.asm"
jmp exit
exit:
	movl $EXIT, %eax
	movl (tmp), %ebx
	int $LINUX_SYSTEMCALL

	

	
	

















