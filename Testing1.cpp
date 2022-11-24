#include <iostream>
#include <string>

using namespace std;
int ptype;
int flag;
string searchProdName;
string searchBrand;

   struct inventory
{
    string pname;
    string brand;
    int qty;
    double cost;
    double price;
    int id;
    int num;

} p[100];//can only insert 100 items

void print_menu()//display badminton products and brands
{
    cout<<"\n\t\t\t\t Menu\n";
    cout<<"+-----------------------------------------------------------------------+"<<endl;
    cout<<"| List. |\t\tProduct\t\t   |\t\tBrand\t\t|"<<endl;
    cout<<"+-----------------------------------------------------------------------+"<<endl;
    cout<<"|   a.\t|\t\tRacquet\t\t   |\t\tYonex\t\t|\n|   b.\t|\t\t\t\t   |\t\tLi Ning\t\t|\n|   c.\t|\t\t\t\t   |\t\tFleet\t\t|\n|   d.\t|\t\t\t\t   |\t\tApacs\t\t|\n|   e.\t|\t\t\t\t   |\t\tVictor\t\t|"<<endl;
    cout<<"+-----------------------------------------------------------------------+"<<endl;
    cout<<"|   f.\t|\tBadminton Shuttlecock\t   |\t\tYonex\t\t|\n|   g.\t|\t\t\t\t   |\t\tLi Ning\t\t|\n|   h.\t|\t\t\t\t   |\t\tRSL\t\t|\n|   i.\t|\t\t\t\t   |\t\tLing Mei\t|"<<endl;
    cout<<"+-----------------------------------------------------------------------+"<<endl;
    cout<<"|   j.\t|\t   Badminton Grip\t   |\t\tYonex\t\t|\n|   k.\t|\t\t\t\t   |\t\tLi Ning\t\t|\n|   l.\t|\t\t\t\t   |\t\tApacs\t\t|\n|   m.\t|\t\t\t\t   |\t\tVictor\t\t|"<<endl;
    cout<<"+-----------------------------------------------------------------------+"<<endl;

}
void Insert()//store the details of product such as product name, brand, quantity, cost and selling price
{
    char choice,con;
            do
            {
                cout<<"How many product you want to insert?(max 100): ";//max can enter only 100 items
                cin>>ptype;
                if(!(0<ptype)||!(ptype<=100))
                {
                     cout<<"Invalid number!"<<endl;
                }
            }while(!(0<ptype)||!(ptype<=100));

            for(int i=0;i<ptype;i++)
            {
                p[i].id=i+1;
                cout<<""<<p[i].id<<"."<<endl;
                do
                {
                    cout<<"Enter a choice from the menu(a-m): ";//choose the item from the menu by entering a-m and the name will be displayed
                    cin>>choice;
                    if((choice=='a')||(choice=='A'))
                    {
                        p[i].pname="Racquet";
                        p[i].brand="Yonex";
                    }
                    if((choice=='b')||(choice=='B'))
                    {
                        p[i].pname="Racquet";
                        p[i].brand="Li Ning";
                    }
                    if((choice=='c')||(choice=='C'))
                    {
                        p[i].pname="Racquet";
                        p[i].brand="Fleet";
                    }
                    if((choice=='d')||(choice=='D'))
                    {
                        p[i].pname="Racquet";
                        p[i].brand="Apacs";
                    }
                    if((choice=='e')||(choice=='E'))
                    {
                        p[i].pname="Racquet";
                        p[i].brand="";
                    }
                    if((choice=='f')||(choice=='F'))
                    {
                        p[i].pname="";
                        p[i].brand="Yonex";
                    }
                    if((choice=='g')||(choice=='G'))
                    {
                        p[i].pname="";
                        p[i].brand="Li Ning";
                    }
                    if((choice=='h')||(choice=='H'))
                    {
                        p[i].pname="Shuttlecock";
                        p[i].brand="";
                    }
                    if((choice=='i')||(choice=='I'))
                    {
                        p[i].pname="Shuttlecock";
                        p[i].brand="";
                    }
                    if((choice=='j')||(choice=='J'))
                    {
                        p[i].pname="Badminton Grip";
                        p[i].brand="Yonex";
                    }
                    if((choice=='k')||(choice=='K'))
                    {
                        p[i].pname="Badminton Grip";
                        p[i].brand="Li Ning";
                    }
                    if((choice=='l')||(choice=='L'))
                    {
                        p[i].pname="Badminton Grip";
                        p[i].brand="Apacs";
                    }
                    if((choice=='m')||(choice=='M'))
                    {
                        p[i].pname="Badminton Grip";
                        p[i].brand="Victor";
                    }
                    cout<<p[i].pname<<" - "<<p[i].brand<<"\n";
                    if ((choice>'m')&&(choice>'M'))
                    {
                        cout<<"Please enter an alphabet within a-m\n\n";
                    }
                }while((choice>'m')&&(choice>'M'));
                do
                {
                    cout<<"Enter quantity of product: ";//enter quantity of the item
                    cin>>p[i].qty;
                    if (p[i].qty<=0)
                    {
                        cout<<"\nProduct quantity must be > 0\n";
                    }
                }while (p[i].qty<=0);
                do
                {
                    cout.setf(ios::fixed);
                    cout.setf(ios::showpoint);
                    cout.precision(2);
                    cout<<"Enter cost of product: ";//enter cost of the item
                    cin>>p[i].cost;
                    if (p[i].cost<=0)
                    {
                        cout<<"\nProduct cost must be > 0\n";
                    }
                }while (p[i].cost<=0);
                do
                {
                    cout<<"Enter selling price of product: ";//enter selling price of the item so that the
                    cin>>p[i].price;                         //profit will be counted during checkout
                    if (p[i].price <= 0)
                    {
                        cout<<"\nProduct selling price must be > 0\n";
                    }
                    if(p[i].price <= p[i].cost)
                    {
                        cout<<"\nProduct selling price must be greater than product cost\n";
                    }
                }while ((p[i].price<= 0) || (p[i].price <= p[i].cost));
                }
            }

