#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache: public Cache
{
    public:
    LRUCache(int capacity)
    {
        cp = capacity;
        head = NULL;
        tail = NULL;
    }
    void set(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            mp[key]->value = value;
            if (mp[key] != head)
            {
                if (mp[key] == tail)
                {
                    tail = tail->prev;
                    tail->next = NULL;
                }
                else
                {
                    mp[key]->prev->next = mp[key]->next;
                    mp[key]->next->prev = mp[key]->prev;
                }
                mp[key]->next = head;
                mp[key]->prev = NULL;
                head->prev = mp[key];
                head = mp[key];
            }
        }
        else
        {
            if (mp.size() == cp)
            {
                mp.erase(tail->key);
                if (tail->prev != NULL)
                {
                    tail->prev->next = NULL;
                    tail = tail->prev;
                }
                else
                {
                    head = NULL;
                    tail = NULL;
                }
            }
            Node* newNode = new Node(key, value);
            mp[key] = newNode;
            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }
    }
    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            if (mp[key] != head)
            {
                if (mp[key] == tail)
                {
                    tail = tail->prev;
                    tail->next = NULL;
                }
                else
                {
                    mp[key]->prev->next = mp[key]->next;
                    mp[key]->next->prev = mp[key]->prev;
                }
                mp[key]->next = head;
                mp[key]->prev = NULL;
                head->prev = mp[key];
                head = mp[key];
            }
            return mp[key]->value;
        }
        else
        {
            return -1;
        }
    }
};
int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
