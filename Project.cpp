#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <iomanip>
using namespace std;

class Product {
    public:
        int id; //ID that is human-friendly.
        string type; //Type of product.
        string brand; //Brand of product.
        int qty; //Quantity of product
        double buyPrice; //Cost of product
        double sellPrice; //Selling price of product.
    void displayEntry(int columnWidth[6]) {
        //Function to display all the details of product.
        cout.setf(ios::fixed | ios::showpoint);
        cout.precision(2);
        cout << setfill(' ') 
            <<  "| " << setw(columnWidth[0] - 1) << right << id << "."
            << " | " << setw(columnWidth[1]) <<  left << type
            << " | " << setw(columnWidth[2]) <<  left << brand
            << " | " << setw(columnWidth[3]) << right << qty
            << " | " << setw(columnWidth[4]) << right << buyPrice
            << " | " << setw(columnWidth[5]) << right << sellPrice << " |\n";
    }

    void editEntry(int id, string type, string brand, int qty, double buyPrice, double sellPrice) {
        //Function to edit the details of product.
        this->id = id;
        this->type = type;
        this->brand = brand;
        this->qty = qty;
        this->buyPrice = buyPrice;
        this->sellPrice = sellPrice;
    }    
};
//Function declarations
void Display(int start, int end); //Display from ID A to B (index)
void Insert(); //Insert product
void Search(); //Search inventory
void Edit();   //Edit product Details 
void Delete(); //Delete product details
void Checkout(); //Transaction, product reduction
void Load(); //Load from previous sessions
void Save(); //Save session for next session
//Operation function declaration
string stringToLower(string str);
bool isBetween(char lower, char upper, char input);
bool isInteger(string str);
bool isDouble(string str);
//Var declaration
static int inventoryLimit = 100;
int productCount = 0;
Product product[100];

//Operation functions
string stringToLower(string str) {
    //Lower all the characters for case insensitive comparison, created due to predefined method not able to convert strings.
    for (int i = 0; str[i]!='\0'; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
	}
    return str;
}
bool isBetween(char lower, char upper, char input) {
    //Self explainatory. Returns true if input char is between lower and upper.
    lower = toupper(lower);
    upper = toupper(upper);
    input = toupper(input);

    if (lower <= input && input <= upper)
        return true;
    else
        return false; 
}
bool isInteger(string str) { //Check whether the input is a int.
    return regex_match(str, regex("[0-9]+"));    
}
bool isDouble(string str) { //Check whether the input is a double.
    //I have no other idea other than RegEx, sorry. -Fang
    //[0-9] represents match from 0-9, + represents contains 1 or more (digits 0-9)
    //[.] represents the literal dot
    //()? - () represents capture group, which is captured by ?, 
    //which indicates 0 or 1 that specific capture group.
    //Overall, it represents that number has many digits, 
    //and may or may not have a decimal point.
    //(Negative values are not counted).
    return regex_match(str, regex("[0-9]+([.][0-9]+)?"));
}
//End of Operation functions

int main()
{
    Load(); //Read file.
    string input;
    char choice;
    do
    {   //Main menu section
        cout << "\tWelcome to Inventory System. ^U^\n";
        if (productCount > 0) {
            //If at least 1 product is added, display the cart.
            cout << "\nCurrent inventory:\n";   
            Display(0, productCount);
        }
        cout << "1.Insert product\n" 
             << "2.Search product\n"
             << "3.Edit\n" 
             << "4.Delete\n"
             << "5.Checkout\n" 
             << "6.Exit\n\n";
        do 
        {
            cout << "Please select your option (1-6): ";
            getline(cin, input); //Using getline instead of cin to combat errors regarding spaces.
            choice = input[0]; // Only receive one letter to prevent error.
            switch (choice)
            {
                case '1': //Insert product
                    Insert();
                    break;
                case '2': //Search product
                    Search();
                    break;
                case '3': //Edit
                    Edit();
                    break;
                case '4': //Delete
                    Delete();
                    break;
                case '5': //Checkout
                    Checkout();
                    break;
                case '6':
                    system("cls||clear"); //Clears terminal, where 'cls' - Windows, 'clear' - Mac devices.
                    cout << "\n\t\t\tThank you for choosing us.\n\t\t\tEnjoy Your Products! ^U^\n";\
                    return 0;
                    break;
                default:
                    cout << "Invalid option!" << endl << endl;
                    break;
            }
        }   while(!isBetween('1', '6', choice)); //Repeat for error input.
    }   while(isBetween('1', '5', choice)); //Repeat after completing the section.
    return 0;
}

