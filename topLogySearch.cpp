/****************************************
Desined by Barun Toplogy Search!!
Expolrig Ai using c++11 
10  May 2018 
***************************************/

#include<iostream>
#include<list>
#include<stack>
#include<stdio.h>
#include<stdint.h>
#define node 6
using namespace std;

class toplogySearchInGraph
{
	
	int v;
	list<int> *adg;
	public:
		void addEdge(int v,int w);
		toplogySearchInGraph(int v)
		{
			this->v=v;
			adg = new list<int>[v];
		}
		void toplogySearchUtil(int v, bool *visted,stack<int> &StackNode);
		void topLogySearch(void);
		
		
	
};
/**********************************************************
adding edge into this!!

**********************************************************/
void toplogySearchInGraph ::addEdge(int v,int w)
{
		adg[v].push_back(w);													
}
/************************************************
process function for toplogy search
******************************************/
void toplogySearchInGraph ::topLogySearch(void)
{
		stack<int> sNode; 
		bool *visted = new bool[v];
		//memset(visted,false,node);
		for(uint8_t mov=0;mov<v;mov++)
		{
			visted[mov] =false;
		}
		
		for(uint8_t mov=0;mov<v;mov++)
		{
			if(visted[mov] ==false)
			{
				toplogySearchUtil(mov,visted,sNode);
			}
			
			
		}
		// print
		while(sNode.empty()==false)
		{
			cout<<sNode.pop()<<endl;
			sNode.pop();
		}
													
}
/*****************************************************

// inprocessing function
**************************************************/
void toplogySearchInGraph::toplogySearchUtil(int v, bool *visted,stack<int> &StackNode)
{
	visted[v]= true;
	list<int>::iterator it;
	for(it=adg[v].begin();it!=adg[v].end();it++)
	{
		if(!visted[*it])
			toplogySearchUtil(*it,visted,StackNode);
	}
	
	
		stackNode.push(v);
		
}

int main()
{
	toplogySearchInGraph g(node); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
    g.topLogySearch();
  
	cout<<"Designed By Barun!!"<<endl;
	return 0;
}
