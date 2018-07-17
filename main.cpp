#include <iostream>
#include "ContainerTlist.h"

using namespace std;

int main()
{
    const int ListNodeCardinality = +314;
    ContainerTlistNmsp::ListContainer<ContainerTlistNmsp::TListNode> * the_T_Container =
        new ContainerTlistNmsp::ListContainer<ContainerTlistNmsp::TListNode>();// --here the first node is allocated.
    //
    for( int c=0; c<ListNodeCardinality; c++)
    {// Nodes in cardinality of "ListNodeCardinality" are allocated in this loop. (One is allocated before, from ListContainer::Ctor().
        ContainerTlistNmsp::TListNode * tmp = new ContainerTlistNmsp::TListNode();//----each new node is allocated here, before being pushed_bach.
        the_T_Container->push_back( tmp );
    }
    //
    ContainerTlistNmsp::TListNode * cursor = the_T_Container->begin()->next;//--skip the first one, which is only a termminator.
    ContainerTlistNmsp::TListNode * afterLast = the_T_Container->end();
    for( ; cursor != afterLast ; cursor=cursor->next )
    {
        cursor->showNode();
    }

    cout << endl<< endl<< "Strike ""Enter"" to leave." << endl;
//    string mystring;
//    cin >> mystring;
    int i;
    cin >> i;
    return 0;
}
