/* -*- c++ -*- */

#define EVERT_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "evert_swig_doc.i"

%{
#include "evert/prbs_b.h"
#include "evert/compare_ffb.h"
%}


%include "evert/prbs_b.h"
GR_SWIG_BLOCK_MAGIC2(evert, prbs_b);

%include "evert/compare_ffb.h"
GR_SWIG_BLOCK_MAGIC2(evert, compare_ffb);
