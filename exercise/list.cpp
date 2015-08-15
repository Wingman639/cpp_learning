#include <iostream>

using namespace std;


class Item {
public:
    string value;

    string __str__()
    {
        return "\"" + value + "\"";
    }

    void print()
    {
        cout << value;
    }
};


class List {
protected:
    int max;
    int count;
    Item *_array;

public:
    List(int m) : max(m)
    {
        count = 0;
        _array = new Item[max];
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

    void add(Item &a_item)
    {
        if (count == max)
        {
            throw count;            //TODO: replace with enlarge()
        }
        Item new_item(a_item);      //copy item
        _array[count++] = new_item;
    }
};


void test_add(){
    List a_list(3);
    Item item_1;
    item_1.value = "item A";
    a_list.add(item_1);
    Item item_2;
    item_2.value = "item B";
    a_list.add(item_2);

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
    test_item();
    test_list();
    test_add();


}


int main()
{
    test();
    return 0;
}