void Display(int start, int end)
{    
    int longest[6] = {0, 0, 0, 0, 0, 0};
    for (int i = start; i < end; i++)
    {   //Get the longest length to set column width
        if (to_string(product[i].id).length() > longest[0]) 
            longest[0] = to_string(product[i].id).length() + 1; //To include '.'
        if (product[i].type.length() > longest[1]) 
            longest[1] = product[i].type.length();
        if (product[i].brand.length() > longest[2]) 
            longest[2] = product[i].brand.length();
        if (to_string(product[i].qty).length() > longest[3]) 
            longest[3] = to_string(product[i].qty).length();
        if (to_string(product[i].buyPrice).length() > longest[4]) 
            longest[4] = to_string((int) product[i].buyPrice).length() + 3;
        if (to_string(product[i].sellPrice).length() > longest[5]) 
            longest[5] = to_string((int) product[i].sellPrice).length() + 3;
    };
    //Title length: 3, 7, 5, 3, 9, 15; and compare them with the longest entry, whichever is longest.
    int columnWidth[6] = {
        max( 3, longest[0]),
        max( 7, longest[1]),
        max( 5, longest[2]),
        max( 3, longest[3]),
        max( 9, longest[4]),
        max(15, longest[5]),
    };

    /* Example format      
    +-----+-------------+--------------+-----+-----------+-----------------+
    | Num | Product     | Brand        | Qty | Cost (RM) | Sell Price (RM) |
    +-----+-------------+--------------+-----+-----------+-----------------+
    |  1. | Racquet     | Li Ning      |   1 |     xx.xx |           xx.xx |
    |  2. | Shuttlecock | Yonex        |   1 |     xx.xx |           xx.xx |
    |  3. | Grip tape   | Li Ning      |   1 |     xx.xx |           xx.xx |
    |  4. | Others      | Yonex        |   1 |     xx.xx |           xx.xx |
    +-----+-------------+--------------+-----+-----------+-----------------+
    Gets the highest length from longest data, then create a table with X wide 
    (aligned left for string, or right for numbers)
    */
    for (int i = 0; i < 6; i++)
        cout << "+" << setfill('-') << setw(2 + columnWidth[i]) << "-";
    cout << "+\n";
    cout << setfill(' ') 
         <<  "| " << setw(columnWidth[0]) << left << "Num"
         << " | " << setw(columnWidth[1]) << left << "Name"
         << " | " << setw(columnWidth[2]) << left << "Brand"
         << " | " << setw(columnWidth[3]) << left << "Qty"
         << " | " << setw(columnWidth[4]) << left << "Cost (RM)"
         << " | " << setw(columnWidth[5]) << left << "Sell Price (RM)" << " |\n";
    for (int i = 0; i < 6; i++)
        cout << "+" << setfill('-') << setw(2 + columnWidth[i]) << "-";
    cout << "+\n";

    //Display from entry (int start) to (int end).
    for (int i = start; i < end; i++)
    {
        product[i].displayEntry(columnWidth);
    }

    for (int i = 0; i < 6; i++)
        cout << "+" << setfill('-') << setw(2 + columnWidth[i]) << "-";
    cout << "+\n\n";
}

