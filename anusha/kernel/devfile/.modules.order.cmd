cmd_/home/engineer/anusha/kernel/devfile/modules.order := {   echo /home/engineer/anusha/kernel/devfile/basic.ko; :; } | awk '!x[$$0]++' - > /home/engineer/anusha/kernel/devfile/modules.order
