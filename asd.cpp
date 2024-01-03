#include <iostream>
#include <string>

using namespace std;

struct MenuItem {
    string name;
    double price;
    int stock;
};

struct SubCategory {
    char name[50];
    MenuItem items[10];
    int itemCount;
};

struct Category {
    char name[50];
    SubCategory subCategories[10];
    int subCategoryCount;
};

struct Node {
    Category data;
    Node* next;
};

Node* createNode(Category category) {
    Node* newNode = new Node;
    newNode->data = category;
    newNode->next = nullptr;
    return newNode;
}

void addItem(Node*& head, Category category) {
    Node* newNode = createNode(category);
    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int main()
{
    int choice;
    char backMenu;

    do {
        cout << "1. Admin" << endl;
        cout << "2. Pelanggan" << endl;
        cout << "Masukkan Pilihan Anda: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Admin";
            break;
    
        case 2:
            cout << "Pelanggan";
            break;
    
        default:
            cout << "Pilihan Anda Tidak Ada Didalam Menu.";
            break;
        }

        cout << "Ingin Kembali Ke Menu Utama? (Y, y/N): ";
        cin >> backMenu;

        cout << endl;

    } while (backMenu == 'Y' || backMenu == 'y');

    cout << "Terima Kasih dan Sampai berjumpa kembali ya :)";

    return 0;

}