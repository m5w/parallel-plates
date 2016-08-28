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

#include <iostream>
#include <string>

int main(int argc, char **argv) {
  if (argc != 2)
    throw;

  std::cout << pow<2ull>(std::stold(argv[1])) << '\n';
}
