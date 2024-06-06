# Programa 17
#Para a expressão a seguir, escreva um programa que calcule o valor de k:
#k = x * y (Você deverá realizar a multiplicação através de somas!)
#O valor de x deve ser lido da primeira posição livre da memória e o valor de y deverá lido da
#segunda posição livre. O valor de k, após calculado, deverá ainda ser escrito na terceira posição
#livre da memória.
.data
x: .word 4
y: .word 5

.text

lui $t0, 0x1001
lw $s0, 0($t0)
lw $s1, 4($t0)
ori $t1,$s0,0
ori $t2,$s1,0
addi $t2 ,$t2, -1

loop:
beq $t2,$zero, fim 
add $t1 ,$s0,$t1
addi $t2 ,$t2, -1
j loop

fim:
sw $t1, 8($t0)