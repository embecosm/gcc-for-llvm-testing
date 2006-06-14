// -*- C++ -*-

// Copyright (C) 2005, 2006 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the terms
// of the GNU General Public License as published by the Free Software
// Foundation; either version 2, or (at your option) any later
// version.

// This library is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this library; see the file COPYING.  If not, write to
// the Free Software Foundation, 59 Temple Place - Suite 330, Boston,
// MA 02111-1307, USA.

// As a special exception, you may use this file as part of a free
// software library without restriction.  Specifically, if other files
// instantiate templates or use macros or inline functions from this
// file, or you compile this file and link it with other files to
// produce an executable, this file does not by itself cause the
// resulting executable to be covered by the GNU General Public
// License.  This exception does not however invalidate any other
// reasons why the executable file might be covered by the GNU General
// Public License.

// Copyright (C) 2004 Ami Tavory and Vladimir Dreizin, IBM-HRL.

// Permission to use, copy, modify, sell, and distribute this software
// is hereby granted without fee, provided that the above copyright
// notice appears in all copies, and that both that copyright notice
// and this permission notice appear in supporting documentation. None
// of the above authors, nor IBM Haifa Research Laboratories, make any
// representation about the suitability of this software for any
// purpose. It is provided "as is" without express or implied
// warranty.

/**
 * @file join_test.hpp
 * Contains a join performance test.
 */

#ifndef PB_DS_JOIN_TEST_HPP
#define PB_DS_JOIN_TEST_HPP

#include <performance/time/timing_test_base.hpp>
#include <ext/pb_ds/detail/type_utils.hpp>
#include <performance/io/xml_formatter.hpp>
#include <common_type/priority_queue/string_form.hpp>
#include <iterator>

namespace pb_ds
{
  namespace test
  {
    namespace detail
    {
      template<typename It, typename Cntnr>
      class double_push_functor
      {
	const It _M_begin;
	const It _M_end;

      public:
        double_push_functor(It b,  It e) : _M_begin(b), _M_end(e) { }

	void
        operator()(std::size_t resolution)
	{
	  typedef typename Cntnr::const_reference const_reference;
	  for (std::size_t n = 0; n < resolution; ++n)
	    {
	      Cntnr c0;
	      Cntnr c1;
	      for (It it = _M_begin; it != _M_end; ++it)
		{
		  c0.push(const_reference(it->first));
		  c1.push(const_reference(it->first));
		}
	    }
	}
      };

      template<typename It, typename Cntnr>
      class double_push_join_functor
      {
	const It _M_begin;
	const It _M_end;

      public:
        double_push_join_functor(It b,  It e) : _M_begin(b), _M_end(e) { }

	void
        operator()(std::size_t resolution)
	{
	  typedef typename Cntnr::const_reference const_reference;
	  for (std::size_t n = 0; n < resolution; ++n)
	    {
	      Cntnr c0;
	      Cntnr c1;
	      for (It it = _M_begin; it != _M_end; ++it)
		{
		  c0.push(const_reference(it->first));
		  c1.push(const_reference(it->first));
		}
	      c0.join(c1);
	    }
	}
      };
    } // namespace detail

    template<typename It>
    class join_test : private pb_ds::test::detail::timing_test_base
    {
      const It 		m_ins_b;
      const size_t 	m_ins_vn;
      const size_t 	m_ins_vs;
      const size_t 	m_ins_vm;

    public:
      join_test(It ins_b, size_t ins_vn, size_t ins_vs, size_t ins_vm)
	: m_ins_b(ins_b), m_ins_vn(ins_vn), m_ins_vs(ins_vs), m_ins_vm(ins_vm)
      { }

      template<typename Cntnr>
      void
      operator()(pb_ds::detail::type_to_type<Cntnr>)
      {
	using pb_ds::test::detail::double_push_functor;
	using pb_ds::test::detail::double_push_join_functor;
	typedef pb_ds::test::detail::timing_test_base base_type;
	typedef xml_result_set_performance_formatter result_type;
	result_type res(string_form<Cntnr>::name(), string_form<Cntnr>::desc());
	  
	for (size_t n = 0; m_ins_vn + n*  m_ins_vs < m_ins_vm; ++n)
	  {
	    const size_t v = m_ins_vn + n *  m_ins_vs;
	    It b = m_ins_b;
	    It e = m_ins_b;
	    std::advance(e, v);

	    double_push_functor<It, Cntnr> double_push_fn(b, e);
	    const double double_push_res = base_type::operator()(double_push_fn);
	    double_push_join_functor<It, Cntnr> double_push_join_fn(b, e);
	    const double double_push_join_res = base_type::operator()(double_push_join_fn);
	      
	    const double effective_delta = std::max(double_push_join_res - double_push_res,
						    base_type::min_time_res());
	    res.add_res(v, effective_delta / v);
	  }
      }

    private:
      join_test(const join_test&);

      template<typename Cntnr>
      void
      join(pb_ds::detail::type_to_type<Cntnr>, It b, It e)
      {
	Cntnr cntnr;
	typedef typename Cntnr::const_reference const_reference;
	for (It it = b; it != e; ++it)
	  cntnr.join(const_reference(*it));
      }
    };
  } // namespace test
} // namespace pb_ds

#endif // #ifndef PB_DS_JOIN_TEST_HPP

