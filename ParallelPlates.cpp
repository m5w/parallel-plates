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

#include <cmath>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  if (argc != 8)
    throw;

  const long double LENGTH = std::stold(argv[1]), WIDTH = std::stold(argv[2]),
                    HEIGHT = std::stold(argv[3]);
  const long double HEIGHT_SQUARED = std::pow(HEIGHT, 2.0l);
  const long double DELTA_X_1 = LENGTH / std::pow(2.0l, std::stoull(argv[4])),
                    DELTA_Y_1 = WIDTH / std::pow(2.0l, std::stoull(argv[5])),
                    DELTA_X_2 = LENGTH / std::pow(2.0l, std::stoull(argv[6])),
                    DELTA_Y_2 = WIDTH / std::pow(2.0l, std::stoull(argv[7]));
  const long double DELTA = DELTA_X_1 * DELTA_Y_1 * DELTA_X_2 * DELTA_Y_2;
  long double force_z = 0.0l;

  for (long double x_1 = 0.0l; x_1 < LENGTH; x_1 += DELTA_X_1) {
    for (long double y_1 = 0.0l; y_1 < WIDTH; y_1 += DELTA_Y_1) {
      for (long double x_2 = 0.0l; x_2 < LENGTH; x_2 += DELTA_X_2) {
        for (long double y_2 = 0.0l; y_2 < WIDTH; y_2 += DELTA_Y_2) {
          force_z -= HEIGHT * DELTA /
                     std::pow(std::pow(x_2 - x_1, 2.0l) +
                                  std::pow(y_2 - y_1, 2.0l) + HEIGHT_SQUARED,
                              1.5l);
        }
      }
    }
  }

  std::cout << "𝐅₁₂ = " << force_z << " · C · 𝐤\n";
}
