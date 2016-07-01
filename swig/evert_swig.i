/* -*- c++ -*- */

#define EVERT_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "evert_swig_doc.i"

%{
#include "evert/prbs_b.h"
%}


%include "evert/prbs_b.h"
GR_SWIG_BLOCK_MAGIC2(evert, prbs_b);
