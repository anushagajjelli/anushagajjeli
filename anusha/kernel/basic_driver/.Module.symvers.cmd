cmd_/home/engineer/anusha/kernel/basic_driver/Module.symvers := sed 's/ko$$/o/' /home/engineer/anusha/kernel/basic_driver/modules.order | scripts/mod/modpost -m -a  -o /home/engineer/anusha/kernel/basic_driver/Module.symvers -e -i Module.symvers   -T -