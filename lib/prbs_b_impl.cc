/* -*- c++ -*- */
/* 
 * Copyright 2016 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "prbs_b_impl.h"

namespace gr {
  namespace evert {

    prbs_b::sptr
    prbs_b::make(char prbs_type)
    {
      return gnuradio::get_initial_sptr
        (new prbs_b_impl(prbs_type));
    }

    /*
     * The private constructor
     */
    prbs_b_impl::prbs_b_impl(char prbs_type)
      : gr::sync_block("prbs_b",
              gr::io_signature::make(0, 0, 0),
              gr::io_signature::make(1, 1, sizeof(char)))
    {
       m_a = 0x02;
       m_type = prbs_type;
    }

    /*
     * Our virtual destructor.
     */
    prbs_b_impl::~prbs_b_impl()
    {
    }

    int
    prbs_b_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      char *out = (char *) output_items[0];

      if (m_type < 0 || m_type > 3)
         m_type = 0;
      switch (m_type)
      {
			case 0:  // PRBS7
				for (int i=0; i<noutput_items; ++i)
				{
					*out = (((m_a >> 6) ^ (m_a >> 5)) & 1);
					m_a = ((m_a << 1) | *out) & 0x7fffffff;
					++out;
				}
				break;
				
			case 1:  // PRBS15
				for (int i=0; i<noutput_items; ++i)
				{
					*out = (((m_a >> 14) ^ (m_a >> 15)) & 1);
					m_a = ((m_a << 1) | *out) & 0x7fffffff;
					++out;
				}
				break;

			case 2:  // PRBS23
				for (int i=0; i<noutput_items; ++i)
				{
					*out = (((m_a >> 22) ^ (m_a >> 17)) & 1);
					m_a = ((m_a << 1) | *out) & 0x7fffffff;
					++out;
				}
				break;

			case 3:  // PRBS31
				for (int i=0; i<noutput_items; ++i)
				{
					*out = (((m_a >> 30) ^ (m_a >> 27)) & 1);
					m_a = ((m_a << 1) | *out) & 0x7fffffff;
					++out;
				}
				break;
      }

      // Tell runtime system how many output items we produced.
      consume_each (noutput_items);
      return noutput_items;
    }

  } /* namespace evert */
} /* namespace gr */

