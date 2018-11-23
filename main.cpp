#include <iostream>
#include <cstring>


using namespace std;

/*class basic_acc;

class client
{
protected:
    string name ;
    string address;
    int phone;
    basic_acc* acc_obj [];

public:
    client (){}
    client( client arr[] )
    {
        int v;
        //basic_acc arr_[];
        cout<<"enter data of clients: "<<endl;
        for(int i=0 ; i<v ; i++)
        {
          cout<<"name of client "<<i+1<<" : ";
          cin>>arr[i].name;
          cout<<"address of client "<<i+1<<" : ";
          cin>>arr[i].address;
          cout<<"phone of client "<<i+1<<" : ";
          cin>>arr[i].phone;
          //client->arr_.id=i;
        }
    }
   friend class basic_acc ;
};*/
class basic_acc
{
protected:
    /*string name ;
    string address;
    int phone;
    int id ;
    double balance ;
    int type ;*/


public:
    string name ;
    string address;
    int phone;
    int id ;
    double balance ;
    string type ;

    basic_acc()
    {
        balance=0;
    }

    basic_acc ( basic_acc arr[] , int v )
    {

        //cout<<"enter data of clients: "<<endl;
        for(int i=0 ; i<v ; i++)
        {
          cout<<"name of client "<<i+1<<" : ";
          cin>>arr[i].name;
          cout<<"address of client "<<i+1<<" : ";
          cin>>arr[i].address;
          cout<<"phone of client "<<i+1<<" : ";
          cin>>arr[i].phone;
          cout<<"balance of client "<<i+1<<" : ";
          cin>>arr[i].balance;
          arr[i].id=i;
          cout<<"What Type of Account Do You Like? (Basic ,or Saving) for client "<<i+1<<" : ";
          cin>>arr[i].type;
          cout<<"An account was created with ID FCI-00"<<arr[i].id<<" && Balance: "<<arr[i].balance<<"  "<<endl;
          cout<<endl<<"__________________________________________________________________________"<<endl;
        }
    }

    void setbalance ( basic_acc arr[])
    {
       int t ;
       for (int i=0 ; i<t ; i++)
        {
            cout<<"enter balance for client "<<i+1<<": ";
            cin>>arr[i].balance;
        }
    }

    void getmin_value (basic_acc arr[])
    {
       int t ;
       for (int i=0 ; i<t ; i++)
         {cout<<"Balance of client "<<i+1<<"is:"<<arr[i].balance<<"  "<<endl;}
    }



    virtual void withdraw ( basic_acc arr[] , int v )
    {
        int id1 ;
        double d ;
        cout<<"enter account id:  ";
        cin>>id1;
        for(int i=0 ; i<v ; i++)
        {
          if(id1!=arr[i].id)
          {
            while (id1!=i)
            {
              cout<<"Not Found .."<<endl;
              cout<<"enter account id:  ";
              cin>>id1;
            }
          }
          else
              {
                cout<<"Account ID: FCI_00"<<arr[i].id<<endl;
                cout<<"Balance: "<<arr[i].balance<<endl;
                cout<<"enter the amount of money you to take \n";
                cin>>d;
                while ( d > arr[i].balance )
                {
                 cout<<"Your balance isn't sufficient\n";
                 cout<<"enter the amount of money you to take \n";
                 cin>>d;
                }
                arr[i].balance-=d;
                cout<<"thank you .. "<<endl;
                cout<<"Account ID: FCI_00"<<arr[i].id<<endl;
                cout<<"NEW BALANCE: "<<arr[i].balance<<endl;
              }//end of else
        }//end of for
    }//end of withdraw

    void deposit ( basic_acc arr[])
    {
        double g ;
        int id1 , v;
        cout<<"enter account id:  ";
        cin>>id1;
        for(int i=0 ; i<v ; i++)
        {
            if (id1!=i)
             {
              cout<<"Not Found .."<<endl;
              cout<<"enter account id:  ";
              cin>>id1;
             }
            cout<<"Account ID: FCI_00"<<arr[i].id<<endl<<endl;
            cout<<"Balance: "<<arr[i].balance<<endl<<endl;
            cout<<"enter the amount of money you want to deposit\n";
            cin>>g;
            arr[i].balance+=g;
            cout<<"DONE .. "<<endl<<endl;
            cout<<"NEW BALANCE:  "<<arr[i].balance<<endl<<endl;
            break;
        }
    }
    /*void print1 ()
    {
        cout<<"An account was created with ID : fci_"<<id<<" ,, and Starting Balance is : "<<balance<<"L.E\n\n";
    }*/

    void print1 ( basic_acc arr[] , int v)
    {
      //int v ;
      for(int i=0 ; i<v ; i++)
      {
        cout<<"\n\n____________________"<<arr[i].name<<"___________________\n\n";
        cout<<"Address : "<<arr[i].address<<endl<<endl;
        cout<<"Phone Number : "<<arr[i].phone<<endl<<endl;
        cout<<"Account_ID : FCI_00"<<arr[i].id<<" ,,, "<<arr[i].type<<"Account"<<endl<<endl;
        cout<<"Balance: "<<arr[i].balance<<endl<<endl;

      }
    }

};

