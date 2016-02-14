/* 
# Copyright (C) 2013-2016 Martin Drees
#
# This file is part of darch.
#
# darch is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# darch is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with darch. If not, see <http://www.gnu.org/licenses/>.
*/

#include <Rcpp.h>
using namespace Rcpp;

// edits in-place
// [[Rcpp::export]]
void ditherCpp(NumericMatrix data)
{
  int ncols = data.ncol();
  NumericVector column, dither;
  float sdColumn, variance;

  for (int i = 0; i < ncols; i++)
  {
    column = data.column(i);
    sdColumn = sd(column);
    variance = sdColumn * sdColumn;
    dither = runif(ncols, -variance, variance);
    data(_, i) = column + dither;
  }
}
