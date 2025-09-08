# Programa 2
#x = 1;
#y = 5*x + 15;
addi $s0,$zero, 1 # x = 1
add $t0, $s0, $s0
add $t0, $t0, $s0
add $t0, $t0, $s0
add $t0, $t0, $s0
addi $s1, $t0, 15 # y = 5*x + 15
