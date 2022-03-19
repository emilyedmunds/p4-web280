#ifndef LIST_H
#define LIST_H
/* List.h
 *
 * doubly-linked, double-ended list with Iterator interface
 * Project UID c1f28c309e55405daf00c565d57ff9ad
 * EECS 280 Project 4
 */

#include <iostream>
#include <cassert> //assert
#include <cstddef> //NULL
#include <string>
#include <sstream>
#include <utility>



template <typename T>
class List {
  //OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:
    //constructor
    List():first(nullptr),last(nullptr){}
    //need copy constructor

  //EFFECTS:  returns true if the list is empty
  bool empty() const;

  //EFFECTS: returns the number of elements in this List
  //HINT:    Traversing a list is really slow.  Instead, keep track of the size
  //         with a private member variable.  That's how std::list does it.
  int size() const;

  //REQUIRES: list is not empty
  //EFFECTS: Returns the first element in the list by reference
  T & front();

  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
  T & back();

  //EFFECTS:  inserts datum into the front of the list
  void push_front(const T &datum);

  //EFFECTS:  inserts datum into the back of the list
  void push_back(const T &datum);

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
  void pop_front();

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
  void pop_back();

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
  void clear();

  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you can omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists

private:
  //a private type
  struct Node {
    Node *next;
    Node *prev;
    T datum;
  };

  //REQUIRES: list is empty
  //EFFECTS:  copies all nodes from other to this
  void copy_all(const List<T> &other);

  Node *first;   // points to first Node in list, or nullptr if list is empty
  Node *last;    // points to last Node in list, or nullptr if list is empty

public:
  ////////////////////////////////////////
  class Iterator {
      friend class List;
    //OVERVIEW: Iterator interface to List

    // You should add in a default constructor, destructor, copy constructor,
    // and overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you can omit them. A user
    // of the class must be able to create, copy, assign, and destroy Iterators.

    // Your iterator should implement the following public operators: *,
    // ++ (prefix), default constructor, == and !=.

  public:
      Iterator():node_ptr(nullptr){}
      ~Iterator() { delete node_ptr; }
    // This operator will be used to test your code. Do not modify it.
    // Requires that the current element is dereferenceable.
    Iterator& operator--() {
      assert(node_ptr);
      node_ptr = node_ptr->prev;
      return *this;
    }
      T & operator*()const;
      Iterator &operator++();
      bool operator==(Iterator rhs)const;
      bool operator!=(Iterator rhs) const;

  private:
    Node *node_ptr; //current Iterator position is a List node
    // add any additional necessary member variables here

    // add any friend declarations here

    // construct an Iterator at a specific position
      //below is how it came, i edited it
//    Iterator(Node *p);
      Iterator(Node *p):node_ptr(p){}

  };//List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element
  Iterator begin() const {
    return Iterator(first);
  }

  // return an Iterator pointing to "past the end"
    Iterator end() const{
        return Iterator();
    }

  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container
  void erase(Iterator i);

  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: inserts datum before the element at the specified position.
  void insert(Iterator i, const T &datum);

};//List


////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for
// Iterator.



//EFFECTS:  returns true if the list is empty
template<typename T>
bool List<T>::empty() const {
  assert(false);
    //see if first and last are pointing to null_ptr
    //a list of size zero is defined by: first = null_ptr
//    Node* ptr = first; //this is probs wrong
//    while(*ptr != nullptr){
//        ptr = ptr->next;
//    }
//    for(Node *ptr = first; ptr != nullptr; ptr = ptr->next){
//        //do something w given datum
//    }
    return (first == nullptr && last == nullptr);
}

//EFFECTS: returns the number of elements in this List
//HINT:    Traversing a list is really slow.  Instead, keep track of the size
//         with a private member variable.  That's how std::list does it.
template<typename T>
int List<T>::size() const{
    assert(false);
}

//REQUIRES: list is not empty
//EFFECTS: Returns the first element in the list by reference
template<typename T>
T & List<T>:: front(){
    return first;
}

//REQUIRES: list is not empty
//EFFECTS: Returns the last element in the list by reference
template<typename T>
T & List<T>::back(){
   return last;
}