class savings_acc : public basic_acc
{
protected:
    double min_value ;
public:
    savings_acc ()
    {

    }
    savings_acc ( savings_acc arr2[] , basic_acc arr[] , int t)
    {
        double v ;
        int id1;
        cout<<"enter account id:  ";
        cin>>id1;
        for (int i=0 ; i<t ; i++)
        {
          while (id1!=i)
            {
              cout<<"Not Found .."<<endl;
              cout<<"enter account id:  ";
              cin>>id1;
            }

              cout<<"YOUR CURRENT BALANCE: "<<arr[i].balance<<"   "<<endl;
              cout<<"enter amount of money you want to (save) in your account\n";
              cin>>v;
                  while (v > arr[i].balance)
                    {
                      cout<<"enter amount < your balance ("<<arr[i].balance<<")  "<<endl;
                      cin>>v;
                    }

                  arr2[i].min_value=v;
                  cout<<"DONE ...  "<<endl;

        }//end of for
    }//end of constructor
    void setmin_value ( savings_acc arr2[])
    {
       int t ;
       for (int i=0 ; i<t ; i++)
        {
            cout<<"enter amount of money for client "<<i+1<<": ";
            cin>>arr2[i].min_value;
        }
    }

    void getmin_value (savings_acc arr2[])
    {
       int t ;
       for (int i=0 ; i<t ; i++)
         {cout<<"the saved money of client "<<i+1<<"is:"<<arr2[i].min_value<<"  "<<endl;}
    }


    void withdraw ( savings_acc arr2[] , basic_acc arr[], int v)
    {
        int id1 ;
        double d ;
        cout<<"enter account id:  ";
        cin>>id1;
        for(int i=0 ; i<v ; i++)
        {
                if (id1==i)
                {
                cout<<endl<<"Account ID: FCI_00"<<arr[i].id<<endl<<endl;
                cout<<"Balance: "<<arr[i].balance<<endl<<endl;
                cout<<"enter the amount of money you to take \n";
                cin>>d;
                while ( d > arr[i].balance )
                {
                 cout<<"you should not withdraw amount < your saved money ("<<arr[i].balance<<")\n";
                 cout<<"enter the amount of money you to take \n";
                 cin>>d;
                }
                arr[i].balance-=d;
                cout<<"thank you .. "<<endl<<endl;
                cout<<"Account ID: FCI_00"<<arr[i].id<<endl<<endl;
                cout<<"NEW BALANCE: "<<arr[i].balance<<endl<<endl;
                }
                else
                {
                 cout<<"Not Found .."<<endl;
                 cout<<"enter account id:  ";
                 cin>>id1;
                }
        }//end of for
    }//end of override withdraw

    void deposit_ ( savings_acc arr2[] , basic_acc arr[])
    {
        int v , id1 ;
        double h ;
        cout<<"enter account id:  ";
        cin>>id1;
        for(int i=0 ; i<v ; i++)
        {
          while (id1!=i)
            {
              cout<<"Not Found .."<<endl;
              cout<<"enter account id:  ";
              cin>>id1;
            }

            cout<<"enter amount of money you want to deposit\n";
            cin>>h;
            while (h<100)
            {
            cout<<"your deposit must be >= 100 \n";
            cout<<"enter amount of money you want to deposit\n";
            cin>>h;
            }
            arr2[i].balance+=h;
            cout<<endl<<"DONE .. "<<endl<<endl;
            cout<<endl<<"NEW BALANCE :  "<<arr[i].balance<<endl<<endl;
        }//for
    }//deposite

};

/*void client:: print (basic_acc& x , client& t )
{
    cout<<"\n\n____________________"<<t.name<<"___________________\n\n";
    cout<<"Address : "<<t.address<<endl<<endl;
    cout<<"Phone Number : "<<t.phone<<endl<<endl;
    cout<<"Account_ID : "<<x.id<<endl<<endl;
    cout<<"Balance: "<<x.balance<<endl<<endl;


}*/



int main()
{
   savings_acc s ;
   basic_acc &a=s ;
   int c  ;
   int v1;
   cout<<"enter number of clients: "<<endl;
   cin>>v1;
   basic_acc arr[v1];
   savings_acc arr2[v1];
   cout<<"welcome to FCI Banking Application\n\n";
   cout<<"1. enter data of clients\n";
   cout<<"2. List Clients and Accounts\n";
   cout<<"3. Withdraw Money\n";
   cout<<"4. Deposit Money\n";
   cout<<"Please Enter Choice =========>  ";
   cin>>c;

    while (c!=0)
    {
     if ( c==1 )
       {
           basic_acc a (arr,v1);
           for (int i=0 ; i<v1 ; i++)
           {
               if(arr[i].type=="saving"||arr[i].type=="Saving")
               {
                   savings_acc s (arr2,arr,v1);
               }
           }
       }
     if (c==2)
       {
           a. print1(arr,v1) ;
       }
     if (c==3)
     {
           for (int i=0 ; i<v1 ; i++)
           {
               if(arr[i].type=="basic"||arr[i].type=="Basic")
                   {a.withdraw(arr,v1);}
               if(arr[i].type=="saving"||arr[i].type=="Saving")
                   {
                     s.withdraw(arr2,arr,v1);
                   }
           }

     }
    if (c==4)
    {
         for (int i=0 ; i<v1 ; i++)
           {
               if(arr[i].type=="basic"||arr[i].type=="Basic")
                   {
                     a.deposit(arr);
                   }
               if(arr[i].type=="saving"||arr[i].type=="Saving")
                   {
                     s.deposit_(arr2,arr);
                   }
           }
    }
   cout<<"welcome to FCI Banking Application\n\n";
   cout<<"1. Create a New Account\n";
   cout<<"2. List Clients and Accounts\n";
   cout<<"3. Withdraw Money\n";
   cout<<"4. Deposit Money\n";
   cout<<"Please Enter Choice =========>  ";
   cin>>c;
   }
    return 0 ;
}
