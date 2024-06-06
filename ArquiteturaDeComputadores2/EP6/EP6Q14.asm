# Programa 14
#Escreva um programa que leia um valor A da memória, identifique se o número é par ou não.
#Um valor deverá ser escrito na segunda posição livre da memória (0 para par e 1 para ímpar).

.text

lui $t0, 0x1001
lw $s0, 0($t0)
ori $t1, $zero, 2
ori $t2,$zero, 1
loop:
beq $t1,$s0, par
beq $t2,$s0, impar
sub $s0, $s0, $t1
j loop
par:sw $zero, 4($t0)
j fim
impar:sw $t2, 4($t0)
fim:

.data

A: .word 1
