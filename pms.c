//PARKING MANAGEMENT SYSTEM

#include <stdio.h>
#include <stdlib.h>

//Declaration of Functions
void Addcar();
int Findcar();
void Carcost();

void Addbike();
int Findbike();
void Bikecost();

void Addrickshaw();
int Findrickshaw();
void Rickcost();

void Addbus();
int Findbus();
void Buscost();

void Total();
void Space();

//Parking Area Capacity(Maximum)
int tscar=100,tsbike=200,tsrick=50,tsbus=20;

//Initial capacity
int carcap=0,bikecap=0,rickcap=0,buscap=0;

//initial money collection
int carcost=0,bikecost=0,rickcost=0,buscost=0;

struct node
{   //data fields
    int cardata,bikedata,rickdata,busdata;
    
    //Link fields 
    struct node* carlink;
    struct node* bikelink;
    struct node* ricklink;
    struct node* buslink;
};

//Root declarations
struct node* startcar=NULL;
struct node* startbike=NULL;
struct node* startrick=NULL;
struct node* startbus=NULL;


void main()
{   int a,r1,r2,r3,r4;
    printf("\t-----------------------------------------------------------------\n");
    printf("\t                PARKING MANAGEMENT SYSTEM\n");
    printf("\t-----------------------------------------------------------------\n");
    printf("\t\tCAR\n\t\t1.Car is entering\n\t\t2.Car is exiting\n\t\t3.Total amount from car parking\n\n\t\tBIKE\n\t\t4.Bike is entering\n\t\t5.Bike is exiting\n\t\t6.Total amount from car parking\n\n\t\tAUTO RICKSHAW\n\t\t7.Auto Rickshaw is entring\n\t\t8.Auto Rickshaw is exiting\n\t\t9.Total amount from Auto Rickshaw parking\n\n\t\tBUS\n\t\t10.Bus is entering\n\t\t11.Bus is exiting\n\t\t12.Total amount from BUS parking\n\n\t\t13.Total amount collected from parking of all vehicles\n\t\t14.How many vehicles are present in parking area?\n");
    printf("\t-----------------------------------------------------------------\n");

do{
    printf("\n\t\tSelect a situation:-->");
    scanf("%d",&a);
    
    switch(a)
    { 
        case 1:Addcar(); 
               break;
                
        case 2:r1=Findcar();
               if(r1==0)
               printf("\t\tThere is no car in parking area.\n");
               else if(r1==1)
               printf("\t\tThere is no such car in parking lot\n");
               else
               printf("\t\tEntery for car number %d is deleted.\n",r1);
               break;
        case 3: Carcost();
                break;
        case 4:Addbike();
               break;
        case 5:r2=Findbike();
               if(r2==0)
               printf("\t\tThere is no bike in parking area.\n");
               else if(r2==1)
               printf("\t\tThere is no such bike in parking lot\n");
               else
               printf("\t\tEntery for bike number %d is deleted.\n",r2);
               break;
        case 6: Bikecost();
                break;
        case 7:Addrickshaw();
               break;
        case 8:r3=Findrickshaw();
               if(r3==0)
               printf("\t\tThere is no rickshaw in parking area.\n");
               else if(r3==1)
               printf("\t\tThere is no such rickshaw in parking lot\n");
               else
               printf("\t\tEntery for Auto Rickshaw number %d is deleted.\n",r3);
               break;
        case 9: Rickcost();
               break;
        case 10:Addbus();
               break;
        case 11:r4=Findbus();
               if(r4==0)
               printf("\t\tThere is no bus in parking area.\n");
               else if(r4==1)
               printf("\t\tThere is no such bus in parking lot\n");
               else
               printf("\t\tEntery for bus number %d is deleted.\n",r4);
               break;
     case 12: Buscost();
               break;
     case 13: Total();
               break;
     case 14: Space();
                break;
        default: printf("\t\tInvalid Choice.Thank You!\n");
    }
    
  }while(a>=1&&a<=14);
}



//************************CAR PARKING******************************

