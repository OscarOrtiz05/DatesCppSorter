#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


class Item {
    private:
        int id,price;
        string name;

    public: 
        Item(){
            id = -1;
            name = "Small Shield Potion";
            price = 25;
        };
        Item(int i,int p, string n){
            id = i;
            name = n;
            price = p;
        };
        string getName(){
            return name;
        };
        int getPrice(){
            return price;
        };
        int getId(){
            return id;
        }

        //overload operators
        bool operator==(const Item& other) const {
            return price == other.price;
        }
        bool operator<(const Item& other) const {
            return price < other.price;
        }
        bool operator>(const Item& other) const {
            return price > other.price;
        }
        bool operator!=(const Item& other) const {
            return price != other.price;
        }
        bool operator<=(const Item& other) const {
            return price <= other.price;
        }
        bool operator>=(const Item& other) const {
            return price >= other.price;
        }
};


// makes idx a random permutation of 0..n-1 (in-place)
void makeRandomPermutation(int* idx, int n){
    // seed once
    static bool seeded = false;
    if (!seeded) { srand((unsigned)time(nullptr)); seeded = true; }

    // fill 0..n-1
    for (int i = 0; i < n; ++i) idx[i] = i;

    // fisher–yates shuffle
    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1); 
        int tmp = idx[i]; 
        idx[i] = idx[j];
        idx[j] = tmp;
    }
}

//function to print each element of an array, this specifically 
void printArray(int *A, int n){
    for (int i = 0; i < n; i++){
        cout << A[i] << ((i < n-1) ? ", " : "");
    }
    cout << endl;
}

//print the items and their info
void printArrayItem(Item *A, int n,int *idx){
    for (int i = 0; i < n; i++){
        cout << A[idx[i]].getName() + ": " + to_string(A[idx[i]].getPrice()) << endl;
    }
}

//prints only the price of the objects, only technically used for debugging
void printArrayItemPrice(Item *A, int n,int *idx){
    for (int i = 0; i < n; i++){
        cout << to_string(A[idx[i]].getPrice()) << ((i < n - 1) ? ", " :  "");
    }
    cout << endl << endl;
}

//selection sort for a numbers array
void selectionSort(int *A, int n, bool asc = true){
    int indexMin, aux;
    for (int i = 0; i < n-1; i++){
        indexMin = i;
        for (int j = i+1; j < n; j++){
            if (asc ? (A[j] < A[indexMin]): (A[j] > A[indexMin])){
                indexMin = j;
            }
        }
        aux = A[indexMin];
        A[indexMin] = A[i];
        A[i] = aux;
        printArray(A,n);
    }
}

//selection sort ordering the prices of the Item objets
void selectionSortItems(Item *A, int n, int *idx, bool asc = true){
    int indexMin, aux;
    for (int i = 0; i < n-1; i++){
        indexMin = i;
        for (int j = i+1; j < n; j++){
            if (asc ? (A[idx[j]] < A[idx[indexMin]]) : (A[idx[j]] > A[idx[indexMin]])){
                indexMin = j;
                printArrayItemPrice(A, n, idx);
            }
        }
        aux = idx[indexMin];
        idx[indexMin] = idx[i];
        idx[i] = aux;
    }
}

//bubble sort for the prices of Item objects
void bubbleSortItems(Item *A, int n, int *idx, bool asc = true){
    int aux;
    bool change;
    for (int i = 0; i < n-1; i++){
        change = false;
        for (int j = 0; j < n - i - 1; j++){
            if (asc ? (A[idx[j]] > A[idx[j+1]]) : ((A[idx[j]] < A[idx[j+1]]))) {
                aux = idx[j+1];
                idx[j+1] = idx[j];
                idx[j] = aux;
                change = true;
                printArrayItemPrice(A, n, idx);
            }
        }
        if (change == false){
            break;
        }
    }
}

//swap sort for the prices of Item objects
void swapSortItems(Item *A, int n, int *idx, bool asc = true){
    int aux;
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if (asc ? (A[idx[i]] > A[idx[j]]) : (A[idx[i]] < A[idx[j]])){
                aux = idx[i];
                idx[i] = idx[j];
                idx[j] = aux;
                printArrayItemPrice(A, n, idx);
            }
        }
    }
}

//insertion sort for the prices of Item objects
void insertionSortItems(Item *A, int n, int *idx, bool asc = true){
    int c, j;
    for (int i = 0; i < n; i++){
        c = idx[i];
        j = i - 1;
        while (j >= 0 && (asc ? (A[idx[j]] > A[c]) : (A[idx[j]] < A[c]))){
            idx[j + 1] = idx[j];
            j--;
            printArrayItemPrice(A, n, idx);
        }
        idx[j + 1] = c;
    }
}

