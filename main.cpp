/*
* testin dis graph bish
*/



#include <iostream>
#include "graph.h"
using namespace std;



void test1 (void)
{
  cout << "testing grap.txt" << endl;
  Graph g1("grap.txt");
  //g1.dfs();
  cout << boolalpha << g1.cycle() << endl;
}


void test2 (void)
{
  cout << "testing grap2.txt" << endl;
  Graph g2("grap2.txt");
  //g2.dfs();
  cout << boolalpha << g2.cycle() << endl;
}



void test3 (void)
{
  cout << "testing grap3.txt" << endl;
  Graph g3("grap3.txt");
//  g3.dfs();
  cout << boolalpha << g3.cycle() << endl;
}

void test4 (void)
{
  cout << "testing grap4.txt" << endl;
  Graph g4("grap4.txt");
  //g4.dfs();
  cout << boolalpha << g4.cycle() << endl;
}

int main (void)
{
  test1();
  test2();
  test3();
  test4();
}
