# pseudo-constantes
EXIT = 1
LINUX_SYSCALL = 0x80

.data                   
vetor:  .int  1, -1, 1, 1, 4, -3	# um vetor de inteiros
len = (. - vetor)	# dimensao do vetor
sum: .int 0		


.text           # seccao de codigo
.global _start  # exportar o simbolo _start (inicio do programa)



_start:
movl $vetor,%eax 
movl $vetor,%ecx #Aqui (ecx)vai ficar guardado o endereço atual do programa.
movl $len,%ebx
addl %ebx,%eax #Aqui (eax) vai ficar guardado o endereço final do vetor
movl (sum), %edx
jmp p

p:
	addl (%ecx), %edx
	cmpl %ecx,%eax
je getReady
jne l

l:
	addl $4,%ecx
jmp p

	 
getReady:
	movl %edx, %ebx
jmp fim	

#	  TODO...


#	  movl ..., %ebx			  colocar no ebx a soma. Se o seu
						# codigo jah fez isso, o mov eh
						# naturalmente desnecessario
fim:
        movl $EXIT,%eax		# pedir o exit ao sistema
        int  $LINUX_SYSCALL		# chama o sistema