//merge function for the Item objects
void merge(int *A, int l, int m, int r){
    int s1, s2;
    s1 = m - l + 1;
    s2 = r - m;

    int L[s1], R[s2];

    for (int i = 0; i < s1; i++){
        L[i] = A[l+i];
    }
    for (int j = 0; j < s2; j++){
        R[j] = A[m + 1 +j];
    }
    int i = 0, j = 0, k = l;
    while(i < s1 && j < s2){
        if (L[i] <= R[j]){
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }

        k++;
    }
    while (i < s1){
        A[k] = L[i];
        i++;
        k++;
    }
    while(j < s2){
        A[k] = R[j];
        j++;
        k++;
    }
}

//merge sort for the Item prices
void mergeSort(int *A, int l, int r){
    int m;
    if (l < r){
        m = l + (r - l)/2;
        mergeSort(A,l,m);
        mergeSort(A,m + 1,r);
        merge(A,l,m,r);

    }
}

//merge function for the Item prices
void mergeItems(Item *A, int *idx, int l, int m, int r, bool asc = true){
    int s1, s2;
    s1 = m - l + 1;
    s2 = r - m;

    int L[s1], R[s2];

    for (int i = 0; i < s1; i++){
        L[i] = idx[l+i];
    }
    for (int j = 0; j < s2; j++){
        R[j] = idx[m + 1 +j];
    }
    int i = 0, j = 0, k = l;
    while(i < s1 && j < s2){
        if (asc ? (A[L[i]] <= A[R[j]]) : (A[L[i]] >= A[R[j]])){
            idx[k] = L[i];
            i++;
        } else {
            idx[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < s1){
        idx[k] = L[i];
        i++;
        k++;
    }
    while(j < s2){
        idx[k] = R[j];
        j++;
        k++;
    }
}

//merge sort for the Item prices
void mergeSortItems(Item *I, int *idx, int l, int r, bool asc = true){
    int m;
    if (l < r){
        m = l + (r - l)/2;
        mergeSortItems(I,idx,l,m,asc);
        mergeSortItems(I,idx,m + 1,r,asc);
        mergeItems(I,idx,l,m,r,asc);

    }
}

//partition function for the Item prices
int partitionItems(Item *I, int *A, int l, int r, bool asc = true){
    int pivot = A[r], i = l - 1, aux;
    for (int j = l; j < r; j++){
        if (asc ? (I[A[j]] < I[pivot]) : (I[A[j]] > I[pivot])){
            i++;
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }
    }
    aux = A[i + 1];
    A[i + 1] = A[r];
    A[r] = aux;
    return i + 1;
}

//quick sort for the Item prices
void quickSortItems(Item *I, int *A, int l, int r, bool asc = true){
    int pivot;
    if (l < r){
        pivot = partitionItems(I,A,l,r, asc);
        quickSortItems(I,A,l,pivot-1,asc);
        quickSortItems(I,A,pivot+1,r,asc);
    }
}


int main(){
    //defining the const number for the arrays
    int const n = 10;
    //the original order of the Item's name array
    string names[n] = {"Iron Sword", "Leather Armor", "Health Potion", "Mana Potion", "Steel Shield", "Bow & 20 Arrows", "Magic Ring", "Fire Spell Scroll", "Traveler's Boots", "Amulet of Protection"};
    //the original order of the Item's prices array
    int prices[n] = {50, 75, 10, 12, 60, 40, 120, 30, 25, 200};
    //initialization of the Item's array
    Item items[n];
    //initialization of the indices array
    int indices[n] = {6,5,4,3,8,7,9,1,2,0};
    //Initializing items array
    for (int i = 0; i < n; i++){
        items[i] = Item(i,prices[i],names[i]);
    }
    //uses of each sorting function

    cout << "Selection sorter:" << endl;
    printArrayItemPrice(items,n,indices);
    selectionSortItems(items,n,indices, false);
    printArrayItemPrice(items,n,indices);

    cout << endl << "Swap sorter:" << endl;
    makeRandomPermutation(indices,n);
    printArrayItemPrice(items,n,indices);
    swapSortItems(items,n,indices);
    printArrayItemPrice(items,n,indices);

    cout << endl << "Bubble sorter:" << endl;
    makeRandomPermutation(indices,n);
    printArrayItemPrice(items,n,indices);
    bubbleSortItems(items,n,indices, false);
    printArrayItemPrice(items,n,indices);

    cout << endl << "Insertion sorter:" << endl;
    makeRandomPermutation(indices,n);
    printArrayItemPrice(items,n,indices);
    insertionSortItems(items,n,indices);    
    printArrayItemPrice(items,n,indices);

    cout << endl << "Merge sorter:" << endl;
    makeRandomPermutation(indices,n);
    printArrayItemPrice(items,n,indices);
    mergeSortItems(items,indices,0,n-1, false);
    printArrayItemPrice(items,n,indices);

    cout << endl << "Quick sorter:" << endl;
    makeRandomPermutation(indices,n);
    printArrayItemPrice(items,n,indices);
    quickSortItems(items,indices,0,n-1);
    printArrayItemPrice(items,n,indices);
    return 0;
}