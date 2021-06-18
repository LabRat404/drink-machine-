/**
 * ENGG1110 Problem Solving by Programming 
 *
 * I declare that the assignment here submitted is original
 * except for source material explicitly acknowledged,
 * and that the same or closely related material has not been
 * previously submitted for another course.
 * I also acknowledge that I am aware of University policy and
 * regulations on honesty in academic work, and of the disciplinary
 * guidelines and procedures applicable to breaches of such
 * policy and regulations, as contained in the website.
 *
 * University Guideline on Academic Honesty:
 *   http://www.cuhk.edu.hk/policy/academichonesty/
 *
 * Student Name : Yeung Tang <fill in yourself>
 * Student ID   : 1155144676 <fill in yourself>
 * Class/Section: D <fill in yourself>
 * Date         : 30-11-2019 <fill in yourself>
 */
 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Data{
    int a[7];
    int price[5];
    char name[5][20];
};
//5 = input 6=income
struct Data a,b,c;

void gui(struct Data c){
    int i = 0;
    printf("*---------------------------*\n|  ~Tang's Vending Machine  |\n*---------------------------*\n|   A    B    C    D    E   |\n|  $%d  $ %d  $ %d  $ %d  $ %d  |\n|  ", c.price[0], c.price[1], c.price[2], c.price[3], c.price[4]);
    while(i<=4){
        if(c.a[i]==0){
            c.a[i]=88;
        }else{
            if(c.a[5]>=c.price[i]){
                c.a[i]=79;
            }else{
                c.a[i]=32;
            }
        }
        printf("[%c]  ", c.a[i]);
        i++;
    }
    if(c.a[5]>=10){
        printf("|\n*---------------------------*\n|                    [$ %d] |\n|                           |\n|           [===]           |\n*---------------------------*\n", c.a[5]);
    }else{
        printf("|\n*---------------------------*\n|                    [$ %d]  |\n|                           |\n|           [===]           |\n*---------------------------*\n", c.a[5]);
    }
}

struct Data ims(struct Data b){
    printf("\n(9-1) Machine status\nAmount of revenue: $%d\nAmount of inserted coins: $%d\nProduct information:\nA. %s ($%d) (%d left)\nB. %s ($%d) (%d left)\nC. %s ($%d) (%d left)\nD. %s ($%d) (%d left)\nE. %s ($%d) (%d left)\n", b.a[6], b.a[5], b.name[0], b.price[0],b.a[0], b.name[1], b.price[1],b.a[1], b.name[2], b.price[2],b.a[2], b.name[3], b.price[3],b.a[3], b.name[4], b.price[4],b.a[4]);
}

struct Data wic(struct Data b){
    printf("\n(9-2) Inserted coins are being withdrawn.\n$%d is withdrawn.\n\n", b.a[6]);
    b.a[6] = 0;
    return b;
}

struct Data refill(struct Data b){

    while(1){
        int input=0, fill=0;
        printf("\n(9-3) Which product would you like to refill?\n1. %s ($%d) (%d left)\n2. %s ($%d) (%d left)\n3. %s ($%d) (%d left)\n4. %s ($%d) (%d left)\n5. %s ($%d) (%d left)\n6. Enter 0 to exit\nYour choice: ", b.name[0], b.price[0],b.a[0], b.name[1], b.price[1],b.a[1], b.name[2], b.price[2],b.a[2], b.name[3], b.price[3],b.a[3],b.name[4], b.price[4],b.a[4]);
        scanf("%d", &input);
        if(input>0&&input<5){
            printf("\nHow many ?");
            scanf("%d", &fill);
            b.a[input-1] += fill;
        }else{
            if(input==0){
                printf("\nReturning to menu....\n");
                break;
            }else{
                printf("\nWrong input, try again.\n");
            }
        }
    }
    return b;
}

struct Data change(struct Data b){

    while(1){
        printf("\n(9-4) Which product would you like to change?\n1. %s\n2. %s\n3. %s\n4. %s\n5. %s\n0. Go back\nYour choice: ",b.name[0],b.name[1],b.name[2],b.name[3],b.name[4]);
        int input=0;
        char name[20];
        scanf("%d", &input);
        if(input>0&&input<6){
            strcpy(name, b.name[input-1]);
            printf("\nYou are changing product ""%s"".\nPlease enter new product name: ",name);
            fseek(stdin, 0, SEEK_END);//clean buffer
            fflush(stdin);
            scanf("%s", name);
            int len = strlen(name);
            if( name[len-1] == '\n' )
                name[len-1] = 0;
            strcpy(b.name[input-1], name);
            printf("\nPlease enter a new price for the product: ");
            scanf("%d", &len);
            b.price[input-1] = len;
            printf("\nPlease enter how many can you wanted to fill in: ");
            scanf("%d", &len);
            b.a[input-1] = len;
            printf("\n\nYou have changed product %c to product: %s with price $%d (%d left)", input+64, b.name[input-1], b.price[input-1], b.a[input-1]);
//printf how many what has been change
        }else{
            if(input==0){
                printf("\nReturning to menu....\n");
                break;
            }else{
                printf("\nWrong input, try again.\n");
            }
        }
    }
    return b;
}

struct Data nothing()
{

}

struct Data read(struct Data b){
    printf("\nThe displayed products are:\nA. %s ($%d)\nB. %s ($%d)\nC. %s ($%d)\nD. %s ($%d)\nE. %s ($%d)\n\n",b.name[0],b.price[0],b.name[1],b.price[1],b.name[2],b.price[2],b.name[3],b.price[3],b.name[4],b.price[4]);
}

