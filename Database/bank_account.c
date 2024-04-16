#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    char name[40];
    int id;
    int cash;
    char visa[20]; // <credit or Debit>
}client[3];
int temp =0;

//create
void Create(void){
    static int i = 0;
    for (i; i < 3; i++) {
        printf("enter the name of customer: %d \n", i+1);
        scanf("%s", &client[i].name);
        printf("enter the id of customer : %d \n", i+1);
        scanf("%d", &client[i].id);
        printf("enter the cash of customer :%d \n", i+1);
        scanf("%d", &client[i].cash);
        printf("enter the type <credit or debit> of card customer : %d \n ", i+1);
        scanf("%s",&client[i].visa);
        i++;
        temp++;
        break;
        }
       if(temp ==3){
            printf("IT's ENOUGH !!\n");
        }
}


//EDIT
void Edit(){
    int choose =0;
    int e;

    printf("Enter ID for Modify : \n");
    scanf("%d" , &e);

    for(int i =0;i<3;i++){
        if(client[i].id == e){
               while(choose!=6){
                    printf("\n Choose Type of Modifying  \n ");
                    printf("\n 1- Name ");
                    printf("\n 2- ID ");
                    printf("\n 3- Count of Money ");
                    printf("\n 4- type of Card ");
                    printf("\n 5- Modifying All Data");
                    printf("\n 6- Exit \n ");
                    scanf("%d" , &choose);

                    if(choose == 1){
                        printf("\n Enter New Name : ");
                        scanf("%s" , &client[i].name);}

                    else if(choose == 2){
                        printf("\n Enter New ID ");
                        scanf("%d" , &client[i].id);}

                    else if(choose == 3){
                        printf("\n Enter New count of Money ");
                        scanf("%d" , &client[i].cash);}

                    else if(choose == 4){
                        printf("\n Enter New Type of Card ");
                        scanf("%s" ,&client[i].visa );}

                    else if (choose == 5){
                        printf("\n Enter New Name : ");
                        scanf("%s" ,&client[i].name) ;
                        printf("\n Enter New ID ");
                        scanf("%d" , &client[i].id);
                        printf("\n Enter New Count of Cash : ");
                        scanf("%d" , &client[i].cash);
                        printf("\n Enter New Type of Visa : ");
                        scanf("%s" ,&client[i].visa);}

                    else if(choose == 6){
                        printf("\n Back");
                        break; }
    }
    }
    }
}

//DELETE
void Delete(void){
    int m;
    printf("\n ENTER ID : ");
    scanf("%d" , &m);
    for(int g = 0; g<3; g++){
            if(client[g].id == m){
                for(int n =g; n<3 ; n++ ){
                    client[n]=client[n+1];
                    temp--;
        }
            printf("\n THE OPRATION IS DONE !!");
    }
    }
}

//Transfer
void Transfer(void){
    int x , receiver , sender , amount;

    printf("\n SENDER ID : ");
    scanf("%d" , &sender);

    printf("\n RECEIVER ID : ");
    scanf("%d" , &receiver);

    printf("\n Amount : ");
    scanf("%d" ,&amount);

    for(x =0; x<3; x++){
        if(client[x].id == sender && client[x].cash >= amount){
            client[x].cash = client[x].cash - amount;
        }
        if(client[x].id == receiver){
            client[x].cash = client[x].cash + amount;
        }
    }
   printf("\n TRANSFARE IS DONE. ");

}

//Print Data
void Print(void){
     int c;
     printf(" ************************************** ");
     printf("\n SHOW ALL DATA OF ID : ");
     scanf("%d" , &c);
     for(int b=0 ; b<3 ; b++){
            if(client[b].id==c){
                printf(" ENTER NAME : %s\n" , client[b].name );
                printf(" ENTER ID : %d\n" , client[b].id);
                printf(" ENTER CASH : %d\n" , client[b].cash);
                printf(" ENTER VISA : %s\n" , client[b].visa);

     printf(" ************************************** ");

     return ;
     }
     }
     printf("\n NO DATA HAS BEEN ENTERD ");
}


int main(){

    int START=0;

    while (START!=6)
    {
        printf(" \n1- Create a New Customer <Press 1 To Select This option> \n");
        printf(" \n2- Edit The Data Customer <Press 2 To Select This option> \n");
        printf(" \n3- Delete The Data Customer <Press 3 To Select This option> \n");
        printf(" \n4- Transfer  <Press 4 To Select This option> \n");
        printf(" \n5- Print the data of Customer <Press 5 To Select This option> \n");
        printf(" \n6- to end the program <Press 6 To Select This option> \n");
        scanf("%d", &START);

        if (START == 1) {
            Create();
        } else if (START == 2) {
            Edit();
        } else if (START == 3) {
            Delete();
        } else if (START == 4) {
            Transfer();
        } else if (START == 5) {
            Print();
        } else if (START == 6) {
            printf("\nThe Program Is Finish \n");
            break;
        }
    }
    return 0;
}
