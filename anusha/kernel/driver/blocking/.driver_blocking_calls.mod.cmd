cmd_/home/engineer/anusha/kernel/driver/blocking/driver_blocking_calls.mod := printf '%s\n'   driver_blocking_calls.o | awk '!x[$$0]++ { print("/home/engineer/anusha/kernel/driver/blocking/"$$0) }' > /home/engineer/anusha/kernel/driver/blocking/driver_blocking_calls.mod