#x = 3;
#y = 4;
#z = ( 15*x + 67*y)*4
addi $s0,$zero, 3 # x = 3
addi $s1,$zero, 4 # y = 4
add  $t0, $s0, $s0 # 2*x
add  $t0, $t0, $t0 # 4*x
add  $t0, $t0, $t0 # 8*x
add  $t0, $t0, $t0 # 16*x
sub  $t0, $t0, $s0 # 16*x - x

add  $t1, $s1, $s1 # 2*y
add  $t1, $t1, $t1 # 4*y
add  $t1, $t1, $t1 # 8*y
add  $t1, $t1, $t1 # 16*y
add  $t1, $t1, $t1 # 32*y
add  $t1, $t1, $t1 # 64*y
add  $t1, $t1, $s1 # 65*y
add  $t1, $t1, $s1 # 66*y
add  $t1, $t1, $s1 # 67*y

add  $t2, $t0, $t1 # ( 15*x + 67*y)
add  $t2, $t2, $t2
add  $s2, $t2, $t2 #z = ( 15*x + 67*y)*4

