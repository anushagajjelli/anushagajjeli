
//........Perform thei client operation.....................
 
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<arpa/inet.h>
#include"header.h"
//void register_details();
int bal=0;

void main()
{
	int sockfd,newsockfd,client_size,ret,m;

	//char buf[256];
	struct sockaddr_in serv;
	sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	//printf("socket return value:%d\n",socket);
	
	bzero(&serv,sizeof(serv));
	
	serv.sin_family=AF_INET;
	serv.sin_port=htons(5000);
	serv.sin_addr.s_addr=inet_addr("127.0.0.1");

	connect(sockfd,(struct sockaddr*)&serv,sizeof(serv));
	 
	int opt,num,a,b,p;
	while(1)
	{
		 m:printf("MENU\n\t1.Register\n\t2.Login\n\t3.exit\n\t");
		printf("Enter the option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:printf(".........................REGISTER THE DETAILS..............................\n");
				//compare with database, if no user then only register the user....
				//struct register buf;
				printf("Enter the username:");
				__fpurge(stdin);
				scanf("%[^\n]s",buf.usr_name);
				
				printf("Enter the userid:");
				__fpurge(stdin);
				scanf("%ld",&buf.u_id);
				printf("%ld",sizeof(buf.u_id));
				if(sizeof(buf.u_id)==8)
					printf("User id is entered successfully:\n");
				else
				{
					printf("Invalid use of userid use 8digit no:\n");
					goto m;
				}
				
				p:printf("Enter the password:");
				__fpurge(stdin);
				scanf("%s",buf.pswd);
				if(strlen(buf.pswd)>8)
					printf("Password is created successfully:\n");
				else
				{
					printf("Please enter the valid password:\n");
					goto p;
				}
					
				printf("Enter the gender:");
				__fpurge(stdin);
				scanf("%c",&buf.gen);
				
				a:printf("Enter the mobile no:");
				__fpurge(stdin);
				scanf("%d",&buf.mob_no);
				if(sizeof(buf.mob_no==10))
					printf("Mobile no updated successfully\n");
				else
				{
					printf("Please enter the 10digit mobile number:\n");
					goto a;
				}
					
				b:printf("Enter the Adhar no:");
				__fpurge(stdin);
				scanf("%ld",&buf.adhar_no);
				if(sizeof(buf.adhar_no)==12)
					printf("Adhar number is updated successfully:\n");
				else
				{
					printf("Please enter the valid adhar number with 12digits:\n");
					goto b;
				}
				
				printf("Balance amount:");
				__fpurge(stdin);
				scanf("%d",&bal);
				
				buf.account_no=buf.mob_no+buf.adhar_no;
				printf("ACCOUNT NO:%ld\n",buf.account_no);
				
				printf("Enter the dob:");
				__fpurge(stdin);
				scanf("%d %d %d",&buf.dt.date,&buf.dt.month,&buf.dt.year);
				
				//....................use structure........................................
				
				printf("................Enter the Nominee details........................\n");
				printf("Enter the Nominee name:");
				__fpurge(stdin);
				scanf("%s",buf.n_dt.nom_name);
				
				printf("Enter the Nominee mobile no:");
				__fpurge(stdin);
				scanf("%d",&buf.n_dt.nom_mob_no);
				
				printf("Enter the Nominee adhar no:");
				__fpurge(stdin);
				scanf("%ld",&buf.n_dt.nom_adhar_no);
				if(sizeof(buf.n_dt.nom_adhar_no)==12)
					printf("Nominee adhar details are updated successfully:");
				else
					printf("Enter the valid nominee adhar details with 12 digits:");
				
				
				
				//..................use structure...................................
				
				printf("...............................Enter the Address...........................\n");
				printf("Enter the H.NO:");
				__fpurge(stdin);
				scanf("%d",&buf.addr.h_no);
				
				printf("Enter the location:");
				__fpurge(stdin);
				scanf("%[^\n]s",buf.addr.location);
				
				
				printf("Enter the district:");
				__fpurge(stdin);
				scanf("%[^\n]s",buf.addr.dist);
				
				
				printf("Enter the state:");
				__fpurge(stdin);
				scanf("%[^\n]s",buf.addr.state);
				
				
				printf("Enter the pincode:");
				__fpurge(stdin);
				scanf("%d",&buf.addr.pin);
				
				
				
		
				//register();
				
				//printf("Registered successfully:");
			
	

				send(fd,&buf,sizeof(buf),0);
				
		
				//register_details();
				
				printf("Registered successfully:");
			
				break;
				
			case 2:printf(".............................LOGIN......................................\n");
				//compare with the database user if no login then perform the login...
				//if relogin then move to the main menu
				
				printf("Enter the userid:");
				__fpurge(stdin);
				scanf("%ld",&buf.u_id);
				if(sizeof(buf.u_id)==8)
					printf("User id is entered successfully:\n");
				else
					printf("Invalid use of userid:\n");
				
				printf("Enter the password:");
				__fpurge(stdin);
				scanf("%s",buf.pswd);
				if(strlen(buf.pswd)>8)
					printf("Password is created successfully:");
				else
					printf("Please enter the valid password:");
					
				//login();
				
				char sub_opt;
				printf("SUB MENU\na.Deposit\n\tb.Withdrawl\n\tc.Balance\n\td.History\n\te.Profile info\n\tf.Logout\n\t");
				printf("Enter the suboption:");
				__fpurge(stdin);
				scanf("%c",&sub_opt);
				switch(sub_opt)
				{
					case 'a':printf("......................DESPOSIT.....................................\n");
						//bal should be updated(money added)
						break;
						
					case 'b':printf("................................WITHDRAWL..............................\n");
						//bal should be updated(money (balance) subtraction)
						break;
						
					case 'c':printf(".........................BALANCE AMOUNT......................\n");
						//check the deposit and withdrawl amount ...to obtain the required balance
						break;
						
					case 'd':printf(".........................HISTORY................................\n");
						//transaction history
						break;
						
					case 'e':printf(".......................PROFILE INFORMATION........................\n");
						printf("Enter the username:");
						scanf("%[^\n]s",buf.usr_name);
						
						printf("Enter the dob:");
						__fpurge(stdin);
						scanf("%d %d %d",&buf.dt.date,&buf.dt.month,&buf.dt.year);
						
								
						//....................use structure........................................
						
						printf("................Enter the Nominee details........................\n");
						printf("Enter the Nominee name:");
						__fpurge(stdin);
						scanf("%s",buf.n_dt.nom_name);
						
						printf("Enter the Nominee mobile no:");
						__fpurge(stdin);
						scanf("%d",&buf.n_dt.nom_mob_no);
						
						printf("Enter the Nominee adhar no:");
						__fpurge(stdin);
						scanf("%ld",&buf.n_dt.nom_adhar_no);
						if(sizeof(buf.n_dt.nom_adhar_no)==12)
							printf("Nominee adhar details are updated successfully:");
						else
							printf("Enter the valid nominee adhar details with 12 digits:");
						
						buf.account_no=buf.mob_no+buf.adhar_no;
						printf("ACCOUNT NO:%ld\n",buf.account_no);
						
						 //enter balance 
						 //enter the register date and time
					case 'f':printf("............................LOGOUT.............................\n");
						//update the balance and transaction details before logout 
						break;
				}
						 
				break;
			
			case 3:exit(0);
				break;
			
			default:printf("Invalid option\n");
		}
	}
}

