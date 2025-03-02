#include <iostream>
using namespace std;

class student {
public:
    string name;
    int age;

    student(string name, int age) {
        this->name = name;
        this->age = age;
    }
    void print() { cout << name << " " << age << endl; }
};

template <typename T> class Node {
public:
    T *value;
    Node<T> *next;
    Node(T *value) {
        this->value = value;
        this->next = NULL;
    }
    void print() { value->print(); }
};

template <typename T> class LinkedList {
private:
    int length;
    Node<T> *head;

public:
    LinkedList(T *value) {
        this->length = 1;
        this->head = new Node<T>(value);
    }
    void add(T *value) {
        Node<T> *newNode = new Node<T>(value);
        Node<T> *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        length++;
    }

    void addhead(T *value) {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        length++;
    }

    void delfirst() {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    void dellast() {
        Node<T> *temp = head;
        while (temp->next!=NULL)
            temp = temp->next;
        delete temp;
        length--;
    }

    void deleteNode(int index) {
       //TODO:Write the function to delete at the given index. Reuse the pre-written functions for edge cases. Account for missing index.
        if (index == 0) {
            delfirst();
        } else if (index == length - 1) {
            dellast();
        }

        Node<T> *temp = get(index-1);
        Node<T> *temp2 = temp->next;
        temp->next = temp->next->next;
        delete temp2;
        length--;
    }

   void insert(int index, T *value) {
        //TODO:Write a function to insert a new node at a give index. Reuse the pre-written functions for edge cases. Account for missing index
        if ((index < 0)||(index>=length)) {
            cout<<"Index is out of bounds"<<endl;
            return;
        }
        if (index == 0) {
            addhead(value);
        } else if (index == length - 1) {
            add(value);
        }
        else {
            Node<T> *nodeBefore = get(index-1);
            Node<T> *newNode=new Node<T>(value);
            newNode->next = nodeBefore->next;
            nodeBefore->next = newNode;
        }
        length++;
    }

    Node<T>* get(int index) {
        if ((index < 0)||(index>=length)) {
            return nullptr;
        }
        Node<T> *temp = head;
        int curIndex = 0;
        for (int i=0; i<index; i++) {
            temp = temp->next;
        }
        return temp;
    }


   void reverselist(){
        //TODO:Write a function to reverse the list using the logic from the slide.


        Node<T> *before = nullptr;
        Node<T> *curr = head;
        Node<T> *after = head->next;

        while (after!=nullptr) {
            after = curr->next;
            curr->next = before; // "flips" current's arrow around
            before = curr; // moving ptrs "up" through the list
            curr = after; // moving ptrs through the list
        }
        head = before;

    }

    void print() {
        cout << "Printing List.." << endl;
        Node<T> *temp = head;
        while (temp != NULL) {
            temp->print();
            temp = temp->next;
        }
    }
};

int main() {
    student *s1 = new student("A", 20);
    student *s2 = new student("B", 21);
    student *s3 = new student("C", 23);
    student *s4 = new student("D", 24);
    student *s5 = new student("E", 25);
    student *s6 = new student("F", 26);
    LinkedList<student> *ll = new LinkedList<student>(s1);
    ll->add(s2);
    ll->add(s3);
    ll->add(s4);
    ll->add(s5);
    ll->add(s6);
    ll->print();
    ll->reverselist();
    ll->print();
    ll->insert(4, new student("G", 22));
    ll->print();
    ll->deleteNode(4);
    ll->print();
}