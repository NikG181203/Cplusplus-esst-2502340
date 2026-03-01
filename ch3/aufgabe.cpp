// C++ implementation​​​​​​‌‌‌‌​​​‌‌​‌​​‌‌‌​‌‌‌‌‌​​​ below
#include <iostream>
#include <memory>

struct SimpleNode {
  int mItem = 0;
  std::shared_ptr<SimpleNode> mNext;
};

std::shared_ptr<SimpleNode> list;

void addElement(const int value)
{
	// TODO: Code that appends a value to the linked list 
  //auto vec = std::unique_ptr<SimpleNode>(new SimpleNode);
  auto vec = std::make_shared<SimpleNode>();
  vec->mItem = value;
  vec->mNext = list;
  list = vec; //zeigt auf zuletzt hinzugefügtes Element
}
void printList()
{
	// TODO: Print all the list items
  std::shared_ptr<SimpleNode> cur = list;
  while(cur){
    std::cout << cur->mItem << std::endl;
    cur = cur->mNext;
  }
}










// So wird Ihr Code aufgerufen.
// Für eigene Tests können Sie gerne weiteren Code hinzufügen.
// Am Ende sollte aber eine Liste mit den Elementen 145, 342, 22, 12 stehen.

addElement(12);
addElement(22);
addElement(342);
addElement(145);

printList();
