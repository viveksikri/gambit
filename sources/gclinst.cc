//
// FILE: gclinst.cc -- Instantiations for GCL
//

#include "gtext.h"

#include "gstack.imp"
#include "garray.imp"
#include "gblock.imp"
#include "gslist.imp"

class Portion;
class EfgPortion;
class NfgPortion;
class FuncDescObj;
class CallFuncObj;
class RefHashTable;

//----------
// Stacks
//----------

template class gStack<Portion *>;
template class gStack<gStack<Portion *> *>;
template class gStack<CallFuncObj *>;
template class gStack<RefHashTable *>;

//--------
// Lists
//--------

template class gSortList<FuncDescObj *>;
template class gListSorter<FuncDescObj *>;
template class gSortList<gText>;
template class gListSorter<gText>;


//--------------------
// Arrays and Blocks
//--------------------

template class gArray<NfgPortion *>;
template class gBlock<NfgPortion *>;

template class gArray<EfgPortion *>;
template class gBlock<EfgPortion *>;


 
