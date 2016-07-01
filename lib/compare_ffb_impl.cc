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
#include "compare_ffb_impl.h"

namespace gr {
  namespace evert {

    compare_ffb::sptr
    compare_ffb::make(eCondOp condOp)
    {
      return gnuradio::get_initial_sptr
        (new compare_ffb_impl(condOp));
    }

    /*
     * The private constructor
     */
    compare_ffb_impl::compare_ffb_impl(eCondOp condOp)
      : gr::sync_block("compare_ffb",
              gr::io_signature::make(2, 2, sizeof(float)),
              gr::io_signature::make(1, 1, sizeof(short)))
    {
        m_condOp = condOp;
    }

    /*
     * Our virtual destructor.
     */
    compare_ffb_impl::~compare_ffb_impl()
    {
    }

    int
    compare_ffb_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const float *A = (const float *) input_items[0];
      const float *B = (const float *) input_items[1];
      short *out = (short *) output_items[0];
      
      for (int i=0; i<noutput_items; ++i)
      {
          switch (m_condOp)
          {
              case eEq:
                *out = *A == *B;
              break;
              case eGt:
                *out = *A > *B;
              break;
              case eLt:
                *out = *A < *B;
              break;
              case eEqGt:
                *out = *A >= *B;
              break;
              case eEqLt:
                *out = *A <= *B;
              break;
              
              default:
                *out = 69;
                break;
          }
          ++A;
          ++B;
          ++out;
      }
      
      this->consume(0, noutput_items); //consume port 0 input
      this->consume(1, noutput_items); //consume port 1 input      

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace evert */
} /* namespace gr */