// Car is entering in parking area
void Addcar()
{ 
   carcost+=100;

 //Checks whether there is a space for parking or not    
 if(carcap<=tscar)  
 {
    struct node* p;
    p=(struct node*)malloc(sizeof(struct node));
    
    
    // Number written on number plate of car will be stored followed by district code at the beginining 
    // for example: MH 04 35837 
    // here MH is state code for any vehicle in Maharashtra which is understood so, there is no need to store this.
    // 04 indicates district code.
    // 35387 is the number.
    // program will store the number of vehicle as DistrictcodeCarNumber ie. 0435837
    
    
    printf("\t\tEnter the car number:");
    scanf("%d",&p->cardata);
     p->carlink=NULL;
    
//When parking Area is empty
    if(startcar==NULL)
    {
        startcar=p;
        carcap++;
        
        printf("\t\tEntry Successful!\n\n");
    }
//when one or more than Car is already parked in parking area
    else
    {
        struct node* p1;
        p1=startcar;
        
        while(p1->carlink != NULL)
        {
            p1=p1->carlink;
        }
        
//New Car number is stored
        p1->carlink=p;
        carcap++;
        printf("\t\tEntry Successful!\n\n");
    }
 }    
 else
 {
     printf("\t\tParking area for Car is full\n\n");
 }
    
}

// Finds the car in list and deletes the entry
int Findcar()
{   int n1,loc=1,i=1;
    if(carcap==0)
    {
     return 0;
    }
    
    else
    {
        printf("\t\tEnter the number of car exiting:");
        scanf("%d",&n1);
        
        struct node* f1;
        struct node* m1;
        struct node* z1;
        f1=startcar;
     
        if(f1->carlink==NULL && f1->cardata==n1)
        {
            carcap--;
            startcar=NULL;
            return n1;
        }
        else if(f1->carlink!=NULL)
        {
            while(f1!=NULL)
            { 
                loc++;
                if(f1->cardata==n1)
                {   
                    carcap--;
                    z1=startcar;
                    while(i<loc-1)
                    {
                       z1=z1->carlink;
                       i++;
                    }
                    z1->carlink=f1->carlink;
                    f1->carlink=NULL;
                    free (f1);
                    
                    return n1;
                
                }
                f1=f1->carlink;
            }
        }
        else
        {
          return 1;
        }
        
    }
}


void Carcost()
{
printf("\t\tTotal money collection from car parking = %d rupees\n",carcost);
}

//************************BIKE PARKING******************************

// BIKE is entering in parking area
void Addbike()
{  
   bikecost+=30;

 //Checks whether there is a space for parking or not    
 if(bikecap<=tsbike)  
 {
    struct node* q;
    q=(struct node*)malloc(sizeof(struct node));
 
    printf("\t\tEnter the car number:");
    scanf("%d",&q->bikedata);
     q->bikelink=NULL;
    
//When parking Area is empty
    if(startbike==NULL)
    {
        startbike=q;
        bikecap++;
        
        printf("\t\tEntry Successful!\n\n");
    }
//when one or more than one bike is already parked in parking area
    else
    {
        struct node* q1;
        q1=startbike;
        
        while(q1->bikelink != NULL)
        {
            q1=q1->bikelink;
        }
        
//New bike number is stored
        q1->bikelink=q;
        bikecap++;
        printf("\t\tEntry Successful!\n\n");
    }
 }    
 else
 {
     printf("\t\t>Parking area for Bike is full!\n\n");
 }
    
}

// Finds the bike in list and deletes the entry
int Findbike()
{   int n2,loc1=1,j=1;
    if(bikecap==0)
    {
     return 0;
    }
    
    else
    {
        printf("\t\tEnter the number of bike exiting:");
        scanf("%d",&n2);
        
        struct node* f2;
        struct node* m2;
        struct node* z2;
        f2=startbike;
     
        if(f2->bikelink==NULL && f2->bikedata==n2)
        {
            bikecap--;
            startbike=NULL;
            return n2;
        }
        else if(f2->bikelink!=NULL)
        {
            while(f2!=NULL)
            { 
                loc1++;
                if(f2->bikedata==n2)
                {   
                    bikecap--;
                    z2=startbike;
                    while(j<loc1-1)
                    {
                       z2=z2->bikelink;
                       j++;
                    }
                    z2->bikelink=f2->bikelink;
                    f2->bikelink=NULL;
                    free (f2);
                    
                    return n2;
                
                }
                f2=f2->bikelink;
            }
        }
        else
        {
          return 1;
        }
        
    }
}


void Bikecost()
{
printf("\t\tTotal money collection from Bike parking = %d rupees\n",bikecost);
}



//************************AUTO RICKSHAW PARKING******************************

