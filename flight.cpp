#include<iostream>
#include<cstring>

using namespace std;

class node{
    public:
        int cityindex;
        int distance;
        node * next;
        
        node(int ind, int dis)
        {
             cityindex=ind;
             distance = dis;
             next = NULL;
        }
};

class graph{
     public:
         int v,e;
         int a[100][100];
         string cities[100];
         node* list[100];
         
         graph(int x, int y)
         {
            v=x;
            e=y;
            for(int i = 0 ; i< v; i++)
            {
               list[i] = nullptr;
               for(int j = 0; j<v; j++)
               {
                   a[i][j]=0;
               }
            }
         }

         int findindex(string city)
         {
             for(int i =0 ; i<v ; i++)
             {
                  if (cities[i]==city)
                  {
                      return i;
                  }
                     
             }
             return -1;
         }

         void getflight(int w, string scity, string dcity)
         {
               int u = findindex(scity);
               int v = findindex(dcity);
               if(v==-1 || u==-1)
               {
                 cout<<"\nInvalide city!!!";
                 return;
               }
               a[u][v] = w;
               a[v][u] = w;
               node* newnode1 = new node(v,w);
               newnode1->next = list[u];
               list[u] = newnode1;

               node* newnode2 = new node(u,w);
               newnode2->next = list[v];
               list[v] = newnode2;
         } 

         void display()
        {
             cout<<"\nAdjacency Matrix for flight!!!!\n";
             cout<<"          ";
             for(int i = 0 ; i< v; i++)
            {
               cout<<cities[i]<<"         ";
                
            }
            for(int i = 0 ; i< v; i++)
            {
               cout<<cities[i]<<"         ";
               cout<<endl; 
               for(int j = 0; j<v; j++)
               {
                   cout<<a[i][j]<<"       ";
               }
               cout<<endl;
            }
  
        }

        void displayl()
         {
            cout<<"\nAdjacency list:";
            for(int i=0 ; i<v ; i++)
             {
                cout<<"\nCity "<<cities[i]<<"->\t";
                 node* temp = list[i];
                 while(temp)
                 {
                    cout<<cities[temp->cityindex]<<"("<<temp->distance<<")"<<"->\t";
                    temp=temp->next;
                 }
                 cout<<endl;
               }
           }
      
};

int main()
{
    int v,e,we;
    cout<<"\n Enter number of city and route:\t";
    cin>>v>>e;
     
    graph g(v,e);
     
    for(int i=0 ; i<v ; i++)
    {
       cout<<"\nEnter city number "<<i+1<<" name:\t";
       cin>>g.cities[i];
     }
    
    //g.getcities();
    int ch;
    do
    {
       cout<<"\nEnter your choice\n1.Enter data\n2.Display\n3.Exits";
       cin>>ch;
       switch(ch)
       {
           case 1:
                for(int i=0 ; i<e ; i++)
                {
                    string s_city ,d_city;
                    cout<<"\nEnter soruce city and destination city:\t";
                    cin>>s_city>>d_city;
                    cout<<"\nEnter distance:\t";
                    cin>>we;
                    g.getflight(we,s_city,d_city);
                 }
                 break;
           case 2:
                g.display();
                g.displayl();
                break;
           case 3:
                cout<<"\nExiting program\n";
                break;
           default:
                cout<<"\nInvalide choice!!!";
                break;
          
        }
    }while(ch!=3);
  return 0;
    
}

