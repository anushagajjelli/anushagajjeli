cmd_/home/engineer/anusha/kernel/driver/simple/modules.order := {   echo /home/engineer/anusha/kernel/driver/simple/simpserial.ko; :; } | awk '!x[$$0]++' - > /home/engineer/anusha/kernel/driver/simple/modules.order