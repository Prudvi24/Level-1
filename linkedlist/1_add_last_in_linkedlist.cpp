#include <iostream>

using namespace std;

class node
{
public :
  int data;
  node* next;
};

class linked_list
{
public:
  node* head, *tail;
  int size = 0;

public:
  linked_list()
  {
    head = NULL;
    tail = NULL;
  }

  void addLast(int n)
  {
    // Write your code here
    node *newnode = new node();
    newnode->data = n;
    newnode->next = nullptr;
    if(head==NULL){
      head = newnode;
      tail = newnode;
    }
    else{
      tail->next = newnode;
      tail = newnode;
    }
    size++;
  }
  void display() {
    for (node* tmp = head; tmp != NULL; tmp = tmp->next) {
      cout << tmp->data << " ";
    }

  }

  void testList() {
    for (node* temp = head; temp != NULL; temp = temp->next) {
      cout << temp->data << endl;
    }
    cout << size << endl;

    if (size > 0) {
      cout << tail->data << endl;
    }
  }
};


int main() {
  string str;
  linked_list l;
  while (true) {
    getline(cin, str);
    if (str[0] == 'q') {
      break;
    }
    if (str[0] == 'a') {
      string ss = str.substr(8, 2);
      int n = stoi(ss);
      l.addLast( n);

    }

  }

  l.testList();
  return 0;
}