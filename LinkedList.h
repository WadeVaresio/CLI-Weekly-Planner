#ifndef WEEKLY_CALENDAR_LINKEDLIST_H
#define WEEKLY_CALENDAR_LINKEDLIST_H

template<typename T> class LinkedList{
public:
  struct Node{
    T data;
    Node *next;
    Node *prev;
  };

  LinkedList(){
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
  }

  void insert(T data){
    this->size++;
    auto insertion = new Node{data, nullptr, nullptr};

    if(!head){
      head, tail = insertion;
      return;
    }

    Node * cur = head; // guaranteed not to be nullptr

    while(cur->next != nullptr)
      cur = cur->next;

    cur->next = insertion;
    insertion->prev = cur;
  }

  T* getEntries(){
    auto entries = new T[this->size - 1];

    Node* cur = head;
    int i = 0;

    while(cur != nullptr){
      entries[i] = cur->data;
      i++;
    }

    return entries;
  }

  bool search(T target){
    Node * cur = head;

    while(cur != nullptr){
      if(cur->data == target)
        return true;

      cur = cur->next;
    }

    return false;
  }

private:
  Node *head;
  Node *tail;
  int size;
};

#endif //WEEKLY_CALENDAR_LINKEDLIST_H
