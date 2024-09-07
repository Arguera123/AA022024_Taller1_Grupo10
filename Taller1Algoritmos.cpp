#include <iostream>

using namespace std;

struct Node{
    string name;
    int stock;
    Node *next;
};

Node *list = NULL;

void insert(int, string);
void showLessThanTeen();
void showNNodes(int);
void modify(string);
void deleteProducto(string);
void bubbleSort();
void menu();

int main() {

    menu();
    
    return 0;
}

void menu() {
    int c = 1;
    string producto;
    while (c != 0){
        cout << "===============================================" << endl;
        cout << "Seleccione una opción: " << endl;
        cout << "===============================================" << endl;
        cout << "1. Agregar un producto" << endl;
        cout << "2. Eliminar un producto" << endl;
        cout << "3. Modificar un producto" << endl;
        cout << "4. Ver productos con menos de 10 unidades" << endl;
        cout << "5. Ver n cantidad de productos con menor stock" << endl;
        cout << "6. Salir" << endl;
        cout << "Digite: ";
        cin >> c;

        switch(c){
            case 1: {
                string name;
                int stock;
                cout << "Digite un producto: ";
                cin >> name;
                cout << "Digite el stock: ";
                cin >> stock;
                insert(stock, name);
                break;
            }
            case 2: {
                cout << "Digite el producto que desea eliminar: ";
                cin >> producto;
                deleteProducto(producto);
                break;
            }
            case 3: {
                cout << "Digite el producto que desea modificar: ";
                cin >> producto;
                modify(producto);
                bubbleSort();
                break;
            }
            case 4: {
                showLessThanTeen();
                break;
            }
            case 5: {
                int n;
                cout << "Digite la cantidad de producto que desea ver: ";
                cin >> n;
                showNNodes(n);
                break;
            }
            case 6: {
                c = 0;
                break;
            }
            default: {
                cout << "Opción incorrecta" << endl;
            }
        }
    }
}

void insert(int stock, string name) {
    Node *new_node = new Node();
    new_node->stock = stock;
    new_node->name = name;

    Node *aux1 = list;
    Node *aux2;

    while((aux1 != NULL) && (aux1->stock < stock)) {
        aux2 = aux1;
        aux1 = aux1->next;
    }
    
    if(list == aux1) {
        list = new_node;  
    } else {
        aux2->next = new_node;
    }

    new_node->next = aux1;

    cout << "Elemento " << name << " insertado a lista correctamente." << endl;
}

void showLessThanTeen() {
    Node *current = new Node();
    current = list;

    while(current != NULL) {
        if(current->stock < 10) {
            cout << "Del producto " << current->name << " existen " << current->stock << " unidades." << endl;
        }
        current = current->next;
    }  
}

void showNNodes(int n) {
    Node *current = new Node();
    current = list;
    int j = 0;  

    while(current != NULL && j < n) {
        cout << "Del producto " << current->name << " existen " << current->stock << " unidades." << endl;
        current = current->next;
        j++;
    }
}

void modify(string product) {
    bool band = false;
    Node *current = new Node();
    current = list;

    while(current != NULL) {
        if(current->name == product) {
            int new_stock;
            cout << "Digite el nuevo stock del producto: ";
            cin >> new_stock;
            current->stock = new_stock;
            band = true;
            break;
        }
        current = current->next;
    }

    if(band == false) {
        cout << "Producto no encontrado." << endl;
        return;
    }
}

void deleteProducto(string producto) {
    if(list != NULL) {
        Node *aux_delete;
        Node *previous = NULL;

        aux_delete = list;

        while((aux_delete != NULL) && (aux_delete->name != producto)) {
            previous = aux_delete;
            aux_delete = aux_delete->next;
        }

        if(aux_delete == NULL) {
            cout << "El elemento no ha sido encontrado." << endl;
        } else if(previous == NULL) {
            list = list->next;
            delete aux_delete;
        } else {
            previous->next = aux_delete->next;
            delete aux_delete;
        }
    }
}

void bubbleSort() {
    if(!list || !list->next) {
        return;
    } 

    bool swapped;
    Node* current;
    Node* lastSorted = nullptr;

    do {
        swapped = false;
        current = list;
        
        while(current->next != lastSorted) {
            if(current->stock > current->next->stock) {
                string tempName = current->name;
                int tempStock = current->stock;

                current->name = current->next->name;
                current->stock = current->next->stock;

                current->next->name = tempName;
                current->next->stock = tempStock;

                swapped = true;
            }
            current = current->next;
        } 
        lastSorted = current;
    } while(swapped);
}
