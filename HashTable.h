//
// Created by wade on 6/13/20.
//

#ifndef WEEKLY_CALENDAR_HASHTABLE_H
#define WEEKLY_CALENDAR_HASHTABLE_H

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
    table = new TableEntry*[this->initialSize];

    for(int i = 0; i < this->initialSize; i++){
      table[i] = nullptr;
    }
  }

  void insert(T entry, int hashableKey){
    this->entries++;

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

    if(!table[bucket]) // bucket is empty
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

private:
  void resizeTable(){
    size += 5;

    T** tempTable = new T*[size];

    for(int i = 0; i < size - 5; i++){
//      tempTable[i] = table[i];
        TableEntry* t = table[i];
    }

    //table = tempTable;
    delete[] tempTable;
  }

  int hash(int hashableKey){
    return hashableKey % size;
  }

  int initialSize = 5;
  int entries, size;
  TableEntry **table;
};


#endif //WEEKLY_CALENDAR_HASHTABLE_H
