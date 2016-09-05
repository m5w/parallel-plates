// This file is part of Parallel Plates.
//
// Parallel Plates is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.
//
// Parallel Plates is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
// more details.
//
// You should have received a copy of the GNU General Public License along with
// Parallel Plates.  If not, see <http://www.gnu.org/licenses/>.

#include "Pow.hpp"

#include <cmath>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  if (argc != 8)
    throw;

  const long double LENGTH = std::stold(argv[1]), WIDTH = std::stold(argv[2]),
                    HEIGHT = std::stold(argv[3]);
  const long double HEIGHT_SQUARED = pow<2ull>(HEIGHT);
  const unsigned long long N_X_1 = 1ull << std::stoull(argv[4]),
                           N_Y_1 = 1ull << std::stoull(argv[5]),
                           N_X_2 = 1ull << std::stoull(argv[6]),
                           N_Y_2 = 1ull << std::stoull(argv[7]);
  const long double DELTA_X_1 = LENGTH / N_X_1, DELTA_Y_1 = WIDTH / N_Y_1,
                    DELTA_X_2 = LENGTH / N_X_2, DELTA_Y_2 = WIDTH / N_Y_2;
  const long double NUMERATOR =
      HEIGHT * DELTA_X_1 * DELTA_Y_1 * DELTA_X_2 * DELTA_Y_2;
  long double force_z = 0.0l;

  long double x_1 = 0.0l;

  for (unsigned long long n_x_1 = 0ull; n_x_1 != N_X_1;
       ++n_x_1, x_1 = DELTA_X_1 * n_x_1) {
    long double y_1 = 0.0l;

    for (unsigned long long n_y_1 = 0ull; n_y_1 != N_Y_1;
         ++n_y_1, y_1 = DELTA_Y_1 * n_y_1) {
      long double x_2 = 0.0l;

      for (unsigned long long n_x_2 = 0ull; n_x_2 != N_X_2;
           ++n_x_2, x_2 = DELTA_X_2 * n_x_2) {
        long double y_2 = 0.0l;

        for (unsigned long long n_y_2 = 0ull; n_y_2 != N_Y_2;
             ++n_y_2, y_2 = DELTA_Y_2 * n_y_2) {
          force_z -=
              NUMERATOR * std::pow(pow<2ull>(x_2 - x_1) + pow<2ull>(y_2 - y_1) +
                                       HEIGHT_SQUARED,
                                   -1.5l);
        }
      }
    }
  }

  std::cout << force_z << '\n';
}
