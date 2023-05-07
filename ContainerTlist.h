#include <iostream>

#ifndef ContainerTlistNmspInclude
#define ContainerTlistNmspInclude

namespace ContainerTlistNmsp
{


    template <typename TlistNode> class ListContainer
    {
    public:
        int cardinality;
	    TlistNode * current;

        ListContainer();// Ctor()
        void push_back( TlistNode * newEntry );
        TlistNode * begin() const;
        TlistNode * end() const;
    };



class TListNode
{
private:

public:
    TListNode * prev;
    TListNode * next;
    int NodeOrdinal;

    // public Ctor()
    TListNode( )
    {
    }// end : Ctor()


    void showNode()
    {
        std::cout << "\n\t this->NodeOrdinal " <<  this->NodeOrdinal << std::endl;
        std::cout << "\t pointer address this->prev " <<  this->prev << std::endl;
        std::cout << "\t pointer address this       " <<  this       << std::endl;
        std::cout << "\t pointer address this->next " <<  this->next << std::endl;
    }// end : showNode()

};

}// end nmsp

#endif
