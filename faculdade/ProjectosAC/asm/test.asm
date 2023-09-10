#Este programa cumprimenta o utlizador, pedindo-lhe o nome e imprimindo uma saudação junto com a sequência de caracteres que foi escrita.

#Esta é a secção de defines. Vou colocar aqui as cenas a serem usadas nas chamadas ao sistema.:

EXIT=1 #"Macro" para Sinal de saida.
WRITE=4 #Macro para sinal de escrita.
CH_DIR=4
MKDIR=39
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

	
	vec: .asciz "Jumping Is fun\n"
	cmp0: .int (.-vec)
	dir: .asciz "/home"
	cmp2: .int (.-dir)
	new: .asciz "folder"
	cmp3: .int (.-new)
	num: .asciz ""
.text
.global _start

_start:

jmp main

write:

	movl $WRITE, %eax
	movl $SYSOUT,%ebx
	movl $vec, %ecx
	movl (cmp0),%edx
	int $LINUX_SYSTEMCALL
	
	movl $WRITE, %eax
	movl $SYSOUT,%ebx
	movl $dir, %ecx
	movl (cmp2),%edx
	int $LINUX_SYSTEMCALL
	

jmp exit

newdir:

	movl $MKDIR,%eax
	movl $new,%ebx
	movl $1,%ecx
	int $LINUX_SYSTEMCALL
jmp write
	
main:
	movl $READ, %eax
	movl $SYSIN,%ebx
	movl $num,%ecx
	movl $10,%edx
	int $LINUX_SYSTEMCALL
	
	
	movl $WRITE,%eax
	movl $SYSOUT, %ebx
	movl $num,%ecx
	movl $10,%edx
	int $LINUX_SYSTEMCALL
	
	movl $CH_DIR,%eax
	movl $dir,%ebx
	int $LINUX_SYSTEMCALL
	
jmp newdir

exit:
	movl $EXIT, %eax
	movl (cmp2),%ebx
	int $LINUX_SYSTEMCALL

