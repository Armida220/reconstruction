// Copyright (C) 2010-2012 Conrad Sanderson
// Copyright (C) 2010-2012 NICTA (www.nicta.com.au)
// 
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.


//! \addtogroup fn_cumsum
//! @{



template<typename T1>
arma_inline
const Op<T1, op_cumsum_mat>
cumsum
  (
  const T1& X,
  const uword dim = 0,
  const typename enable_if< is_arma_type<T1>::value       == true  >::result* junk1 = 0,
  const typename enable_if< resolves_to_vector<T1>::value == false >::result* junk2 = 0
  )
  {
  arma_extra_debug_sigprint();
  arma_ignore(junk1);
  arma_ignore(junk2);
  
  return Op<T1, op_cumsum_mat>(X, dim, 0);
  }



template<typename T1>
arma_inline
const Op<T1, op_cumsum_mat>
cumsum
  (
  const T1& X,
  const uword dim,
  const typename enable_if<resolves_to_vector<T1>::value == true>::result* junk = 0
  )
  {
  arma_extra_debug_sigprint();
  arma_ignore(junk);
  
  return Op<T1, op_cumsum_mat>(X, dim, 0);
  }



template<typename T1>
arma_inline
const Op<T1, op_cumsum_vec>
cumsum
  (
  const T1& X,
  const arma_empty_class junk1 = arma_empty_class(),
  const typename enable_if<resolves_to_vector<T1>::value == true>::result* junk2 = 0
  )
  {
  arma_extra_debug_sigprint();
  arma_ignore(junk1);
  arma_ignore(junk2);
  
  return Op<T1, op_cumsum_vec>(X);
  }



template<typename T1>
arma_inline
const Op<Op<T1, op_cumsum_vec>, op_cumsum_mat>
cumsum
  (
  const Op<T1, op_cumsum_vec>& X,
  const uword dim,
  const typename enable_if<resolves_to_vector<T1>::value == true>::result* junk = 0
  )
  {
  arma_extra_debug_sigprint();
  arma_ignore(junk);
  
  return Op<Op<T1, op_cumsum_vec>, op_cumsum_mat>(X, dim, 0);
  }



template<typename T1>
arma_inline
const Op<Op<T1, op_cumsum_vec>, op_cumsum_vec>
cumsum
  (
  const Op<T1, op_cumsum_vec>& X,
  const arma_empty_class junk1 = arma_empty_class(),
  const typename enable_if<resolves_to_vector<T1>::value == true>::result* junk2 = 0
  )
  {
  arma_extra_debug_sigprint();
  arma_ignore(junk1);
  arma_ignore(junk2);
  
  return Op<Op<T1, op_cumsum_vec>, op_cumsum_vec>(X);
  }



template<typename T>
arma_inline
arma_warn_unused
const typename arma_scalar_only<T>::result &
cumsum(const T& x)
  {
  return x;
  }



//! @}
