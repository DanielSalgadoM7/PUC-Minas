# Programa 11
#Considere o seguinte programa: y = x – z + 300000
#Faça um programa que calcule o valor de y conhecendo os valores de x e z. Os valores de x e z
#estão armazenados na memória e, na posição imediatamente a seguir, o valor de y deverá ser
#escrito, ou seja:
#.data
#x: .word 100000
#z: .word 200000
#y: .word 0 # esse valor deverá ser sobrescrito após a execução do programa.

.text
lui $t0, 0x1001
lw $s0, 0($t0)
lw $s1, 4($t0)
ori $t1, $zero, 0x249f
sll $t1, $t1, 5
sub $t2, $s0, $s1
add $s2, $t2, $t1
sw $s2, 8($t0)

.data
x: .word 100000
z: .word 200000
y: .word -1