/*void register_details()
{
	int account_no,m;
				printf("Enter the username:");
				__fpurge(stdin);
				scanf("%[^\n]s",buf.usr_name);
				
				printf("Enter the userid:");
				__fpurge(stdin);
				scanf("%ld",&buf.u_id);
				printf("%d",sizeof(buf.u_id));
				if(sizeof(buf.u_id)==8)
					printf("User id is entered successfully:\n");
				else
				{
					printf("Invalid use of userid use 8digit no:\n");
					goto m;
				}
				
				printf("Enter the password:");
				__fpurge(stdin);
				scanf("%s",buf.pswd);
				if(strlen(buf.pswd)>8)
					printf("Password is created successfully:");
				else
					printf("Please enter the valid password:");
					
				printf("Enter the gender:");
				__fpurge(stdin);
 if(mkdir("database",0777)==-1)
        {
                printf("Failed to create directory\n");
                exit(4);
        }
				scanf("%c",&buf.gen);
				
				printf("Enter the mobile no:");
				__fpurge(stdin);
				scanf("%d",&buf.mob_no);
				if(sizeof(buf.mob_no==10))
					printf("Mobile number is added successfully:");
				else
					printf("Please enter the 10digit mobile number:");
					
				printf("Enter the Adhar no:");
				__fpurge(stdin);
				scanf("%ld",&buf.adhar_no);
				if(sizeof(buf.adhar_no)==12)
					printf("Adhar number is updated successfully:");
				else
					printf("Please enter the valid adhar number with 12digits:");
				
				printf("Balance amount:");
				__fpurge(stdin);
				scanf("%d",&bal);
				
				buf.account_no=buf.mob_no+buf.adhar_no;
				printf("ACCOUNT NO:%ld\n",buf.account_no);
				
				printf("Enter the dob:");
				__fpurge(stdin);
				scanf("%d %d %d",&buf.dt.date,&buf.dt.month,&buf.dt.year);
				
				//....................use structure........................................
				
				printf("................Enter the Nominee details........................\n");
				printf("Enter the Nominee name:");
				__fpurge(stdin);
				scanf("%s",buf.n_dt.nom_name);
				
				printf("Enter the Nominee mobile no:");
				__fpurge(stdin);
				scanf("%d",&buf.n_dt.nom_mob_no);
				
				printf("Enter the Nominee adhar no:");
				__fpurge(stdin);
				scanf("%ld",&buf.n_dt.nom_adhar_no);
				if(sizeof(buf.n_dt.nom_adhar_no)==12)
					printf("Nominee adhar details are updated successfully:");
				else
					printf("Enter the valid nominee adhar details with 12 digits:");
				
				
				
				//..................use structure...................................
				
				printf("...............................Enter the Address...........................\n");
				printf("Enter the H.NO:");
				__fpurge(stdin);
				scanf("%d",&buf.addr.h_no);
				
				printf("Enter the location:");
				__fpurge(stdin);
				scanf("%[^\n]s",buf.addr.location);
				
				
				printf("Enter the district:");
				__fpurge(stdin);
				scanf("%[^\n]s",buf.addr.dist);
				
				
				printf("Enter the state:");
				__fpurge(stdin);
				scanf("%[^\n]s",buf.addr.state);
				
				
				printf("Enter the pincode:");
				__fpurge(stdin);
				scanf("%d",&buf.addr.pin);
				
				
				
		
				//register();
				
				//printf("Registered successfully:");
}*/
	