// AUTO RICKSHAW is entering in parking area
void Addrickshaw()
{
   rickcost+=50;

 //Checks whether there is a space for parking or not    
 if(rickcap<=tsrick)  
 {
    struct node* t;
    t=(struct node*)malloc(sizeof(struct node));
    
    printf("\t\tEnter the Auto Rickshaw number:");
    scanf("%d",&t->rickdata);
     t->ricklink=NULL;
    
//When parking Area is empty
    if(startrick==NULL)
    {
        startrick=t;
        rickcap++;
        
        printf("\t\tEntry Successful!\n\n");
    }
//when one or more than auto are already parked in parking area
    else
    {
        struct node* t1;
        t1=startrick;
        
        while(t1->ricklink != NULL)
        {
            t1=t1->ricklink;
        }
        
//New Auto rickshaw number is stored
        t1->ricklink=t;
        rickcap++;
        printf("\t\tEntry Successful!\n\n");
    }
 }    
 else
 {
     printf("\t\tParking area for auto rickshaw is full\n\n");
 }
    
}

// Finds the Auto Rickshaw in list and deletes the entry
int Findrickshaw()
{   int n3,loc2=1,k=1;
    if(rickcap==0)
    {
     return 0;
    }
    
    else
    {
        printf("\t\tEnter the number of Auto rickshaw exiting:");
        scanf("%d",&n3);
        
        struct node* f3;
        struct node* m3;
        struct node* z3;
        f3=startrick;
     
        if(f3->ricklink==NULL && f3->rickdata==n3)
        {
            rickcap--;
            startrick=NULL;
            return n3;
        }
        else if(f3->ricklink!=NULL)
        {
            while(f3!=NULL)
            { 
                loc2++;
                if(f3->rickdata==n3)
                {   
                    rickcap--;
                    z3=startrick;
                    while(k<loc2-1)
                    {
                       z3=z3->ricklink;
                       k++;
                    }
                    z3->ricklink=f3->ricklink;
                    f3->ricklink=NULL;
                    free (f3);
                    
                    return n3;
                
                }
                f3=f3->ricklink;
            }
        }
        else
        {
          return 1;
        }
        
    }
}

void Rickcost()
{
printf("\t\tTotal money collection from Auto Rickshaw parking = %d rupees\n",rickcost);
}


//*****************BUS PARKING********************************
// BUS is entering in parking area
void Addbus()
{ 
   buscost+=200;
 //Checks whether there is a space for parking or not    
 if(buscap<=tsbus)  
 {
    struct node* s;
    s=(struct node*)malloc(sizeof(struct node));
  
    printf("\t\tEnter the Bus number:");
    scanf("%d",&s->busdata);
     s->buslink=NULL;
    
//When parking Area is empty
    if(startbus==NULL)
    {
        startbus=s;
        buscap++;
        
        printf("\t\tEntry Successful!\n\n");
    }
//when one or more than Bus is already parked in parking area
    else
    {
        struct node* s1;
        s1=startbus;
        
        while(s1->buslink != NULL)
        {
            s1=s1->buslink;
        }
        
//New Bus number is stored
        s1->buslink=s;
        buscap++;
        printf("\t\tEntry Successful!\n\n");
    }
 }    
 else
 {
     printf("\t\tParking area for Bus is full\n\n");
 }
    
}

// Finds the Bus in list and deletes the entry
int Findbus()
{   int n4,loc3=1,l=1;
    if(buscap==0)
    {
     return 0;
    }
    
    else
    {
        printf("\t\tEnter the number of Bus exiting:");
        scanf("%d",&n4);
        
        struct node* f4;
        struct node* m4;
        struct node* z4;
        f4=startbus;
     
        if(f4->buslink==NULL && f4->busdata==n4)
        {
            buscap--;
            startbus=NULL;
            return n4;
        }
        else if(f4->buslink!=NULL)
        {
            while(f4!=NULL)
            { 
                loc3++;
                if(f4->busdata==n4)
                {   
                    buscap--;
                    z4=startbus;
                    while(l<loc3-1)
                    {
                       z4=z4->buslink;
                       l++;
                    }
                    z4->buslink=f4->buslink;
                    f4->buslink=NULL;
                    free (f4);
                    
                    return n4;
                
                }
                f4=f4->buslink;
            }
        }
        else
        {
          return 1;
        }
        
    }
}

void Buscost()
{
printf("\t\tTotal money collection from Bus parking = %d rupees\n",buscost);
}



void Total()
{
printf("\t\tTotal Money collection of all the vehicles = %d\n",(carcost+bikecost+rickcost+buscost));
}

void Space()
{

printf("\n\t\t.......Timeline of Parking Area.......");

printf("\n\t\tTotal Number of Cars = %d",carcap);
printf("\n\t\tTotal Number of Bikes = %d",bikecap);
printf("\n\t\tTotal Number of Auto Rickshaws = %d",rickcap);
printf("\n\t\tTotal Number of Buses = %d\n\n",buscap);

}
