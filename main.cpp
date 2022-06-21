#include "Declarations.h"

int main() {

    List<int> list;
    int current_data;
    int current_item_number = 1;
    cout<<endl;
    cout<<"---Please,fill the list "<<endl<<endl;
    while (true) {
            cout<<"#"<<current_item_number<<"_item  data: ";
            cin>>current_data;
            if(current_data == 0)break;
            list.push_back(current_data);
            ++current_item_number;

    }
    list.print(list);
    cout<<endl;
    list.pop_front();
    cout<<endl;
    list.print(list);
    list.push_front(67);
    cout<<endl;
    list.print(list);
    cout<<endl;
    list.insert(27,3);
    cout<<endl;
    list.print(list);
    cout<<endl;
    list.remove_at(2);
    cout<<endl;
    list.print(list);
    cout<<endl;
    list.pop_back();
    cout<<endl;
    list.print(list);
    cout<<endl<<endl<<endl;
    cout<<"---Your List Size: "; cout<<list.size()<<endl;

    return 0;
}


