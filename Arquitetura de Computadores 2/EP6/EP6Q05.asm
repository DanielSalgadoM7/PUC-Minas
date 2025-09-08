# Programa 5
# x = 100000;
# y = 200000;
# z = x + y;
ori $t0,$zero, 0xC35
sll $s0,$t0, 5 # x = 100000;
sll $s1,$t0, 6 # y = 200000;
add $s2,$s0,$s1 # z = x + y;
