# Programa 10
#Considere o seguinte programa: y = 127x – 65z + 1
#Faça um programa que calcule o valor de y conhecendo os valores de x e z. Os valores de x e z
#estão armazenados na memória e, na posição imediatamente a seguir, o valor de y deverá ser
#escrito, ou seja:
#.data
#x: .word 5
#z: .word 7
#y: .word 0 # esse valor deverá ser sobrescrito após a execução do programa.

.text
lui $t0, 0x1001
lw  $s0, 0($t0)
lw  $s1, 4($t0)

sll $t1, $s0, 7
sub $t1, $t1, $s0

sll $t2, $s1, 6
add $t2, $t2, $s1

sub $t3, $t1, $t2
addi $t3, $t3, 1

sw $t3, 8($t0)

.data
x: .word 5
z: .word 7
y: .word -1