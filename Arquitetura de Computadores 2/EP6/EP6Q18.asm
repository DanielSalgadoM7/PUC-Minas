# Programa 18
#Para a expressão a seguir, escreva um programa que calcule o valor de k:
#k = x^y
#Obs: Você poderá utilizar o exercício anterior.
#O valor de x deve ser lido da primeira posição livre da memória e o valor de y deverá lido da
#segunda posição livre. O valor de k, após calculado, deverá ainda ser escrito na terceira posição
#livre da memória.
#Dê um valor para x e y (dê valores pequenos !!) e use o MARS para verificar a quantidade de
#instruções conforme o tipo (ULA, Desvios, Mem ou Outras)

.data
x: .word 9
y: .word 7

.text

lui $t0, 0x1001
lw $s0, 0($t0)
lw $s1, 4($t0)
ori $t1,$s0,0

# x^y
# x -> s0
# y -> s1
ori $t4,$zero,1
loop2:
beq $t4, $s1, fim
ori $t3,$t1,0
ori $t2,$zero,1
loop: # x * 4
beq $t2, $s0,a
add $t3, $t3, $t1
addi $t2 ,$t2, 1
j loop
a:
ori $t1, $t3, 0
addi $t4 ,$t4, 1
j loop2
fim:

sw $t1, 8($t0)
