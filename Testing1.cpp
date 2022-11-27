#include <iostream>
using namespace std;

static int inventoryLimit = 100;
string searchProdName;
string searchBrand;

int productCount = 0;
struct inventory
{
    int id; //+1 offset to number of product, e.g. product[0] has ID of 1.
    string type; 
    string brand;
    int qty;
    double buyPrice;
    double sellPrice;
} product[100];

string stringToLower(string str) {
    //Lower all the characters for case insensitive comparison, created due to predefined method not able to convert strings.
    for (int i = 0; str[i]!='\0'; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z') 
			str[i] = str[i] + 32;
	}
    return str;
}

void print_menu()
{
    //Display all the products and brands.

    /* Note: All items aligned left for least complexity.
       Also note: This list can be dynamic in the future.
    */
    system("cls");
    cout
    <<  " Product List                        \n"
    <<  "+------+--------------+-------------+\n"
    <<  "| List | Product      | Brand       |\n"
    <<  "+------+--------------+-------------+\n"
    <<  "|  a.  | Racquet      | Yonex       |\n"
    <<  "|  b.  |              | Li Ning     |\n"
    <<  "|  c.  |              | Fleet       |\n"
    <<  "|  d.  |              | Apacs       |\n"
    <<  "|  e.  |              | Victor      |\n"
    <<  "+------+--------------+-------------+\n"
    <<  "|  f.  | Shuttlecock  | Yonex       |\n"
    <<  "|  g.  |              | Li Ning     |\n"
    <<  "|  h.  |              | RSL         |\n"
    <<  "|  i.  |              | Ling Mei    |\n"
    <<  "+------+--------------+-------------+\n"
    <<  "|  j.  | Grip tape    | Yonex       |\n"
    <<  "|  k.  |              | Li Ning     |\n"
    <<  "|  l.  |              | Apacs       |\n"
    <<  "|  m.  |              | Victor      |\n"
    <<  "+------+--------------+-------------+\n";
}
void Insert()
{
    char choice, next;
    int i;
    string input;
    do  //Adding one item section, with further do while loop responsible for details of that item.
    {
        print_menu();
        i = productCount; 
        product[i].id = i + 1;
        cout << ""<< product[i].id << "." << endl; //Storing starts from 0, but humans start counting from 1
        do  //Type and brand of product
        {   
            //WARNING: Infinite loop in this method (do while loops), this is also true on other cin input where it's broken when letters are inputted.
            cout << "Enter a choice from the menu(a-m) from product " << product[i].id << ":";
            cin  >> choice;
            switch (toupper(choice))
            {
                case 'A':
                    product[i].type="Racquet"; product[i].brand="Yonex";
                    break;
                case 'B':
                    product[i].type="Racquet"; product[i].brand="Li Ning";
                    break;
                case 'C':
                    product[i].type="Racquet"; product[i].brand="Fleet";
                    break;
                case 'D':
                    product[i].type="Racquet"; product[i].brand="Apacs";
                    break;
                case 'E':
                    product[i].type="Racquet"; product[i].brand="Victor";
                    break;
                case 'F':
                    product[i].type="Shuttlecock"; product[i].brand="Yonex";
                    break;
                case 'G':
                    product[i].type="Shuttlecock"; product[i].brand="Li Ning";
                    break;
                case 'H':
                    product[i].type="Shuttlecock"; product[i].brand="RSL";
                    break;
                case 'I':
                    product[i].type="Shuttlecock"; product[i].brand="Ling Mei";
                    break;
                case 'J':
                    product[i].type="Grip tape"; product[i].brand="Yonex";
                    break;
                case 'K':
                    product[i].type="Grip tape"; product[i].brand="Li Ning";
                    break;
                case 'L':
                    product[i].type="Grip tape"; product[i].brand="Apacs";
                    break;
                case 'M':
                    product[i].type="Grip tape"; product[i].brand="Victor";
                    break;
                default:
                    break;
            }
                if ((toupper(choice) < 'A') || (toupper(choice) > 'M'))
                    cout << "Please enter an alphabet within a-m\n";
            
        }   while((toupper(choice) < 'A') || (toupper(choice) > 'M')); //If error, try again
        
        do  //Qty of product
        {   //NOTE: This will have inf loop if single letters are entered (as if it's >0)
            cout << product[i].type << " - " << product[i].brand << "\n";
            cout << "Enter quantity of product: ";
            cin  >> product[i].qty;
            if (product[i].qty <= 0) 
                cout << "Invalid input.\n";
        }   while (product[i].qty <= 0); //If error, try again
        
        do  //Cost of product
        {
            cout.setf(ios::fixed, ios::showpoint);
            cout.precision(2);
            cout << "Enter cost of product: ";
            cin  >> product[i].buyPrice;
            if (product[i].buyPrice <= 0)
                cout<<"\nInvalid product cost.\n";
        }   while (product[i].buyPrice <= 0);
        
        do  //Selling price of product
        {
            cout<<"Enter selling price of product: ";
            cin>>product[i].sellPrice;
            if (product[i].sellPrice <= 0)
            {
                cout << "\nProduct selling price must be > 0\n";
            }
            else if (product[i].sellPrice <= product[i].buyPrice)
            {
                cout << "\nProduct selling price must be greater than product cost\n";
            }
        }   while ((product[i].sellPrice <= 0) || (product[i].sellPrice <= product[i].buyPrice));
        
        productCount++;
        
        do  //Query on adding next product
        {
            cout << "Producted added successfully." << endl
                 << "Do you want to add more product? (Y/N)";
            cin  >> next;
            if (toupper(next) != 'Y' && toupper(next) != 'N')
            {
                cout << "Invalid response.\n";
            }
        }   while (toupper(next) != 'Y' && toupper(next) != 'N');
        
    }   while (toupper(next) == 'Y'); //Stop adding next product
}

