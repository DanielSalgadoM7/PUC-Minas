# Programa 4
#x = 3;
#y = 4 ;
#z = ( 15*x + 67*y)*4
ori $s0, $zero, 3 # x = 3
ori $s1, $zero, 4 # x = 4
sll $t0, $s0, 4 # 16*x
sub $t0, $t0, $s0 # 15*x
sll $t1, $s1, 6 # 64*x
add $t1, $t1, $s1 # 65*y
add $t1, $t1, $s1 # 66*y
add $t1, $t1, $s1 # 67*y
add $t2,$t0, $t1 # ( 15*x + 67*y)
sll $s2, $t2, 2 # z = ( 15*x + 67*y)*4
