#include<stdio.h>
#include<stdlib.h>
struct list
{
       int data;
       struct list* p;
};
struct list* init_node()
{
       struct list* n;
       n= (struct list * )malloc( sizeof(struct list));
       return n;
}
struct list* create_list()
{
       struct list * p ;
       p = init_node();
       if(p == NULL)
       {
            printf("Overflow.pls exit");
            return NULL;
       }
            
       printf("Enter Element ");
       int x;
       scanf("%d" , &x);
       p->data=x;
       p->p=NULL;
       struct list* q;
       int i;
       printf("Enter More Elements(1/0)");
       scanf("%d", &i);
       
       while(i!=0)
       {
        q= init_node();
          if(q == NULL)
            {
            printf("Overflow.pls exit");
            return p;
            }
           
         printf("Enter Element ");
          scanf("%d" , &x);
         q->data=x;
         q->p = p;
         p = q;
         printf("Enter More Elements(1/0)");
         scanf("%d", &i);
         }
         
         return p;
   }
   
struct list* eol(struct list* start)
{
       
 struct list* q;
 q= start;
 while(q->p!=NULL)
 {
   q=q->p;
}
return q;
}
struct list* ins_at_end(struct list* start) //working as intended
{
       struct list* end;
       end= eol(start);
       struct list* temp;
       temp= init_node();
       if(temp == NULL)
            {
            printf("Overflow.pls exit");
            return start;
            }
       printf("Enter element");
       scanf("%d" , &(temp->data));
       temp->p=NULL;
       end->p=temp;
       return start;
}
struct list* ins_at_mid(struct list* start)
{
       struct list* temp = start;
       struct list* k = init_node();
       if(k == NULL)
            {
            printf("Overflow.pls exit");
            return start;
            }
       int y;
       printf("Enter the element");
       scanf("%d" , &y);
       k->data = y;
       int x;
       printf("Enter the position you wish to enter in");
       scanf("%d" , &x);
       
       if(x==1)
       {   
           k-> p = start;
           start = k;
       return start;
           }
       else{
            int i;
            for(i=1;i<x-1&& temp!=NULL;++i)
                temp =temp->p;
            if(temp==NULL){ printf("List does not contain so many elements.Invalid Inoput");  return start;
}
            k->p = temp->p;
            temp->p = k;
            
            }
            return start;
}
struct list* search(struct list* start) // working as intended
{       
        int x;
        printf("Enter elemeent to search for");
        scanf("%d", &x);
       struct list * temp;
       temp = start;
       while(temp!=NULL)
       {
        if(temp->data ==x) return temp;
         temp = temp -> p;
         }
         
       if(temp== NULL)
       {
                 printf ("Element Not found");
                 return NULL;
                 }
}
void print_list(struct list*start)  //workinf as intended
{
     struct list* printer = start;
     if(printer==NULL)
     {
     printf("List IS EMPTY");
     return;
     }
     int k=0;
     while(printer!= NULL)
     {  ++k;
        printf("%d (%d) -> ", printer ->data,k);
        printer = printer -> p;
        }
return;
}
struct list* ins_at_start(struct list* start) // working as intended
{
       struct list* temp;
       temp=init_node();
       if(temp==NULL)
       {
                     printf("OVERFLOW" );
                     return start;
                     }
       int x;
       printf("Enter element ");
       scanf("%d", &x);
       temp->data=x;
       
       temp->p= start;
       start= temp;
 return start;
}
int main()
{
     struct list* m;
     struct list* s;
     m= create_list();
     
     int x = 0;
     while(x!=6)
     {
                printf("\n\n 1.Insert element at beginning \n\n 2. Insert Element at end \n\n 3. Insert element in the middle \n\n 4.search for element in list \n\n 5.Print List \n\n 6.Exit");
                scanf("%d" , &x);
                
                switch(x)
                {
                         case 1:
                              m=ins_at_start(m);
                              break;
                         case 2:
                              m=ins_at_end(m);
                              break;
                         case 3:
                              m=ins_at_mid(m);
                              break;
                         case 4:
                              s=search(m);
                              if(s!=NULL)
                              {
                                         printf("ELEMENT FOUND");
                                         }
                              break;
                         case 5:
                              print_list(m);
                              break;
                         case 6:
                              
                              printf("Thank you for using our program");
                              break;
                         default:
                              printf("Invalid Input ! Pls try again \n");
                              break;
                }
          }
return 0;          
}
                              
                         
                              
      
                 
                
       
       
       
         
       