void Display()
{
    //Display the inventory (only if 1 or more items)
    cout << "\nCurrent inventory:"<<endl<<endl;
    cout << " Id\tName\t\tBrand\t\tQuantity\t Cost(RM)\t Selling Price(RM)"<<endl;
        for(int i = 0; i < productCount; i++)
        {
            cout<<" "<<product[i].id<<".\t"<<product[i].type<<"  \t"<<product[i].brand<<"\t\t   "<<product[i].qty<<"\t\t  "<<product[i].buyPrice<<"\t\t   "
            <<product[i].sellPrice<<endl;
        }
}
void Search()
{
    //Searches the inventory (search keyword case insensitive.)
    string searchQuery[4]; 
    bool found;
    cin.ignore();
    cout<<"Enter name of product you want to find: ";
    getline(cin,searchQuery[0]);
    cout<<"Enter the brand of product you want to find: ";
    getline(cin,searchQuery[2]);
    for(int i = 0; i < 2; i++)
        stringToLower(searchQuery[i * 2]); //0, 2
    for(int i = 0; i < productCount; i++)          
    {   
        searchQuery[1] = stringToLower(product[i].type);
        searchQuery[3] = stringToLower(product[i].brand);
        if (searchQuery[0] == searchQuery[1] && searchQuery[2] == searchQuery[3])       
        {   //Case insensitive comparison
            found = true;
            cout << "Product "  << product[i].type << " found, details as follows:"<<endl;
            cout << " Id\tName\t\tBrand\t\tQuantity\t Cost(RM)\t Selling Price(RM)"<<endl;
            cout << " "<<product[i].id<<".\t"<<product[i].type<<"  \t"<<product[i].brand<<"\t\t   "<<product[i].qty<<"\t\t  "<<product[i].buyPrice<<"\t\t   "
            <<product[i].sellPrice<<endl;
            break;
        }
    }
    if (!found) 
        cout << "Product not found in inventory system." << endl;
}

void Delete()
{
    int id;
    cout << "Enter the product ID to delete (Enter 0 to delete all, or -1 to cancel): ";
    cin  >> id;
    if (id == 0) //Clear all
    {
        for(int i = 0; i < inventoryLimit; i++)
        {
            product[i].type = "";
            product[i].brand = "";
            product[i].qty = 0;
            product[i].buyPrice = 0;
            product[i].sellPrice = 0;
        }
        cout << "All product deleted successfully." << endl;
    }
    else if (id > 0 && id <= inventoryLimit) //Clear the particular ID
    {
        id--;
        product[id].type = "";
        product[id].brand = "";
        product[id].qty = 0;
        product[id].buyPrice = 0;
        product[id].sellPrice = 0;
        cout << "Deleted successfully." << endl;
    }
    else if (id == -1) //Cancel (do nothing)
    {
    }
    else //Error input
    {
        cout<<"Invalid option."<<endl;
        Delete();
    }
}

void Update()
{
    int id;
    cout << "Enter the product ID to update (Enter 0 to delete all, or -1 to cancel): ";
    cin  >> id;
    id--;
    if (id > inventoryLimit || id < -1) //Invalid check
    {
        cout << "Invalid ID!" << endl;
        Update();
    }
    if (id == -1) {} //-1 to cancel
    else 
    {
        cin.ignore();
        cout<<"Enter new name: ";
        getline(cin,product[id].type);
        cout<<"Enter new brand: ";
        getline(cin,product[id].brand);
        cout<<"Enter new quantity: ";
        cin>>product[id].qty;
        cout<<"Enter new cost: ";
        cin>>product[id].buyPrice;
        cout<<"Enter new selling price: ";
        cin>>product[id].sellPrice;
    }
    cout<<"Updated successfully.\n";
}

void Checkout(){
    int id;
    int qty;
    cout << "Enter product id: ";
    cin  >> id;
    id--;
    cout << "How many product you want to checkout: ";
    cin  >> qty;
    if(id > productCount || id < 0)
    {
        cout << "Invalid Id!" << endl;
        Checkout();
    }
    else
    {
        if (qty > product[id].qty)
        {
            cout<<"Invalid quantity for checkout."<<endl<<endl;
        }
        else
        {
          product[id].qty = product[id].qty - qty;
          double profit;
          profit = qty * (product[id].sellPrice - product[id].buyPrice);
          cout << "\n\t\t\tProduct checkout successfully, Profit in RM: "<< profit;
        }
    }
}

int main()
{
    char input;
    //system("color 75");
    cout << "\n\t\t\t\tWelcome to Inventory System. ^U^ ";

    do
    {
        if (productCount > 0) {
            Display(); 
        }

        cout << "\n 1.Insert product \n 2.Search product"
             << "\n 3.Checkout \n 4.Update \n 5.Delete \n 6.Exit" << endl;
        cout << "\nChoose your option(1-7):";
        cin  >> input; 
        switch(input)
        {
            case '1':
                Insert();
                break;
            case '2':
                Search();
                break;
            case '3':
                Checkout();
                break;
            case '4':
                Update();
                break;
            case '5':
                Delete();
                break;
            case '6':
                system("cls");
                cout << "\n\t\t\tThank you for choosing us.\n\t\t\tEnjoy Your Products! ^U^\n";
                cout << "\n\t\tProgram Ended. Press Any Key To Exit Screen ^U^\n\n\n" << endl;
                return 0;
                break;
            default:
                cout << "Invalid option!" << endl << endl;
                break;
        }
    }   while(input >= '1' && input <= '5');
    return 0;
}



