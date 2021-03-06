#ifndef WEEKLY_CALENDAR_HASHTABLE_H
#define WEEKLY_CALENDAR_HASHTABLE_H

#include "LinkedList.h"

template <typename T> class HashTable {
public:
  struct TableEntry{
    T data;
    int hashKey;
    TableEntry* next;
  };

  HashTable<T>(){
    this->entries = 0;
    this-> size = this->initialSize;
    this->table = new TableEntry*[this->initialSize]; // Array of TableEntry pointers

    for(int i = 0; i < this->initialSize; i++){
      table[i] = nullptr;
    }
  }

  void insert(T entry, int hashableKey){
    this->entries++;
    this->keys.insert(hashableKey);

    if(entries == size)
      this->resizeTable();

    int bucket = this->hash(hashableKey);

    auto *tableEntry = new TableEntry{entry, hashableKey, nullptr};

    if(!table[bucket])
      table[bucket] = tableEntry;
    else{
      tableEntry->next = table[bucket];
      table[bucket] = tableEntry;
    }
  }

  bool search(T target, int hashableKey){
    int bucket = this->hash(hashableKey);

    if(!table[bucket]) // bucket is empty (nullptr)
      return false;
    else{
      TableEntry *cur = table[bucket];
      do{ //we are guaranteed that cur != nullptr
        if(cur->data == target)
          return true;

        cur = cur->next;
      }while(cur != nullptr);

      return false;
    }
  }

  int getNumberOfEntries(){ return this->entries; }

private:
  void resizeTable(){
    size += 5;

    auto resizedTable = new TableEntry*[size];
    TableEntry** tempTable = table;

    for(int i = 0; i < size - 5; i++){
      resizedTable[i] = table[i];
    }

    this->table = resizedTable;
    delete[] tempTable; // Delete the original table
  }

  int hash(int hashableKey){
    return hashableKey % size;
  }

  int initialSize = 5;
  int entries, size;
  TableEntry **table; // Array of pointers
  LinkedList<int> keys; // keep track of all keys
};

#endif //WEEKLY_CALENDAR_HASHTABLE_H