void Display()//display the list and details of products in the form of table.
{
         char choice;
         cout<<"Below are the details of product:"<<endl<<endl;
         cout<<" Id\tName\t\t\tBrand\t\tQuantity\t Cost(RM)\t Selling Price(RM)"<<endl;


         for(int i=0;i<ptype;i++)
         {
          cout<<" "<<p[i].id<<"\t"<<p[i].pname<<" \t\t"<<p[i].brand<<"\t\t   "<<p[i].qty<<"\t\t  "<<p[i].cost<<"\t\t"
          <<p[i].price<<endl<<endl;
         }
}
void Search()//by enter the name and brand, the details of the products will be shown
{
            flag=1;
            cin.ignore();
            cout<<"Enter name of product you want to find: ";
            getline(cin,searchProdName);
            cout<<"Enter the brand of product you want to find: ";
            getline(cin,searchBrand);
            for(int i=0;i<ptype;i++)
            {
                if ((searchProdName == p[i].pname)&&(searchBrand == p[i].brand))
                {
                    flag=0;
                    cout<<"Name of Product: "<<p[i].pname<<endl;
                    cout<<"Brand of Product: "<<p[i].brand<<endl;
                    cout<<"Quantity of product: "<<p[i].qty<<endl;
                    cout<<"Cost of product: "<<p[i].cost<<endl;
                    cout<<"Selling price of product: "<<p[i].price<<endl;
                    cout<<"Product "<<p[i].pname<<" found."<<endl<<endl;
                }
            }
            if(flag==1)
            {
                cout<<"Product not found in inventory system."<<endl<<endl;
            }
}

void Delete()//delete either one product or all products, and will automatically updated in the table form when enter choice 2 (display function)
{
    int ptype;
    int deleteNum;
    cout<<"Delete one or all products(Enter 1 for one or 2 for all):";
    cin>>deleteNum;
    if(deleteNum==1)
    {
        int i;
        cout<<"Which product you want to delete(Enter product id): ";
        cin>>i;
        i=i-1;
        if(i>ptype||i<0)
        {
            cout<<"Invalid Id!"<<endl;
            Delete();
        }
        else
        {
            p[i].pname="Empty";
            p[i].brand="\tEmpty";
            p[i].qty=0;
            p[i].cost=0;
            p[i].price=0;
            cout<<"Deleted successfully."<<endl;
        }
    }
    else if(deleteNum==2)
    {
        int i;
        int ptype=100;
        for(i=0;i<ptype;i++)
        {
            p[i].pname="Empty";
            p[i].brand="\tEmpty";
            p[i].qty=0;
            p[i].cost=0;
            p[i].price=0;
        }
        cout<<"All product deleted successfully."<<endl;
    }
    else
    {
        cout<<"Invalid option.Please enter 1 for delete one or 2 for delete all product."<<endl;
    }
}

void Update()//change the details of the same product or different products
{
    int i;
    int ptype=100;
    cout<<"Which product you want to modify(Enter product id): ";
    cin>>i;
    i=i-1;
    if(i>ptype||i<0)
    {
        cout<<"Invalid Id!"<<endl;
        Update();
    }
    else
    {
        cin.ignore();
        cout<<"Enter new name: ";
        getline(cin,p[i].pname);
        cout<<"Enter new brand: ";
        getline(cin,p[i].brand);
        cout<<"Enter new quantity: ";
        cin>>p[i].qty;
        cout<<"Enter new cost: ";
        cin>>p[i].cost;
        cout<<"Enter new selling price: ";
        cin>>p[i].price;
    }
    cout<<"Updated successfully.\n";
}


