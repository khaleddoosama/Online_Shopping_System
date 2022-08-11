//S31-32
//khaled osama abdallah  20200166
//abdallah mamdouh fathy 20200308
#include <bits\stdc++.h>
using namespace std;
class item
{
private:
    static int ID;
    int quantity,id;
    float price;
    string name;
public:
    item() //default Constructors
    {
        name = "empty item", quantity = 0, price = 0;
        id = 0;
    }
    item( string n, int q, float p) //parameterized Constructors    
    {
        name = n, quantity = q, price = p;
        id = ++ID;
    }
    item(const item &i) //copy Constructors
    {
        name = i.name;
        quantity = i.quantity;
        price = i.price;
        id=i.id;
    }
    void setItems(string n, int q, float p) //setter function
    {   
        name = n, quantity = q, price = p;
    }
    void setName(string n) 
    {
        name = n;
    }
    void setQuantity( int q) 
    {
         quantity = q;
    }
    void setPrice( float p) 
    {
        price = p;
    }
    int getID()
    {
        return ID;
    }
    int getid()
    {
        return id;
    }

    string getName()
    {
        return name;
    }
    int getQuantity()
    {
        return quantity;
    } 
    float getPrice()
    {
        return price;   
    }
    item operator +=(item i)
    {
        quantity += i.quantity;
        ID--;
        return *this;
    }
    item operator -=(int i)
    {
        quantity -= i;
        return *this;
    }
    int operator==(item i)
    {
        return (name ==i.name);
    }
    friend istream& operator >> (istream& input, item& i)
    {
        input >> i.name >> i.quantity >> i.price;
        i.id = ++ID;
        return input;
    }
    friend ostream& operator<<(ostream& output, item& i)
    {

        output << "Name = " << i.name << "\tID = " << i.id << "\tQuantity = " << i.quantity << "\tPrice = " << i.price << endl;
        return output;
    }
};
class seller
{
private:
    string Name, email;
    int count = 0;
    int maxItems;
    item* items = new item[1];
public:
    seller(string n, string e, item it[], int m)
    {
        Name = n;
        email = e;
        maxItems = m;
        items = new item[maxItems];
        for (int i = 0; i < maxItems; i++)
        {
            items[i] = it[i];
        }
    }
    friend ostream& operator <<(ostream& output, seller& t)
    {
        output << "name = " << t.Name << "\nemail = " << t.email << "\nmaxitems = " << t.maxItems << endl;
        
        return output;
    }
    bool addItem(item t)
    {
        for (size_t i = 0; i < maxItems; i++)
        {
            if (items[i].operator==(t))
            {
                items[i].operator+=(t);
                
                return true;
            }
            else if (!items[i].operator==(t) && count< maxItems)
            {
                items[count] = t;
                count++;
                cout << "Add success" << endl;
                return true;
            }
        }
        cout << "Can't add more items " << endl;
        return false;
    }
    bool sellItem(string n, int q)
    {
        item sell;
        sell.setName(n);
        sell.setQuantity(q);
        for (size_t i = 0; i < maxItems; i++)
        {
            if (items[i].operator==(sell))
            {
                int quantity = items[i].getQuantity();
                if (quantity >= q)
                {
                    items[i].operator-=(q);
                    cout << "sell success"<<endl;
                    return true;
                }
                else
                {
                    cout << "There is only{" << quantity << "}left for this item" << endl;
                }
                return true;
            }
        }
        cout << "not exist " << endl;
        return false;
    }
    void print()
    {
        for (size_t i = 0; i < maxItems; i++)
        {
            cout << items[i];
        }
    }
    item findItem(int id)
    {
        for (size_t i = 0; i < maxItems; i++)
        {
            if (items[i].getid() == id)
            {
                cout << items[i];
                return items[i];
            }
        }
        cout << "not exist" << endl;
    }
    ~seller()
    {
        delete[] items;
    }

};
int item::ID = 0;
int main()
{
    string nameItem, nameSeller,emailSeller,n;
    int Quantity, maxNumberOfItems, options,q,id;
    float price;
    item i[1001],i1 ;
    cout << "Please enter your name : ";
    getline(cin, nameSeller);
    cout << "your email : ";
    getline(cin, emailSeller);
    cout << "your store capacity : ";
    cin >> maxNumberOfItems;
    cout << "-----------------------------------------------------"<<endl;
    cout << "Please choose from which have the following options : ";
    cout << "\n1. Print My Info.\n" << "2. Add An Item.\n" << "3. Sell An Item.\n" << "4. Print Items.\n" << "5. Find an Item by ID\n" << "6. Exit\n";
    cin >> options;
    seller s1(nameSeller, emailSeller, i, maxNumberOfItems);
    while (options != 6)
    {
        switch (options)
        {
        case 1:
            cout << s1;
            break;
        case 2:
            cout << "Enter your item (item name,item quantity and item price) : ";
            cin >> i1;
            s1.addItem(i1);
            break;
        case 3:
            cout << "\nEnter item name and item quantity : ";
            cin >> n >> q;
            s1.sellItem(n, q);
            break;
        case 4:
            s1.print();
            break;
        case 5:
            cout << "\nEnter Id : ";
            cin >> id;
            s1.findItem(id);
            break;
        case 6:
            break;
        default:
            cout << "wrong choise,please try again,"<<endl;
            break;
        }
        cout << "other options? ";
        cin >> options;
    }
    return 0;
}