//EFFECTS:  inserts datum into the front of the list
template<typename T>
void List<T>::push_front(const T &datum){
    //need to link our new node (we will call it temp) to first, and link first to temp
    //first changing first->prev from nullptr to our new node
    //then we can have our temp->next = first; (our nodes are now linked)
    //and update temp->prev and change which node is first
   
//    Node* temp1 = new Node;
//    temp1->datum = datum;
//    temp1->next = first;
//    temp1->prev = nullptr;
//    Node *temp1 = new Node{datum, first, nullptr}; //this code is equiv to the lines above it
    //first = temp1
    
//    Node* temp = new Node;
//    temp->datum = datum;
//    first->prev = temp;
//    temp->next = first;
//    temp->prev = nullptr;
//    first = temp;
    Node* temp = new Node{datum, first, nullptr};
    if(empty()){
        first = last = temp;
    }else{
        first->prev = temp;
        temp->nect = first;
        first = temp;
    }
    
}


//EFFECTS:  inserts datum into the back of the list
template<typename T>
void List<T>::push_back(const T &datum){
    //take into account if you are calling push_back on an empty list
//    Node* temp = new Node;
//    temp-> datum = datum;
//    last->next = temp;
//    temp->prev = last;
//    temp->next = nullptr;
//    last = temp;
          
    Node* temp = new Node{datum, nullptr, last};
    if(empty()){
        first = last = temp;
    }else{
        last->next = temp;
        temp->prev = last;
        last = temp;
    }
}

//REQUIRES: list is not empty
//MODIFIES: may invalidate list iterators
//EFFECTS:  removes the item at the front of the list
template<typename T>
void List<T>::pop_front(){
    //removes an element from front of list
    //need to delete our first node
    //update the next node ot be first (if it exists)
    //first always refers to start of list
    assert(!empty());
    Node* ptr = first->next; //first next is address of node1
    delete first; //since first is a pointer,
                //deleting first removes the data at that location in memory not the pointer itseld
    first = ptr; //first holds address of node1 in memory as opposed to having address of node0
    first->prev = nullptr;
//    if(first == nullptr){
//        ptr->last = nullptr;
//    }
    
}

//REQUIRES: list is not empty
//MODIFIES: may invalidate list iterators
//EFFECTS:  removes the item at the back of the list
template<typename T>
void List<T>::pop_back(){
    assert(!empty());
    Node* ptr = last->prev;
    delete last;
    last = ptr;
    last->next = nullptr;
    
}

//MODIFIES: may invalidate list iterators
//EFFECTS:  removes all items from the list
template<typename T>
void List<T>::clear(){
    //iteratively go thru and delete every node (remember pop_front and pop_back do this for us automatically
    //pop front deletes node at front, so what if we go thru list and call popfront until list is undefined (until first is defined as nullptr)
    assert(false);
}
//not sure if this should have the List<T>:: part
template<typename T>
void List<T>::copy_all(const List<T> &other){
    //copies over all values of next and previous
    //copies everything from (other) to (this)
    for(Node* ptr = first; ptr != nullptr; ptr = ptr->next){
        this->push_back(other);
    }
}

//iterator functions
template<typename T>
T & List<T>::Iterator::operator*() const {
    assert(node_ptr);
    return node_ptr->datum;
}
template<typename T>
typename List<T>::Iterator & List<T>::Iterator::operator++() {
    assert(node_ptr);
    node_ptr = node_ptr->next;
    return *this;
}
template<typename T>
bool List<T>::Iterator::operator==(Iterator rhs) const {
    return node_ptr == rhs.node_ptr;
}
template<typename T>
bool List<T>::Iterator::operator!=(Iterator rhs) const {
    return node_ptr != rhs.node_ptr;
}
//REQUIRES: i is a valid, dereferenceable iterator associated with this list
//MODIFIES: may invalidate other list iterators
//EFFECTS: Removes a single element from the list container

template<typename T>
void List<T>::Iterator::erase(Iterator i){
    //given an iterator i, delete the node at a given iterator
    Node *target = i.node_ptr;
    if(i == Iterator(last)){
        pop_back();
    }
    else if(i == Iterator(first)){
        pop_front();
    }
    else{
        target->prev->next = target->next; //(first->next = last)
        target->next->prev = target->prev;//(last->prev = first)
        delete target;
    }
}

//REQUIRES: i is a valid iterator associated with this list
//EFFECTS: inserts datum before the element at the specified position.
template<typename T>
void List<T>::Iterator::insert(Iterator i, const T &datum){
    Node *target = new Node;
    target->datum = datum;
    Node *iter = i.node_ptr;
    if(i == first){
        push_front(datum);
    }else{
        target->next = iter;
        target->prev = iter->prev;
        iter->prev->next = target;
        iter->prev = target;
    }
   
}
#endif // Do not remove this. Write all your code above this line.
