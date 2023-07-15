#include<iostream>
#include<fstream>

using namespace std;

class market
{

    int pcode;
    float price;
    float dis;
    string pname;

    public:
        void menu();
        void admin();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void recipt();

};

void market::menu()
{
    m:
    int choice;
    string email;
    string pw;

    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t\t__________________________________________\n";
    cout<<"\t\t\t\t                                          \n";
    cout<<"\t\t\t\t                User Type                 \n";
    cout<<"\t\t\t\t                                          \n";
    cout<<"\t\t\t\t__________________________________________\n";
    cout<<"\t\t\t\t                                          \n";
    cout<<"\t\t\t\t|     1.  Administrator                  |\n";
    cout<<"\t\t\t\t|                                        |\n";
    cout<<"\t\t\t\t|     2.  Customer                       |\n";
    cout<<"\t\t\t\t|                                        |\n";
    cout<<"\t\t\t\t|     3.  Exit                           |\n";
    cout<<"\t\t\t\t|                                        |\n";
    cout<<"\n\t\t\t\t Enter your choice:";
    cin>>choice;

    switch(choice)
    {
        case 1:
            cout<<"\t\t\t Please login! \n";
            cout<<"\t\t\t Enter E-mail: ";
            cin>>email;
            cout<<"\t\t\t Enter password: ";
            cin>>pw;

            if(email=="sarkar@gmail.com" && pw=="301205")
            {
                admin();
            }
            else
            {
                cout<<"Invalid Credentials";
            }
            break;

        case 2:
            buyer();
            break;
        
        case 3:
            exit(0);
            break;

        default:
            cout<<"Invalid Choice!";    
    }

    goto m;

}

void market::admin()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Administrator Menu ";
    cout<<"\n\t\t\t|     1) Add a product         |";
    cout<<"\n\t\t\t|                              |";
    cout<<"\n\t\t\t|     2) Modify a product      |";
    cout<<"\n\t\t\t|                              |";
    cout<<"\n\t\t\t|     3) Delete a product      |";
    cout<<"\n\t\t\t|                              |";
    cout<<"\n\t\t\t|     4) Back                  |";
    cout<<"\n\t\t\t|                              |";

    cout<<"\n\n\t Enter your choice: ";
    cin>>choice;

    switch(choice)
    {
        case 1:
            add();
            break;

        case 2:
            edit();
            break;

        case 3:
            rem();
            break;
        
        case 4:
            menu();
            break;

        default:
            cout<<"Invalid choice!";    

    }

    goto m;

}

void market::buyer()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Customer Menu ";
    cout<<"\n\t\t\t|     1) Buy a product         |";
    cout<<"\n\t\t\t|                              |";
    cout<<"\n\t\t\t|     2) Back                  |";
    cout<<"\n\t\t\t|                              |";

    cout<<"\n\n\t Enter your choice: ";
    cin>>choice;

    switch(choice)
    {
        case 1:
            recipt();
            break;

        case 2:
            menu();
            break;

        default:
            cout<<"Invalid choice!";

    }

    goto m;

}

void market::add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Adding new product...";
    cout<<"\n\n\t Product Code: ";
    cin>>pcode;
    cout<<"\n\n\t Product Name: ";
    cin>>pname;
    cout<<"\n\n\t Product Price: ";
    cin>>price;
    cout<<"\n\n\t Product Discount: ";
    cin>>dis;

    data.open("Database.txt",ios::in);

    if(!data)
    {
        data.open("Database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;

        while(!data.eof())
        {
            if(c==pcode)
                token++;
            data>>c>>n>>p>>d;
        }
        data.close();

        if(token==1)
            goto m;

        else
        {
            data.open("Database.txt",ios::app|ios::out);
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            data.close();
        }    
    }

    cout<<"\n\n\t\t Record Inserted!";

}

void market::edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Modifying product...";
    cout<<"\n\n\t Product Code: ";
    cin>>pkey;

    data.open("Database.txt",ios::in);
    if(!data)
    {
        cout<<"\n File doesn't exist!";
    }
    else
    {
        data1.open("Database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\n\t New Product Code: ";
                cin>>c;
                cout<<"\n\n\t New Product Name: ";
                cin>>n;
                cout<<"\n\n\t New Product Price: ";
                cin>>p;
                cout<<"\n\n\t New Product Discount: ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record Modified!";
                token++;
            }

            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }

        data.close();
        data1.close();

        remove("Database.txt");
        rename("Database1.txt","Database.txt");

        if(token==0)
            cout<<"\n\n Record Not found!";
    
    }

}

void market::rem()
{

    fstream data,data1;
    int pkey;
    int token=0;

    cout<<"\n\n\t\t\t Deleting product...";
    cout<<"\n\n\t Product Code: ";
    cin>>pkey;

    data.open("Database.txt",ios::in);
    if(!data)
    {
        cout<<"\n File doesn't exist!";
    }
    else
    {
        data1.open("Database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        
        while(!data.eof())
        {
            if(pkey!=pcode)
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            else
            {
                cout<<"\n\n\t\t Record Deleted!";
                token++;
            }
            data>>pcode>>pname>>price>>dis;
        }

        data.close();
        data1.close();

        remove("Database.txt");
        rename("Database1.txt","Database.txt");

        if(token==0)
            cout<<"\n\n Record not found!";
    }

}

void market::list()
{
    fstream data;
    data.open("Database.txt",ios::in);
    cout<<"\n\n|___________________________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n|___________________________________________________\n";
    data>>pcode>>pname>>price>>dis;

    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }

    data.close();
}

void market::recipt()
{
    fstream data;

    int arrc[100]={0};
    int arrq[100]={0};
    char choice;
    int k=0;
    float sum=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\tList";

    data.open("Database.txt",ios::in);
    if(!data)
        cout<<"\n\n Empty Database!";
    else
    {
        data.close();

        list();
        cout<<"\n__________________________________________________________\n";
        cout<<"\n|                                                        |\n";
        cout<<"\n                  Please Place the Order                  \n";
        cout<<"\n|                                                        |\n";
        cout<<"\n__________________________________________________________\n";

        do
        {
            m:
            cout<<"\n\n Enter Product Code: ";
            cin>>arrc[k];
            cout<<"\n\n Enter Product Quantity: ";
            cin>>arrq[k];
            
            for(int i=0;i<k;i++)
            {
                if(arrc[k]==arrc[i])
                {
                    cout<<"\n\n Duplicate Product Code! Please try again.";
                    goto m;
                }
            }
            k++;
            cout<<"\n\nDo you want to buy another product?(y/n) \nAnswer: ";
            cin>>choice;

        } while (choice=='y');
                
        cout<<"\n\n_______________________________________________RECIPT_________________________________________________\n";
        cout<<"\nProduct No \tProduct Name \t Product quantity \t Price \t\t Amount \t Amount with discount\n";

        for(int i=0;i<k;i++)
        {

            data.open("Database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                
                if(arrc[i]==pcode)
                {
                    
                    amount=price*arrq[i];
                    total=amount-(amount*dis/100);
                    sum+=total;
                    
                    cout<<"\n"<<arrc[i]<<"\t\t "<<pname<<"\t\t "<<arrq[i]<<"\t\t\t "<<price<<"\t\t "<<amount<<"\t\t "<<total;
                }
                data>>pcode>>pname>>price>>dis;

            }
        }
        data.close();

        cout<<"\n\n______________________________________________________________________________________________________";
        cout<<"\n Total Amount: "<<sum;
        sum=0;
    }    
}

int main()
{
    market x;
    x.menu();
    return 0;
}