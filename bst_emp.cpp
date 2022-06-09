#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee{
    int empId;
    char empName[100],empPhoNo[100],empAge[10];
    char empAddress[1000],empSalary[100],empBusId[10],empPost[100];
    struct employee *rchild,*lchild;
};
int c=0;
struct employee *newNode;
struct employee* insert(struct employee *,int);
struct employee* inorder(struct employee *,int,int);
struct employee* delete_node(struct employee *,int);


struct employee* getNode(int id){
	FILE *fp;
    char empId[100],post[10],name[100],phoNo[10],age[10],address[100],busId[10],salary[100],a1[50];
    char i[50]="EMPLOYEE_ID:",p[50]="POST:",n[50]="NAME:",ph[50]="PHONE:",a[10]="AGE:",ad[50]="ADDRESS:",b[10]="BUS_ID:",s[10]="SALARY:";
    printf("\t\t\t*ADD EMPLOYEE*\t\t\t\n");
    fp=fopen("Employee.txt","a+");
	newNode=(struct employee *)malloc(sizeof(struct employee));
	fflush(stdin);
	newNode->empId=id;
    sprintf(a1,"%d",id);
    strcat(i,a1);
    fflush(stdin);
	fprintf(fp,"\n",a1);
    fprintf(fp,"%s\n",i);
    printf("Enter the post of the employee: \n");
    fflush(stdin);
    scanf("%s",newNode->empPost);
    strcat(p,newNode->empPost);
    fprintf(fp,"%s\n",p);
    printf("Enter the name of the employee: \n");
    fflush(stdin);
    scanf("%s",newNode->empName);
    strcat(n,newNode->empName);
	fprintf(fp,"%s\n",n);
    printf("Enter the phone Number of the employee: \n");
    fflush(stdin);
    scanf("%s",newNode->empPhoNo);
    strcat(ph,newNode->empPhoNo);
    fprintf(fp,"%s\n",ph);
    printf("Enter the age of the employee: \n");
    fflush(stdin);
    scanf("%s",newNode->empAge);
    strcat(a,newNode->empAge);
	fprintf(fp,"%s\n",a);
    printf("Enter the address of the employee: \n");
    fflush(stdin);
    scanf("%s",newNode->empAddress);
    strcat(ad,newNode->empAddress);
	fprintf(fp,"%s\n",ad);
    printf("Enter the bus ID for the employee: \n");
    fflush(stdin);
    scanf("%s",newNode->empBusId);
    strcat(b,newNode->empBusId);
	fprintf(fp,"%s\n",b);
    printf("Enter the salary for the employee: \n");
    fflush(stdin);
    scanf("%s",newNode->empSalary);
    strcat(s,newNode->empSalary);
	fprintf(fp,"%s\n",s);
	printf("EMPLOYEE ADDED SUCCESSFULLY!!");
	fprintf(fp,"*********************************");
    fclose(fp);
    newNode->lchild = NULL;
	newNode->rchild = NULL;
	return(newNode);
}

int main(){
    int c1;
    int n,id,eid,e1id;
    struct employee *root=NULL;
    while (1){
        printf("\n\n1.Add Employee\n2.Employee Information\n3.Employee Deletion\n");
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("Enter the id of the employee: ");
                scanf("%d",&id);
                root = insert(root,id);
                c++;
                break;
            case 2:
                c1=-1;
                printf("Enter the id of the employee: ");
                scanf("%d",&e1id);
                inorder(root,e1id,c1);
                break;
            case 3:
                printf("Enter the id of the employee: ");
                scanf("%d",&eid);
                delete_node(root,eid);
                c--;
                printf("\n\nDetails deleted!!");
                break;
        }
    }
    return(0);
    
}

struct employee* insert(struct employee *root,int id){
    struct employee *temp=root;
    if(root == NULL){
        root = getNode(id);
        return(root);
    }
    while(1){
        if(temp->empId>id){
            if(temp->lchild==NULL){
                temp->lchild=getNode(id);
                break;
            }
            else{
                temp=temp->lchild;
            }
        }
        else{
            if(temp->rchild==NULL){
                temp->rchild=getNode(id);
                break;
            }
            else{
                temp=temp->rchild;
            }
        }
    }
    return(root);
}

struct employee *inorder(struct employee *root,int id,int count){
    count++;
    if(count==c){
        printf("details not found!!");
        return(0);
    }
    if(id == root->empId){
        printf("\n\nName = %s",root->empName);
        printf("\nEmployeeID = %d",root->empId);
        printf("\nDesignation = %s",root->empPost);
        printf("\nAge = %s",root->empAge);
        printf("\nPhoneNumber = %s",root->empPhoNo);
        printf("\nAddress = %s",root->empAddress);
        printf("\nSalary = %s",root->empSalary);
        printf("\nBusID = %s",root->empBusId);
        return(0);
    }    
    else if(root->empId > id){
        inorder(root->lchild,id,count);
    }
    else if(root->empId < id){
        inorder(root->rchild,id,count);
    }
        
}




struct employee* delete_node(struct employee *root,int id){
	FILE *fp,*fp1;
	char id1[10],re[100],a1[10];
	char buffer[100];
	fp=fopen("Employee.txt","r+");
	fp1=fopen("copy","a+");
	newNode=(struct employee *)malloc(sizeof(struct employee));
	newNode->empId=id;
    sprintf(a1,"%d",id);
    while(fscanf(fp,"%s",re) != EOF){
    	fprintf(fp1,"%s\n",re);
    	if(strcmp(re,a1)==0)
    	{
    		fprintf(fp1,"		->RECORD_DELETED\n");
    		fseek(fp,100,SEEK_CUR);
		}
	}
	fclose(fp);
	fclose(fp1);
	remove("Employee.txt");
	rename("copy","Employee.txt");
    if (root == NULL)
    return root;
    if (id < root->empId)
    root->lchild = delete_node(root->lchild,id);
    else if (id > root->empId)
    root->rchild = delete_node(root->rchild,id);
    else{
        if (root->lchild == NULL){
            struct employee *temp = root->rchild;
            free(root);
            return temp;
        }
        else if (root->rchild == NULL){
            struct employee *temp = root->lchild;
            free(root);
            return temp;
        }
    }
}