struct Data insert(struct Data b){
    int tmp=0;
    while(1){
        int o = b.a[5];
        printf("(2) Which coin would you like to insert?\n1. $1\n2. $2\n3. $5\n4. $10\n0. Go back\nYour choice: ");
        scanf("%d", &tmp);
        if(tmp!=0){
			
            (tmp==1) ? b.a[5] += 1 : (tmp==2) ? b.a[5] += 2 : (tmp==3) ? b.a[5] += 5 : (tmp==4) ? b.a[5] +=10 : printf("Invalid choice! Pay me $7 to buy a coofee!!");
        }else{
            printf("back to menu......\n\n");
            break;
        }
        printf("You have inserted $%d.\n\n", b.a[5]-o);
        gui(b);
    }

    return b;
}

struct Data press(struct Data c){

    while(1){
        printf("(3) Which product button would you like to press?\n1. A\n2. B\n3. C\n4. D\n5. E\n0. Go back\nYour choice: ");
        int tmp=0;
        int g[5];
        scanf("%d", &tmp);
        if(tmp <1||tmp>5){
            printf("Invalid choice! Pay me $7 to buy a coofee!!\nGoing back to menu....\n\n");
            break;
        }
        printf("You have pressed button %c.\n\n", tmp+64);
        //gui
        int i=0,flag = 0;
        printf("*---------------------------*\n|  ~Tang's Vending Machine  |\n*---------------------------*\n|   A    B    C    D    E   |\n|  $%d  $ %d  $ %d  $ %d  $ %d  |\n|  ",c.price[0], c.price[1], c.price[2], c.price[3], c.price[4]);
        if(c.a[tmp - 1]>0) {
            if (c.a[5] >= c.price[tmp - 1]) {
                c.a[5] -= c.price[tmp - 1];
                c.a[tmp - 1] -= 1;
                c.a[6] += c.price[tmp - 1];
                flag = 1;
            }
        }
        i=0;
        while(i<=4){
            if(c.a[i]==0){
                g[i]=88;
            }else{
                if(c.a[5]>=c.price[i]){
                    g[i]=79;
                }else{
                    g[i]=32;
                }
            }
            printf("[%c]  ", g[i]);
            i++;
        }
        if(flag==1){
            if(c.a[5]>=10){
                printf("|\n*---------------------------*\n|                    [$ %d] |\n|                           |\n|           [=%c=]           |\n*---------------------------*\n", c.a[5],tmp+64);
            }else{
                printf("|\n*---------------------------*\n|                    [$ %d]  |\n|                           |\n|           [=%c=]           |\n*---------------------------*\n", c.a[5],tmp+64);
            }
        }else{
            if(c.a[5]>=10){
                printf("|\n*---------------------------*\n|                    [$ %d] |\n|                           |\n|           [===]           |\n*---------------------------*\n", c.a[5]);
            }else{
                printf("|\n*---------------------------*\n|                    [$ %d]  |\n|                           |\n|           [===]           |\n*---------------------------*\n", c.a[5]);
            }
        }
    }
    return c;
}
struct Data returnb(struct Data b){
    printf("\n(4) Return button is pressed.\n$%d has been returned.\n\n", b.a[5]);
    b.a[5] = 0;
    return b;
}

struct Data error(struct Data b){
    printf("\nInvalid choice! you need any coffee m8?!\n\n");
}

struct Data service(struct Data b){

    int input=0, pwd=1110;
    printf("\n(9) Opening service menu.....\n");
    while(1){
        printf("Access code is required.\nPlease enter access code: ");
        scanf("%d", &input);
        if(input!=pwd){
            if(input == 0){
                return b;
            }
            printf("\nIncorrect code! Access Denied! Enter 0 to exit menu.");

        }else{
            printf("\nAccess Granted...\nEntering menu...");
            break;
        }
    }

    while(1){

        printf("\n(9) What would you like to do?\n1. Inspect machine status\n2. Withdraw inserted coins\n3. Refill product\n4. Change product\n0. Go back\nYour choice:");
        scanf("%d", &input);
        (input==1) ? ims(b) : (input==2) ? b=wic(b) : (input==3) ? b=refill(b) : (input==4) ? b=change(b) : nothing(b);
        if(input==0){
            printf("\nReturning to menu....\n");
            break;
        }
    }
    return b;
}

struct Data run(int input,struct Data b){
    (input==1) ? read(b) : (input==2) ? b=insert(b) : (input==3) ? b=press(b) : (input==4) ? b=returnb(b) : (input==9) ? b=service(b) : error(b);
    return b;
}

int main(){
    int input=0;
    struct Data a;
    a.a[0]=5;
    a.a[1]=1;
    a.a[2]=2;
    a.a[3]=1;
    a.a[4]=9;
    a.a[5]=0;
    a.a[6]=0;
    a.price[0]=10;
    a.price[1]=6;
    a.price[2]=5;
    a.price[3]=8;
    a.price[4]=7;
    strcpy(a.name[0], "A Glass of Juice");
    strcpy(a.name[1], "Nuka_Cola");
    strcpy(a.name[2], "Green_Tea");
    strcpy(a.name[3], "H2O");
    strcpy(a.name[4], "Monster_Drink");

 
    while(1){
        gui(a);
        printf("\nWhat would you like to do ?\n1. Read product information\n2. Insert coin\n3. Press product button\n4. Press return button\n9. Open service menu (code required)\n0. Quit\nYour choice: ");
        scanf("%d", &input);
        if(input!=0){
            a=run(input,a);
        }else{
            printf("Ok, have a good day!\n");
            char spinner[] = "|-\\";
            int i, j,c ,d;
            printf("exiting..");
            break;
        }
    }
}

