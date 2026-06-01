#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct device{
    int number;
    char name[50];
    char brand[50];
    int storage;
    int camera;
    char OS[50];
    int price;
};

void filetostruct(char f[50], struct device tab[]){
    int a,b;
    char sentence[100];
    char delim[]=" ";
    int x;
    FILE *fp;
    fp=fopen(f,"r");
    if(fp==NULL){
        printf("Error: could not open file %s\n", f);
        return;
    }
    for(a=0;a<3;a++){
        if(fgets(sentence,100,fp)==NULL){
            break;
        }
        char *ptr=strtok(sentence,delim);
        for(b=0;b<7;b++){
            if(ptr!=NULL){
                x=atoi(ptr);
                tab[a].number=x;
                ptr=strtok(NULL,delim);
            }
            if(ptr!=NULL){
                strcpy(tab[a].name,ptr);
                ptr=strtok(NULL,delim);
            }
            if(ptr!=NULL){
                strcpy(tab[a].brand,ptr);
                ptr=strtok(NULL,delim);
            }
            if(ptr!=NULL){
                x=atoi(ptr);
                tab[a].storage=x;
                ptr=strtok(NULL,delim);
            }
            if(ptr!=NULL){
                x=atoi(ptr);
                tab[a].camera=x;
            	ptr=strtok(NULL,delim);
            }
            if(ptr!=NULL){
                strcpy(tab[a].OS,ptr);
                ptr=strtok(NULL,delim);
            }
            if(ptr!=NULL){
                x=atoi(ptr);
                tab[a].price=x;
                ptr=strtok(NULL,delim);
            }
        }
    }
    fclose(fp);
}

int main(){
    struct device tab[100];
    char filename[50];
    printf("-Enter the name of the file: \n");
    printf("*Phone.txt \t *Tablet.txt \n");
	printf("*Laptop.txt \t *Console.txt \n");
	printf("*Printer.txt \t *Camera.txt \n");
	printf("	   *TV.txt \n ");
    scanf("%s",filename);
    filetostruct(filename,tab);
    int i;
    // Print the table of structures
    for(i=0;i<3;i++){
        printf("%d %s %s %d %d %s %d\n",tab[i].number,tab[i].name,tab[i].brand,tab[i].storage,tab[i].camera,tab[i].OS,tab[i].price);
    }
    char answer[2];
    printf("Do you want to specify some requirements? (Y/N)\n");
    scanf("%s", answer);
    if(strcmp(answer,"Y")==0||strcmp(answer,"y")==0){
        int choice;
        printf("Please choose a number of your needs :\n");
        printf("1.Brand \t 2.Storage\t 3.Camera\t 4.OS\t 5.Max Price \n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Please enter the brand you want:\n");
                char brandd[50];
                scanf("%s",brandd);
                for(i=0;i<3;i++){
                    if(strcmp(brandd,tab[i].brand)==0){
                        printf("%d %s %s %d %d %s %d\n",tab[i].number,tab[i].name,tab[i].brand,tab[i].storage,tab[i].camera,tab[i].OS,tab[i].price);
                    }
                }
                break;
            case 2:
                printf("Please enter the storage you need:\n");
                int storagee;
                scanf("%d",&storagee);
				for(i=0;i<3;i++){
					if(tab[i].storage==storagee){
						printf("%d %s %s %d %d %s %d\n",tab[i].number,tab[i].name,tab[i].brand,tab[i].storage,tab[i].camera,tab[i].OS,tab[i].price);
					}
				}
				break;
			case 3:
				printf("Please enter the camera you need:\n");
				int cameraa;
				scanf("%d",&cameraa);
				for(i=0;i<3;i++){
					if(tab[i].camera==cameraa){
						printf("%d %s %s %d %d %s %d\n",tab[i].number,tab[i].name,tab[i].brand,tab[i].storage,tab[i].camera,tab[i].OS,tab[i].price);
					}
				}
				break;
			case 4:
				printf("Please enter the OS you need:\n");
				char ooss[50];
				scanf("%s",ooss);
				for(i=0;i<3;i++){
					if(strcmp(ooss,tab[i].OS)==0){
						printf("%d %s %s %d %d %s %d\n",tab[i].number,tab[i].name,tab[i].brand,tab[i].storage,tab[i].camera,tab[i].OS,tab[i].price);
					}
				}
				break;
			case 5:
				printf("Please enter the maximum price you can afford:\n");
				int maxprice;
				scanf("%d",&maxprice);
				for(i=0;i<3;i++){
					if(tab[i].price<=maxprice){
						printf("%d %s %s %d %d %s %d\n",tab[i].number,tab[i].name,tab[i].brand,tab[i].storage,tab[i].camera,tab[i].OS,tab[i].price);
					}
				}
				break;
			default:
				printf("Invalid input!\n");
				break;
		}
	}
	return 0;
}
