# Programa 13
#Escreva um programa que leia um valor A da memória, identifique se o número é negativo ou
#não e encontre o seu módulo. O valor deverá ser reescrito sobre A.
.text

lui $t0, 0x1001
lw $s0, 0($t0)
srl $t1 , $s0, 31
beq $s0, $zero, fim
sub $s0, $zero, $s0
fim:
.data
valor: .word -5
