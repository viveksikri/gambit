//
// FILE: lemke.cc -- Lemke-Howson module
//
// $Id$
//
//

#include "lemke.imp"

//---------------------------------------------------------------------------
//                       LemkeParams: member functions
//---------------------------------------------------------------------------

LemkeParams::LemkeParams(gStatus &s) 
  : AlgParams(s), dup_strat(0), maxdepth(0)
{ }



int Lemke(const NFSupport &support, const LemkeParams &params, 
          gList<MixedSolution> &solutions,
          int &npivots, double &time)
{
  if (params.precision == precDOUBLE)  {
    LemkeModule<double> module(support, params);
    module.Lemke(params.dup_strat);
    for (int i = 1; i <= module.GetSolutions().Length(); i++)  
      solutions.Append(MixedSolution(module.GetSolutions()[i]));
    npivots = module.NumPivots();
    time = module.Time();
  }
  else  {
    LemkeModule<gRational> module(support, params);
    module.Lemke(params.dup_strat);
    for (int i = 1; i <= module.GetSolutions().Length(); i++)  
      solutions.Append(MixedSolution(module.GetSolutions()[i]));
    npivots = module.NumPivots();
    time = module.Time();
  }

  return 1;
}

#include "rational.h"

template class LemkeModule<double>;
template class LemkeModule<gRational>;
