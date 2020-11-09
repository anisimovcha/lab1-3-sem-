#pragma once
#include "ArraySequence.h"
using namespace std;

//______________________BUBBLE_SORT___________________________________________________________________________

template <typename T>
Sequence <T>* Bubble_Sort(Sequence <T>* seq, int (*cmp)(T, T)) 
{
    for (int i = 0; i < seq->GetLength(); i++) 
    {
        for (int j = 0; j < seq->GetLength() - 1; j++) 
        {
            if (cmp(seq->Get(j), seq->Get(j + 1))) 
            {    
                T tmp = seq->Get(j);
                seq->Set(j, seq->Get(j + 1));
                seq->Set(j + 1, tmp);
            }
        }
    }
   // cout << "Sorted sequence: " << endl;
    return seq;
}


//______________________QUICK_SORT____________________________________________________________________________

template <typename T>
void Quick_Sort(Sequence <T>* seq, int (*cmp)(T, T), int left, int right)
{
    int i = left;
    int j = right;
    int middle = seq->Get((i + j)/2);
    int tmp;
    
        while (i <= j)
        {
            while (cmp(middle, seq->Get(i)))
                i++;
            while (cmp(seq->Get(j), middle))
                j--;
            
            if (i <= j)
            { 
                T tmp = seq->Get(i);
                seq->Set(i, seq->Get(j));
                seq->Set(j, tmp);
                i++;
                j--;
            }
        }
        if (i < right)
            Quick_Sort(seq, cmp, i, right);
        if (j > left)
            Quick_Sort(seq, cmp, left, j);
}

template <typename T>
Sequence <T>* Quick_Sort_seq(Sequence <T>* seq, int (*cmp)(T, T)) 
{
    if (seq->GetLength())
        Quick_Sort(seq, cmp, 0, seq->GetLength() - 1);
    return seq;
}


//______________________MERGE_SORT____________________________________________________________________________

template <typename T>
void Merge(Sequence<T>* seq, int (*cmp)(T, T), int left, int middle, int right) {
    int i, j, k;
    int left_leng = middle - left + 1;       // длины двух временных сиквенсов
    int right_leng = right - middle;


    ArraySequence<T> first_tmp(left_leng), second_tmp(right_leng);               // создадим временные сиквенсы
    Sequence<T>* left_seq = &first_tmp;
    Sequence<T>* right_seq = &second_tmp;

    for (i = 0; i < left_leng; i++) {                   // скопируем в них значения
        left_seq->Set(i, seq->Get(i + left));
    }
    for (j = 0; j < right_leng; j++) {
        right_seq->Set(j, seq->Get(middle + 1 + j));
    }

    i = 0; j = 0; k = left;          // начинаем слияние

    while (i < left_leng && j < right_leng) {             // пока мы не перепишем полностью одну из половин - работаем
        if (cmp(right_seq->Get(j), left_seq->Get(i))) {           // сверяем левую
            seq->Set(k, left_seq->Get(i));
            i++;
        }
        else {
            seq->Set(k, right_seq->Get(j));            // сверяем и переписываем(если надо) правую
            j++;
        }
        k++;
    }                                      // переписалась одна половина 

    while (i < left_leng) {              // остатки или от левого или от правого докидываем
        seq->Set(k, left_seq->Get(i));
        i++;
        k++;
    }

    while (j < right_leng) {
        seq->Set(k, right_seq->Get(j));
        j++;
        k++;
    }
}


template <typename T>
void Merge_Sort(Sequence<T>* seq, int (*cmp)(T, T), int left, int right) 
{
    if (left < right) 
    {                                                         // (l + r) / 2 == l + (r - l)/ 2 çàòî áåç ïðîáëåì
        int middle = left + (right - left) / 2;                                 

        Merge_Sort(seq, cmp, left, middle);                                     //1 отсорт
        Merge_Sort(seq, cmp, middle + 1, right);                                //рекурсивная сортировка полученных массивов 2 отсорт
        
        Merge(seq, cmp, left, middle, right);                                   
    }
}

template <typename T>
Sequence <T>* Merge_Sort_for_seq(Sequence <T>* seq, int (*cmp)(T, T)) 
{
    if (seq->GetLength())
        Merge_Sort(seq, cmp, 0, seq->GetLength() - 1);
    //cout << "Sorted sequence: " << endl;
    return seq;
}


//_____________________SORT_WITH_BINARY_TREE__________________________________________________________________

template <typename T>
class BST {
private:
    struct node {
        T data;
        node* left;
        node* right;
    };
    node* root;
    int count;
    // для деструктора
    void destroy_tree(node* branch) {
        if (branch != nullptr) {
            destroy_tree(branch->left);
            destroy_tree(branch->right);
            delete branch;
        }
    }

    int cmp_BST(T a, T b) {
        if (a > b)
            return 1;
        return 0;
    }

    void insert_help(node* branch, T item) {    // помощь для вставки 
        node* cur = branch;
        if (cmp_BST(cur->data, item)) {
            if (cur->left != nullptr) {
                insert_help(cur->left, item);
            }
            else {
                cur->left = new node;
                cur->left->data = item;
                cur->left->left = nullptr;
                cur->left->right = nullptr;
            }
        }
        else {
            if (cur->right != nullptr) {
                insert_help(cur->right, item);
            }
            else {
                cur->right = new node;
                cur->right->data = item;
                cur->right->left = nullptr;
                cur->right->right = nullptr;
            }
        }
    }

    // для пробега

    Sequence<T>* LKP_help(node* branch, Sequence<T>* seq) {
        node* tmp = branch; // KLP
        if (tmp) {
            LKP_help(branch->left, seq);
            seq->Set(this->count, branch->data);
            this->count++;
            LKP_help(branch->right, seq);;
        }
        return seq;
    }

public:
    BST() {
        this->root = nullptr;
        count = 0;
    };

    ~BST() {
        destroy_tree(this->root);
        count = 0;
    };

    Sequence <T>* LKP(Sequence<T>* seq) {
        return LKP_help(this->root, seq);
    }

    void insert(T item) {
        if (this->root != nullptr)
            insert_help(this->root, item);
        else {
            this->root = new node;
            this->root->data = item;
            this->root->right = nullptr;
            this->root->left = nullptr;
        }
    }
};

template <typename T>
Sequence<T>* Sort_With_Tree(Sequence<T>* seq, int (*cmp)(T, T)) {
    BST<T> assist_tree;
    for (int i = 0; i < seq->GetLength(); i++) {
        assist_tree.insert(seq->Get(i));
    }
    return assist_tree.LKP(seq);
}
