					# pseudo-constantes
EXIT = 1
LINUX_SYSCALL = 0x80

.data   
vetor: .int  -1, 5, 1, 1, 4	# um vetor de inteiros, experimente com
					# diferentes tamanhos e com outros valores
len = (. - vetor)
quatro= 4		# porque?  O que faz isto?

x:     .int 4			# elemento a pesquisar
total: .int 0   	# total de valores =s a x encontrados
					# no ‘vetor’
					
					
.text           # seccao de codigo
.global _start  # exportar o simbolo _start (inicio do programa)


_start:
movl $vetor, %eax #em eax vai ser guardado o endereço onde o programa pára.
movl $vetor, %ecx #em ecx vai ser guardado o endereço onde o programa começa e onde vai ser guardada a posição atual do array ondeo programa se encontra.
movl $len,%ebx  #ebx vai ser usado como uma variavel temporaria para transferir o valor certo para eax
addl  %eax ,%ebx
movl %ebx,%eax #edx vai ser o valor de bytes a incrementar em cada salto
movl (x),%edx
jmp p
l:
	addl $4, %ecx
	incl (total)
	cmpl %ecx,%eax
je j
jne p
   
e:
	addl $4, %ecx
	cmpl %ecx,%eax
je j
jne p
p:
	cmpl %edx,(%ecx)

je l
jne e

j:

	movl (total),%eax

jmp fim


fim:
	movl %eax, %ebx			# colocar contagem em ebx para
						# ser passado ah shell...
	movl    $EXIT,%eax		# pedir o exit ao sistema
	int     $LINUX_SYSCALL		# chama o sistema
