cmd_/home/engineer/anusha/kernel/device_drivers/Module.symvers := sed 's/ko$$/o/' /home/engineer/anusha/kernel/device_drivers/modules.order | scripts/mod/modpost -m -a  -o /home/engineer/anusha/kernel/device_drivers/Module.symvers -e -i Module.symvers   -T -
