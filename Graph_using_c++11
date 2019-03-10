/*
 * matrickOpp.cpp
 *
 *  Created on: 13-Sep-2018
 *      Author: barun
 */
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include<string.h>
#include<iostream>
using namespace std;
#include <limits.h>

#define V 9


int minDistFromSourceNode(int dist[], bool sptSet[]);
int printMinDistanceFromSourceNode(int dist[], int n);
void dijkstra_Algo_Algo(int graph[V][V], int src);
// Number of vertices in the graph

// Macro
#define Row  3
#define Col  3
/* Diagonal print /
 * square print
 * Diagonal Reverse
 * Diagonal swap
 * Diagonal short
 * cross diagonal reverse
 * Upper triangle
 *  lower triangle
 *  matrix square
 *
 *
 *
 *
 *
 *
 */
#if 0
void printDiagonal(int str[][Col])
{
 for(uint8_t movAr=0;movAr<3;movAr++)
 {
  printf("%d \n",str[movAr][movAr]);
 }

}
void printDiagonalSq(int str[][Col])
{
 for(uint8_t movAr=0;movAr<3;movAr++)
 {
  printf("%d \n",(str[movAr][movAr]*str[movAr][movAr]));
 }

}

void printDiagonalReverse(int str[][Col])
{
 for(int movAr=2; 0<=movAr;movAr--)
 {
  printf("%d \n",str[movAr][movAr]);
 }
}

void printDiagonalSwape(int str[][Col])
{
 for(uint8_t movAr=0,movArl=Row-1;movAr<(Row/2);movAr++,movArl--)
 {
  if(**str)
  {
   str[movAr][movAr] =str[movArl][movArl]^str[movAr][movAr];
   str[movArl][movArl] =str[movArl][movArl]^str[movAr][movAr];
   str[movAr][movAr] =str[movArl][movArl]^str[movAr][movAr];
  }

 }
 for(uint8_t movAr=0;movAr<3;movAr++)
 {
  printf("%d \n",(str[movAr][movAr]*str[movAr][movAr]));
 }

}

void printOppositeDiagonal(int str[][Col])
{
 for(uint8_t movAr=0,movArLast=3;movAr<3 && movArLast > 0;movAr++,movArLast--)
 {
  printf("%d \n",str[movAr][movArLast]);
 }

}
#endif


int minDistFromSourceNode(int dist[], bool sptSet[])
{
// Initialize min value
int min = INT_MAX, min_index;

for (int v = 0; v < V; v++)
 if (sptSet[v] == false && dist[v] <= min)
  min = dist[v], min_index = v;

return min_index;
}

// A utility function to print the constructed distance array
int printMinDistanceFromSourceNode(int dist[], int n)
{
printf("Vertex Distance from Source\n");
for (int i = 0; i < V; i++)
 printf("%d tt %d\n", i, dist[i]);
}


void dijkstra_Algo_Algo(int graph[V][V], int src)
{
 int dist[V];
 int noused;

 bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest


 for (int i = 0; i < V; i++)
  dist[i] = INT_MAX, sptSet[i] = false;


 dist[src] = 0;


 for (int count = 0; count < V-1; count++)
 {
 int u = minDistFromSourceNode(dist, sptSet);

 // Mark the picked vertex as processed
 sptSet[u] = true;


 for (int v = 0; v < V; v++)


  if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
         && dist[u]+graph[u][v] < dist[v])
   dist[v] = dist[u] + graph[u][v];
 }


 noused=printMinDistanceFromSourceNode(dist, V);
}

void dijkhstra_Algo_for_test(int graph[V][V], int source )
{


 bool sptSet[V];
 int minDist[V];
 int u;

 memset(sptSet,0,V);
 memset(minDist,INT_MAX,V);

 minDist[source]= 0;

 for(int count=0;count<V-1;count++)
 {
   u   = minDistFromSourceNode(minDist,sptSet);

   sptSet[u]=true;


   for(int vertice=0;vertice<V;vertice++)
   {
    if(!sptSet[vertice] && graph[vertice][vertice] && \
      minDist[u]!=INT_MAX && minDist[u]+graph[u][vertice]<minDist[vertice])
    {
        minDist[vertice] = minDist[u]+graph[u][vertice];
    }
   }





 }


 int noused=printMinDistanceFromSourceNode(minDist, V);








}



/*int main()
{
 int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
      {4, 0, 8, 0, 0, 0, 0, 11, 0},
      {0, 8, 0, 7, 0, 4, 0, 0, 2},
      {0, 0, 7, 0, 9, 14, 0, 0, 0},
      {0, 0, 0, 9, 0, 10, 0, 0, 0},
      {0, 0, 4, 14, 10, 0, 2, 0, 0},
      {0, 0, 0, 0, 0, 2, 0, 1, 6},
      {8, 11, 0, 0, 0, 0, 1, 0, 7},
      {0, 0, 2, 0, 0, 0, 6, 7, 0}
      };

 dijkhstra_Algo_for_test(graph, 0);

//cout<<"Hi"<<'\n';

return 0;
}*/
/*
 * GraphMainProblem.cpp
 *
 *  Created on: 08-Oct-2018
 *      Author: barun
 */

/*
 * matrickOpp.cpp
 *
 *  Created on: 13-Sep-2018
 *      Author: barun
 */
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include<string.h>
#include<list>
#include<stack>
#include<iostream>
#include<stdio.h>
using namespace std;

#if 0
class ToplogicalShort
{
 int v;
 list<int> *adj;
 void toplogyshortUtil( int v,bool visted[],stack<int> &Stk);
 public:
 ToplogicalShort( int v)
 {
  this->v =v;
  adj = new list<int>[v];
 }
 void addEdge(int v,int w)
 {
  adj[v].push_back(w);

 }

 void toplogyShort(void)
 {
  stack<int> Stack;
  bool Visted[v];
  memset(Visted,0,sizeof(Visted));

  for(int mov =0; mov< v;mov++)
  {
   if(Visted[mov]==false)
   {
    toplogyshortUtil(mov,Visted,Stack);

   }
  }

  while(Stack.empty()==false)
  {
   cout<<Stack.top()<<" ";
   Stack.pop();
  }
 }

};


void ToplogicalShort ::toplogyshortUtil( int v,bool visted[],stack<int> &Stk)
{

 visted[v] =true;
 list<int> ::iterator it;
 for(it =adj[v].begin();it!=adj[v].end();it++)
 {
  if(!visted[*it])
  {
   toplogyshortUtil(*it,visted,Stk);
  }
 }

 Stk.push(v);

}

/*
int main()
{
 ToplogicalShort g(6);
 g.addEdge(5, 2);
 g.addEdge(5, 0);
 g.addEdge(4, 0);
 g.addEdge(4, 1);
 g.addEdge(2, 3);
 g.addEdge(3, 1);

 g.toplogyShort();


return 1;
}
*/
#endif
