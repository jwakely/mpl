
#ifndef BOOST_MPL_MAP_AUX_ERASE_IMPL_HPP_INCLUDED
#define BOOST_MPL_MAP_AUX_ERASE_IMPL_HPP_INCLUDED

// Copyright (c) Aleksey Gurtovoy 2003-2004
// Copyright (c) David Abrahams 2003-2004
//
// Use, modification and distribution are subject to the Boost Software 
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy 
// at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Source$
// $Date$
// $Revision$

#include <boost/mpl/erase_fwd.hpp>
#include <boost/mpl/map/aux_/has_key_impl.hpp>
#include <boost/mpl/map/aux_/item.hpp>
#include <boost/mpl/map/aux_/tag.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/base.hpp>
#include <boost/mpl/apply_if.hpp>
#include <boost/mpl/aux_/config/typeof.hpp>

#include <boost/type_traits/is_same.hpp>

namespace boost { namespace mpl {

#if defined(BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES)
template<>
struct erase_impl< aux::map_tag >
{
    template< 
          typename Map
        , typename Key
        , typename unused_
        > 
    struct apply
        : apply_if< 
              has_key_impl<aux::map_tag>::apply<Map,Key>
            , apply_if< 
                  is_same< Key,typename Map::key_ > 
                , base<Map>
                , identity< m_mask<Key,Map> >
                >
            , identity<Map>
            >
    {
    };
};
#endif

}}

#endif // BOOST_MPL_MAP_AUX_ERASE_IMPL_HPP_INCLUDED