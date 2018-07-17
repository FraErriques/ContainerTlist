#include <stdlib.h>
#include "ContainerTlist.h"


namespace ContainerTlistNmsp
{

// model :
//template <typename type> namespace::retTypeName namespace::className::func-name(parameter list) 
//{ body of function} 


template <typename TlistNode> ListContainer<TlistNode>::ListContainer()
{
	this->current = new TListNode();
	this->current->prev = NULL;
	this->current->next = NULL;
    this->cardinality = 0;// the ordinal +1 will be given to the effective first record. The this->first is only a terminator.
    this->current->NodeOrdinal = this->cardinality;
}// end Ctor()




template <typename TlistNode> void ListContainer<TlistNode>::push_back( TlistNode * newEntry )
{
    this->current->next = newEntry;// the newEntry::Ctor() is called from outside the push_back. It will require specific initialization.
    TlistNode * tmp = this->current;// use a swap memory zone, before updating the current node.
    this->current = this->current->next;// step forward : here the this->current changes.
    this->current->prev = tmp;// update the previousNode pointer, recovering the old this->current from the tmp swap-variable.
    this->current->next = NULL;// update the nextNode pointer to NULL; NB. otherwise it is not NULL, it's a dirty pointer, like 0xccccc.
    this->current->NodeOrdinal = ++this->cardinality;// another node has been pushed back.
}


template <typename TlistNode> TlistNode * ListContainer<TlistNode>::begin() const
{
    TlistNode * tmp = this->current;// use a swap memory zone.
    //
    for( ; tmp->prev != NULL ; )
    {// just rewind.
        tmp = tmp->prev;
    }
    // ready.
    return tmp;
}// end : begin()


template <typename TlistNode> TlistNode * ListContainer<TlistNode>::end() const
{
    TlistNode * tmp = this->current;// use a swap memory zone.
    //
    for( ; tmp != NULL; )
    {// just move forward.
        tmp = tmp->next;
    }
    // ready.
    return tmp;
}// end : end()


}// end nmsp.


// explicit instantiation
template class ContainerTlistNmsp::ListContainer<ContainerTlistNmsp::TListNode>; // without it, linker_unresolved_external comes.