void Checkout(){//the products are sold and qty and profit will be updated
                //in the table form when enter choice 2 (display function)
    int i;
    int ptype=100;
    int qtyCheckout;
    cout<<"Enter product id: ";
    cin>>i;
    i=i-1;
    cout<<"How many product you want to checkout: ";
    cin>>qtyCheckout;
    if(i>ptype||i<0)
    {
        cout<<"Invalid Id!"<<endl;
        Checkout();
    }
    else
    {
        if (qtyCheckout>p[i].qty)
        {
            cout<<"Invalid quantity for checkout."<<endl<<endl;
        }
        else
        {
          p[i].qty=p[i].qty-qtyCheckout;//qty of products will be deducted and display if choosing display function
          double profit;
          profit=qtyCheckout*(p[i].price-p[i].cost);//profit will be calculated after the checkout of product
          cout<<"Profit is RM"<<profit;
          cout<<"\n\t\t\tProduct Checkout...  Successfully "<<endl;
        }
    }

}


 int main()
{
    string name;
    int pass;
    string userName="a";
    int password=1;
    int op;
    string searchProdName;
    string searchBrand;
    int flag;
    int tryCount=0;
    int tryLimit=3;
    bool outOfTry=false;
    int choice;
    int ptype=100;
    int newPassword;
    char change;

    system("color 75");//change the bg and text colour

    cout<<" \n\n\n\n\n\n\t\t\t\t1.Enter Inventory System  \n\t\t\t\t2.Account & Security\n \t\t\t\t3.Exit\n";
    cout<<"\n\n\t\tChoose your option(1-3): ";
    cin>>choice;
    cout<<endl;
    if(choice==3)//exit the program
    {
        cout<<"\n\n\n\n\n\n\t\tProgram Ended. Press Any Key To Exit Screen ^U^\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
        return 0;
    }
    else if(choice==2)//change the pw
    {
        cout<<"\t\tEnter user name:";
        cin>>name;
        cout<<"\t\tEnter password(in number):";//enter the username and old pw before changing pw
        cin>>pass;
        if (userName != name || password != pass)
        {
            cin.clear();
            cin.ignore();
            cout<<"\n\t\tSorry,invalid user name or password!"<<endl<<endl;
            main();
        }
        else
        {
            cout<<"\nDo you want to change password(Y/N): ";
            cin>>change;
            if(change=='Y'||change=='y')
            {
                cout<<"Enter new password(Original Password If you Don't Want to Change): ";
                cin>>newPassword;
                if(newPassword==password)
                {
                    cout<<"Password not changed...";
                    main();
                }
                cout<<"\t\t*** Changed successfully ***"<<endl;
                password=newPassword;
            }
            else if(change=='N'||change=='n')
            {
                main();
            }
            else
            {
                cout<<"\t\t*** Invalid option! ***";
                main();
            }
        }
    }
    if(choice==1||choice==2)
    {
        while(password != pass && !outOfTry)
        {
            if(tryCount<tryLimit)
            {
                do
                {
                    system("cls");
                    cout<<"\n\t\t\t\tWelcome to Inventory System. ^U^ "<<endl<<endl;
                    cout<<"\t\tEnter user name:";
                    cin>>name;
                    cout<<"\t\tEnter password(in number):";
                    cin>>pass;
                    if(userName!=name||password!=pass)
                        tryCount++;
                    if (userName != name || password != pass)
                    {
                        cin.clear();
                        cin.ignore();
                        cout<<"Sorry,invalid user name or password!"<<endl<<endl;
                    }
                    if (userName == name && password == pass)
                    {
                        print_menu();
                        do
                        {
                            cout<<"\n 1.Insert product \n 2.Display detail of the product \n 3.Search product"
                            "\n 4.Checkout \n 5.Update \n 6.Delete \n 7.Exit"<<endl;
                            cout<<"\nChoose your option(1-7):";
                            cin>>op;
                            cout<<"\n";
                            switch(op)
                            {
                                case 1:
                                    Insert();
                                    break;

                                case 2:
                                    Display();
                                    break;

                                case 3:
                                    Search();
                                    break;

                                case 4:
                                    Checkout();
                                    break;

                                case 5:
                                    Update();
                                    break;

                                case 6:
                                    Delete();
                                    break;

                                case 7:
                                    system("cls");
                                    cout<<"\n\n\n\n\n\n\n\t\t\tThank you for choosing us.\n\t\t\tEnjoy Your Products! ^U^\n";
                                    cout<<"\n\n\n\n\n\n\t\tProgram Ended. Press Any Key To "
                                    "Exit Screen ^U^\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
                                    return 0;
                                    break;

                                default:
                                    cout<<"Invalid option!"<<endl<<endl;
                            }
                        }while(op>=1||op<=6);
                    }
                }while (tryCount<tryLimit);//can only enter a wrong username or password in 3 attempts
            }
            else
            {
                outOfTry=true;
            }
            if(outOfTry)
            {
                cout<<"Sorry, maximum login limit reached.";
                cout<<"\n\n\n\n\n\n\t\tProgram Blocked. Press Any Key To Exit Screen ^U^\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
            }
        }

    }
    else
    {
      cout<<"\n\t\t\t\tInvalid choice!";
      main();
    }
    return 0;
}