void Insert()
{
    char choice;
    int i;
    string input;
    do  //Section to add item, with loop responsible for each details of that item.
    {
        //Display all the products and brands.
        system("cls||clear"); //Clear terminal.
        cout // Brands: Yonex, Li Ning, Fleet, Apacs, Victor
        <<  "     Product List      \n"
        <<  "+------+--------------+\n"
        <<  "| List | Product      |\n"
        <<  "+------+--------------+\n"
        <<  "|  a.  | Racquet      |\n"
        <<  "|  b.  | Shuttlecock  |\n"
        <<  "|  c.  | Grip tape    |\n"
        <<  "|  d.  | Others       |\n"
        <<  "+------+--------------+\n";
        i = productCount;
        product[i].id = i + 1;
        do  //Type of product
        {
            cout << "Enter a choice from the menu(a-d) for type of product " << product[i].id << ": ";
            getline(cin, input); 
            choice = toupper(input[0]); //Taking only first letter, to prevent errors.
            switch (choice) {
                case 'A':
                    product[i].type = "Racquet";
                    break;
                case 'B':
                    product[i].type = "Shuttlecock";
                    break;
                case 'C':
                    product[i].type = "Grip tape";
                    break;
                case 'D':
                    cout << "Enter the type of product " << product[i].id << ": ";
                    getline(cin, input); //Using getline instead of cin to combat errors regarding spaces.
                    product[i].type = input;
                    break;
                default:
                    cout << "Please enter an alphabet within a-d\n";
                    break;
            }                    
        }   while (!isBetween('A', 'D', choice)); /*If error, try again
        
        do(n't) //Brand of product, doesnt require do-while loop and curly braces but OCD hits. */
        { 
            cout << "Enter the brand of product " << product[i].id << " (e.g. Yonex, Li Ning): ";
            getline(cin, input); //Using getline instead of cin to combat errors regarding spaces.
            product[i].brand = input;
        }

        do  //Qty of product
        {
            cout << product[i].type << " - " << product[i].brand << "\n";
            cout << "Enter quantity of product: ";
            getline(cin, input);
            if (!isInteger(input))
                //Nmber checks are needed (across the application) in order to counter accidental letter inputs.
                cout << "Invalid input.\n";
            else 
                product[i].qty = stoi(input);
                //string::stoi(string str) converts string into int.
        }   while (!isInteger(input)); //If error, try again

        do  //Cost of product
        {
            cout.setf(ios::fixed | ios::showpoint);
            cout.precision(2);
            cout << "Enter cost of product: ";
            getline(cin, input);
            if (!isDouble(input))
                cout << "\nInvalid product cost.\n";
            else 
                product[i].buyPrice = stod(input);
                //string::stod(string str) converts string into double.
        }   while (!isDouble(input));

        do  //Selling price of product
        {
            cout << "Enter selling price of product: ";
            getline(cin, input);
            if (!isDouble(input))
            {
                cout << "\nInvalid product selling price.\n";
            }
            else 
            {
                product[i].sellPrice = stod(input);
                if (product[i].sellPrice <= product[i].buyPrice)
                    cout << "\nProduct selling price must be greater than product cost.\n";
            }
        }   while ((!isDouble(input)) || (product[i].sellPrice <= product[i].buyPrice));
        productCount++;
        cout << "Product added successfully.\n";
        
        do  //Query on adding next product
        {   
            cout << "Do you want to add more product? (Y/N)";
            getline(cin, input);
            choice = input[0];
            if (toupper(choice) != 'Y' && toupper(choice) != 'N')
            {
                cout << "Invalid response.\n";
            }
        }   while (toupper(choice) != 'Y' && toupper(choice) != 'N');
        system("cls||clear");
        Save();
    }   while (toupper(choice) == 'Y'); //Stop adding next product
}
void Search() //Searches the inventory (search keyword case insensitive.)
{   
    if (productCount == 0) {
        system("cls||clear");
        cout << "You can't search for product when there is no product.\n\n";
        return; 
    }
    bool found = false;  
    string searchQuery[4];  // 0: search type, 1: inv type, 2: search brand, 3: inv brand
    cout << "Enter name of product you want to find: ";
    getline(cin,searchQuery[0]);
    cout << "Enter the brand of product you want to find: ";
    getline(cin,searchQuery[2]);
    for(int i = 0; i < 2; i++)
        searchQuery[i * 2] = stringToLower(searchQuery[i * 2]); //0, 2
    for(int i = 0; i < productCount; i++)
    {
        searchQuery[1] = stringToLower(product[i].type);
        searchQuery[3] = stringToLower(product[i].brand);
        if (searchQuery[0] == searchQuery[1] && searchQuery[2] == searchQuery[3])
        {   //Case insensitive comparison
            found = true;
            cout << "Product " << product[i].type << " found, details as follows:" << endl;
            Display(i, i+1);
            cout << "Press enter to continue.";
            getline(cin, searchQuery[0]); //dummy var input
            system("cls||clear");
            return;
        }
    }
    if (!found)
        system("cls||clear");
        cout << "Product not found in inventory system.\n\n";
}
void Edit()
{
    string input;
    int id;
    if (productCount == 0) {
        system("cls||clear");
        cout << "You can't edit product when there is no product.\n\n";
        return; 
    }
    cout << "Enter the product ID to edit (Enter 0 to cancel): ";
    getline(cin, input);
    if (!isInteger(input) || (stoi(input) > productCount)) {
        //If input is not a number, or is a number but bigger than productCount
        cout << "Invalid option." << endl;
        Edit();
    }
    else if (stoi(input) == 0) {system("cls||clear");} //do nothing 
    else
    {
        id = stoi(input) - 1;
        cout << "Enter new product type: ";
        getline(cin,product[id].type);
        cout << "Enter new product brand: ";
        getline(cin,product[id].brand);
        //For int and double, checks (do while loops) are needed before inputting, to prevent errors.
        do {
            cout << "Enter new quantity: ";
            getline(cin, input);
            if (!isInteger(input))
                cout << "Invalid input.\n";
            else product[id].qty = stoi(input);
        }  while (!isInteger(input));
        do {
            cout << "Enter new cost: ";
            getline(cin, input);
            if (!isDouble(input))
                cout << "Invalid input.\n";
            else product[id].buyPrice = stod(input);
        }  while (!isDouble(input));
        do {
            cout << "Enter new selling price: ";
            getline(cin, input);
            if (!isDouble(input) || stod(input) <= product[id].buyPrice)
            //Additional condition: must be higher than buying price (cost).
                cout << "Invalid input.\n";
            else product[id].sellPrice = stod(input);
        }  while (!isDouble(input));
        system("cls||clear");
        cout << "Updated successfully.\n\n";
        Save();
    }
}
void Delete()
{   
    string input;
    int id;
    if (productCount == 0) {
        system("cls||clear");
        cout << "You can't delete product when there is no product.\n\n";
        return; 
    }
    cout << "Enter the product ID to delete (Enter 0 to delete all, or -1 to cancel): ";
    getline(cin, input);
    if (input == "-1") { system("cls||clear"); } //do nothing
    else if (!isInteger(input) || (stoi(input) > productCount)) {
        cout << "Invalid option." << endl;
        Delete();
    }
    else
    {
        id = stoi(input); 
        if (id == 0) //Clear all
        {
            for(int i = 0; i < productCount; i++)
            {
                product[i].editEntry(0, "", "", 0, 0, 0);
            }
            productCount = 0;
            system("cls||clear");
            cout << "All product deleted successfully.\n\n";
        }
        else //Clear a particular ID
        {
            //Move up the empty row to replace the row that was deleted.
            for (int i = id - 1; i < productCount; i++) {
                product[i].editEntry(product[i].id, product[i+1].type, product[i+1].brand, product[i+1].qty, product[i+1].buyPrice, product[i+1].sellPrice);
            }
            system("cls||clear");
            cout << "Deleted successfully.\n\n";
            productCount--;
        }
    }
    Save();
}
void Checkout(){
    string input;
    int id, qty;
    double profit;
    if (productCount == 0) {
        system("cls||clear");
        cout << "You can't checkout when there is no product.\n\n";
        return; 
    }
    cout << "Enter the product ID (Enter 0 to cancel): ";
    getline(cin, input);
    if (!isInteger(input) || (stoi(input) > productCount)) {
        //If input is not a number, or is a number but bigger than productCount
        cout << "Invalid input."<< endl;
        Checkout();
    }
    else if (stoi(input) == 0) {system("cls||clear");}
    else
    {   
        id = stoi(input) - 1;
        cout << "How many product you want to checkout: ";
        getline(cin, input);
        if (!isInteger(input) || (stoi(input) > product[id].qty))
            cout << "Invalid quantity for checkout, product unchanged.\n\n";
        else {
            qty = stoi(input);
            product[id].qty = product[id].qty - qty;
            profit = qty * (product[id].sellPrice - product[id].buyPrice);
            cout << "\nProduct checkout successfully, Profit: RM "<< profit << "\n";
            cout << "Press enter to continue.";
            getline(cin, input); //dummy var input
            system("cls||clear");
        }
    }    
    Save();
}
void Save() {
    //Save by overwritting the file.
    //Saves happen when: 
    //Each product in Insert-265, Edit-351, Delete-394, Checkout-430
    ofstream saveData("savedata.txt");
    for (int i = 0; i < inventoryLimit; i++) {
        saveData << product[i].id << endl;
        saveData << product[i].type << endl;
        saveData << product[i].brand<< endl;
        saveData << product[i].qty << endl;
        saveData << product[i].buyPrice << endl;
        saveData << product[i].sellPrice << endl;
    }
    saveData.close();
}
void Load() {
    ifstream saveData("savedata.txt");
    string temp[inventoryLimit][6]; //String buffer, to be validated and converted 
    bool error = false; 

    for (int i = 0; i < inventoryLimit; i++) {
        for (int j = 0; j < 6; j++) {
            getline(saveData, temp[i][j]);
        }
        if ((!isInteger(temp[i][0])) || (!isInteger(temp[i][3])) || (!isDouble(temp[i][4])) || (!isDouble(temp[i][5])))  
        //Save data verification, Checks if data type is correct (id and qty is int, prices are double).
            error = true;
    }
    saveData.close();
    if (saveData.fail()) {
        //Saved data does not exist.
        cout << "\nSave file not detected. Input data to save.\n\n";
        return;
    }
    else if (error) {
        //Invalid data detected in the savefile.
        cout << "\nError reading saved file, due to invalid data.\n\n";
        return;
    }
    for (int i = 0; i < inventoryLimit; i++) {
        //Stores the buffer data into program.
        if (stoi(temp[i][0]) != 0) productCount++;
        product[i].id = stoi(temp[i][0]);
        product[i].type = temp[i][1];
        product[i].brand = temp[i][2];
        product[i].qty = stoi(temp[i][3]);
        product[i].buyPrice = stod(temp[i][4]);
        product[i].sellPrice = stod(temp[i][5]);
    }
}