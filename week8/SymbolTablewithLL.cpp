#include <iostream>
#include <cstring>
using namespace std;

struct Symbol{
    char name[50];
    char type[20];
    Symbol* next;
};

class SymbolTable{
private:
    Symbol* head;
public:
    SymbolTable() {
        head = NULL;
    }

    void insert(const char* name, const char* type){
        if(lookup(name) != NULL) return;
        Symbol* p = new Symbol;
        strcpy(p->name, name);
        strcpy(p->type, type);
        p->next = head;
        head = p;
    }

    Symbol* lookup(const char* name){
        Symbol* p = head;
        while(p != NULL){
            if(strcmp(p->name, name) == 0) return p;
            p = p->next;
        }
        return NULL;
    }

    void remove(const char* name){
        Symbol* p = head;
        Symbol* prev = NULL;
        while(p != NULL){
            if(strcmp(p->name, name) == 0){
                if(prev == NULL) head = p->next;
                else prev->next = p->next;
                delete p;
                return;
            }
            prev = p;
            p = p->next;
        }
    }

    void display(){
        Symbol* p = head;
        cout << "\nName\t\tType\n";
        while(p != NULL){
            cout << p->name << "\t\t" << p->type << endl;
            p = p->next;
        }
    }

    ~SymbolTable(){
        Symbol* p;
        while(head != NULL){
            p = head;
            head = head->next;
            delete p;
        }
    }
};


int main() {
    SymbolTable st;
    int choice;
    char name[50], type[20];

    do {
        cout << "\n===== SYMBOL TABLE LINKED LIST =====\n";
        cout << "1. Insert\n";
        cout << "2. Lookup\n";
        cout << "3. Remove\n";
        cout << "4. Display\n";
        cout << "0. Exit\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Nhap name: ";
                cin >> name;
                cout << "Nhap type: ";
                cin >> type;
                st.insert(name, type);
                cout << "Da thuc hien Insert!\n";
                break;

            case 2:
                cout << "Nhap name can tim: ";
                cin >> name;

                if(st.lookup(name) != NULL)
                    cout << "Tim thay Symbol!\n";
                else
                    cout << "Khong tim thay Symbol!\n";
                break;

            case 3:
                cout << "Nhap name can xoa: ";
                cin >> name;

                if(st.lookup(name) != NULL) {
                    st.remove(name);
                    cout << "Xoa thanh cong!\n";
                }
                else {
                    cout << "Khong tim thay Symbol!\n";
                }
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

    } while(choice != 0);

    return 0;
}
