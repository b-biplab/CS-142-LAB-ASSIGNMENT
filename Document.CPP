{\rtf1\ansi\ansicpg1252\deff0\nouicompat\deflang16393{\fonttbl{\f0\fnil\fcharset0 Calibri;}}
{\*\generator Riched20 10.0.16299}\viewkind4\uc1 
\pard\sa200\sl276\slmult1\f0\fs22\lang9 #include <iostream>\par
using namespace std;\par
 \par
struct Node\par
\{\par
  double value;\par
  Node *N,*P;\par
  Node(double y)\par
  \{\par
      value = y;\par
      N = P = NULL;\par
  \}\par
\};\par
 \par
class doubleLinkedList\par
\{\par
  Node *front;\par
  Node *back;\par
  public:\par
  doubleLinkedList()\par
  \{  front = NULL; back = NULL; \}\par
  ~doubleLinkedList()\{ destroyList();\}\par
  void appendNodeFront(double x);\par
  void appendNodeBack(double x);\par
  void dispNodesForward();\par
  void dispNodesReverse();\par
  void destroyList();\par
\};\par
 \par
void doubleLinkedList::appendNodeFront(double x)\par
  \{\par
        Node *n = new Node(x);\par
        if( front == NULL)\par
        \{\par
            front = n;\par
            back = n;\par
        \}\par
        else\par
        \{\par
            front->P = n;\par
            n->N = front;\par
            front = n;\par
        \}\par
  \}\par
  void doubleLinkedList::appendNodeBack(double x)\par
  \{\par
        Node *n = new Node(x);\par
        if( back == NULL)\par
        \{\par
            front = n;\par
            back = n;\par
        \}\par
        else\par
        \{\par
            back->N = n;\par
            n->P = back;\par
            back = n;\par
        \}\par
 \par
  \}\par
 \par
  void doubleLinkedList::dispNodesForward()\par
  \{\par
      Node *temp = front;\par
      cout << "\\n\\nNodes in forward order:" << endl;\par
      while(temp != NULL)\par
      \{\par
         cout << temp->value << "   " ;\par
         temp = temp->N;\par
      \}\par
  \}\par
  void doubleLinkedList::dispNodesReverse()\par
  \{\par
      Node *temp = back;\par
      cout << "\\n\\nNodes in reverse order :" << endl;\par
      while(temp != NULL)\par
      \{\par
         cout << temp->value << "   " ;\par
         temp = temp->P;\par
      \}\par
  \}\par
void doubleLinkedList::destroyList()\par
\{\par
    Node *T = back;\par
    while(T != NULL)\par
    \{\par
        Node *T2 = T;\par
        T = T->P;\par
        delete T2;\par
    \}\par
    front = NULL;\par
    back = NULL;\par
\}\par
int main()\par
\{\par
    doubleLinkedList *list = new doubleLinkedList();\par
    //append nodes to front of the list\par
    for( int i = 1 ; i < 4 ; i++)\par
    list->appendNodeFront(i*1.1);\par
 \par
    list->dispNodesForward();\par
    list->dispNodesReverse();\par
 \par
    //append nodes to back of the list\par
    for( int i = 1 ; i < 4 ; i++)\par
    list->appendNodeBack(11.0 - (1.1 * i));\par
    cout << endl << endl;\par
    list->dispNodesForward();\par
    list->dispNodesReverse();\par
 \par
    cout << endl << endl;\par
    delete list;\par
    return 0;\par
\}\par
}
