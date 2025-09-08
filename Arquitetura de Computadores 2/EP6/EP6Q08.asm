# Programa 8
#Inicialmente escreva um programa que faça:
#$8 = 0x12345678.
#A partir do registrador $8 acima, usando apenas instruções lógicas (or, ori, and, andi,
#xor, xori) e instruções de deslocamento (sll, srl e sra), você deverá obter os seguintes
#valores nos respectivos registradores:
#$9 = 0x12
#$10 = 0x34
#$11 = 0x56
#$12 = 0x78
ori $8, $0, 0x1234
sll $8, $8, 16
ori $8, $8, 0x5678

srl $9, $8, 24

srl $10, $8, 16
xori $10, $10, 0x1200

sll $11, $8, 16
srl $11, $11, 24

sll $12, $8, 24
srl $12, $12, 24