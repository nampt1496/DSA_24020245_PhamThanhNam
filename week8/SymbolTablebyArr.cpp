#include <iostream>
#include <cstring>
using namespace std;

struct Symbol {
    char name[50];
    char type[20];
};
class SymbolTable{
private:
    Symbol table[100];
    int count;
public:
    SymbolTable(){
        count = 0;
    }

    void insert(const char* name, const char* type){
        if (lookup(name) != -1) return;
        if (count == 100) return;
        strcpy(table[count].name, name);
        strcpy(table[count].type, type);
        count++;
    }

    int lookup(const char* name){
        for(int i = 0; i < count; i++){
            if(strcmp(table[i].name, name) == 0) return i;
        }
        return -1;
    }

    void remove(const char* name){
        int pos = lookup(name);
        if(pos == -1) return;
        for (int i = pos; i < count - 1; i++) table[i] = table[i + 1];
        count--;
    }

    void display(){
        cout << "\nName\t\tType\n";
        for(int i = 0; i < count; i++){
            cout << table[i].name << "\t\t" << table[i].type << endl;
        }
    }
};
int main() {
    SymbolTable st;
    int choice;
    char name[50], type[20];

    do {
        cout << "\n===== SYMBOL TABLE =====\n";
        cout << "1. Insert\n";
        cout << "2. Lookup\n";
        cout << "3. Remove\n";
        cout << "4. Display\n";
        cout << "0. Exit\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap name: ";
                cin >> name;
                cout << "Nhap type: ";
                cin >> type;
                st.insert(name, type);
                break;

            case 2:
                cout << "Nhap name can tim: ";
                cin >> name;

                if (st.lookup(name) != -1)
                    cout << "Tim thay Symbol!\n";
                else
                    cout << "Khong tim thay Symbol!\n";
                break;

            case 3:
                cout << "Nhap name can xoa: ";
                cin >> name;
                st.remove(name);
                cout << "Da thuc hien thao tac xoa!\n";
                break;

            case 4:
                st.display();
                break;

            case 0:
                cout << "Ket thuc chuong trinh!\n";
                break;

            default:
                cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}
