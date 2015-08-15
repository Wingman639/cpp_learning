#include <iostream>

using namespace std;


class Item {
public:
    string value;

    Item(string s="") : value(s)
    {

    }

    ~Item()
    {
        cout << "delete: ";
        print();
        cout << endl;
    }

    string __str__()
    {
        return "\"" + value + "\"";
    }

    void print()
    {
        cout << __str__() << " " << this;
    }
};


class List {
protected:
    int max;
    int count;
    Item **_array;                      // Array store points

public:
    List(int m) : max(m)
    {
        count = 0;
        _array = new Item*[max];
    }

    ~List()
    {
        for (int i = 0; i < count; ++i)
        {
            delete _array[i];                               // Items shall be released one by one.
        }
        if (_array)
        {
            delete []_array;
            cout << "delete _array" << endl;
        }
    }

    int length()
    {
        return count;
    }

    string __str__()
    {
        string output = "";
        //output += ", _array : " + to_string( long(&_array) );
        output += "[";
        for (int i = 0; i < count; ++i)
        {
            if (i > 0)
            {
                output += ", ";
            }
            output += _array[i]->__str__();
        }
        output += "]";
        
        return output;
    }

    void print()
    {
        cout << __str__();
        string s_count = " (" + to_string(count) + "/" + to_string(max) + ")";
        cout << s_count;
    }

    void append(Item &a_item)
    {
        if (count == max)
        {
            throw count;            //TODO: replace with enlarge()
        }
        Item *p_new_item = new Item(a_item);      //copy item  Wrong code: Item new_item(a_item); new_item will be free at the end of this method.
        _array[count] = p_new_item;
        count++;
    }
};




class List_2 {
protected:
    int max;
    int count;
    Item *_array;                      // Array store Item

public:
    List_2(int m) : max(m)
    {
        count = 0;
        _array = new Item[max];
    }

    ~List_2()
    {
        if (_array)
        {
            delete []_array;                        // Release array will release all items inside. No need to release individually.
            cout << "delete _array" << endl;
        }
    }

    int length()
    {
        return count;
    }

    string __str__()
    {
        string output = "";
        //output += ", _array : " + to_string( long(&_array) );
        output += "[";
        for (int i = 0; i < count; ++i)
        {
            if (i > 0)
            {
                output += ", ";
            }
            output += _array[i].__str__();
        }
        output += "]";
        
        return output;
    }

    void print()
    {
        cout << __str__();
        string s_count = " (" + to_string(count) + "/" + to_string(max) + ")";
        cout << s_count;
    }

    void append(Item &a_item)
    {
        if (count == max)
        {
            throw count;            //TODO: replace with enlarge()
        }
        Item *p_new_item = new Item(a_item);      //copy item  Wrong code: Item new_item(a_item); new_item will be free at the end of this method.
        _array[count] = *p_new_item;              // Array store item, instead of point.
        count++;
    }
};



void test_list_2_append(){
    List_2 a_list(4);
    Item item_1("AAA");
    a_list.append(item_1);
    Item item_2("BBB");
    a_list.append(item_2);
    Item item_3("CCC");
    a_list.append(item_3);
    a_list.print();
    cout << endl;
}


void test_append(){
    List a_list(3);
    Item item_1;
    item_1.value = "AA";
    a_list.append(item_1);
    Item item_2;
    item_2.value = "BB";
    a_list.append(item_2);

    a_list.print();
    cout << endl;
}

void test_list(){
    List a_list(2);
    a_list.print();
    cout << endl;
}


void test_item(){
    Item a_item;
    a_item.value = "A item";
    a_item.print();
    cout << endl;
}

void test(){
    cout << "Test start:" << endl;
    //test_item();
    //test_list();
    test_append();
    cout << "-----------------------------------" << endl;
    test_list_2_append();


}


int main()
{
    test();
    return 0;
}