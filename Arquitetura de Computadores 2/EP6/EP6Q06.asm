# Programa 6
# x = o maior inteiro possível;
# y = 300000;
# z = x - 4y
ori $t0,$zero, 0xffff
sll $t1,$t0, 15
or $s0, $t0, $t1 #x = o maior inteiro possível
ori $t2,$zero, 0x493E
sll $s1,$t2, 4 # y = 300000
sll $t3,$s1, 2 # 4y
sub $s2, $s0, $t3 # z = x - 4y
