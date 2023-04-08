
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include "graph.hpp"

 
using namespace std;
 
int main(int argc, char *argv[])
{
  int V = 1000;

  struct Graph graph = Graph(V);

  string const fileName("graph.dot");
  ofstream mystream(fileName.c_str());

  if(mystream)    
  {
    mystream << "digraph {\n";
  }
  else
  {
    cout << "ERROR. Cannot open a file" << endl;
  }
  
  ifstream ip(argv[1]);

  if(!ip.is_open()) 
  {
      std::cout << "ERROR: File Open" << '\n';
  }

  string src;
  string dest;
  string weight;
  
  int src1 = 0;
  int srct = 0;
  int i = 0;

  while(ip.good()){
    getline(ip, src,',');
    if(srct != src1 )
    {
      i++;
    }
    getline(ip,dest,',');
    getline(ip,weight,'\n');
    
    if(mystream)
    {
    mystream << "     " << src << " -> " << dest <<"[label="<<weight<<"]\n";
    }
    else
    {
        cout << "ERROR. Cannot open a file" << endl;
    }
    srct = src1;
    src1 = stoi(src);
    int dest1 = stoi(dest);
    int weight1 = stoi(weight);

    graph.addEdge(src1, dest1, weight1);
    std::cout << "-------------------" << '\n';   
  }

  if(mystream)    
  {
    mystream << "}";
  }
  else
  {
    cout << "ERROR. Cannot open a file" << endl;
  }

  ip.close();



  list<int> lista = graph.DFS();
  for(list<int>::iterator it = lista.begin(); it != lista.end(); it++)
    {
      cout << *it << " ";
    }

	return 0;
}