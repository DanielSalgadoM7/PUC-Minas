# Programa 16
#Escreva um programa que avalie a expressão: (x*y)/z.
#Use x = 1600000 (=0x186A00), y = 80000 (=0x13880), e z = 400000 (=0x61A80). Inicializar os
#registradores com os valores acima.

ori $s0,$zero, 0xC35 # x
sll $s0,$s0, 9
ori $s1,$zero, 0x271 # y
sll $s1,$s1, 7
ori $s2,$zero, 0xC35 # z
sll $s2,$s2, 7

div $s0, $s2
mflo $t1
mult $s1, $t1
mflo $s3 # resultado
