struct dob
{

        unsigned int date;
        unsigned int month;
        unsigned int year;
};


struct nominee
{
        char nom_name[20];
        unsigned int nom_mob_no;
        unsigned long int nom_adhar_no;
};


struct address
{
        unsigned int h_no;//char array
        char location[20];
        char dist[20];
        char state[20];
        unsigned int pin;
        //char area[20];
};


struct regstr
{
        char usr_name[20];
        unsigned long int u_id;
        char pswd[10];
        char gen;
        struct dob dt;
        unsigned int mob_no;
        unsigned long int account_no;
        unsigned long int adhar_no;
        struct nominee n_dt;
        struct address addr;
        //struct reg_time rdt;
        signed int bal;
};



