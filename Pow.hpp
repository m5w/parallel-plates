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

namespace {
template <unsigned long long y, typename T> class Pow {
  static_assert(y != 0ull, "y != 0ull");

public:
  static T pow(const T &x) { return x * Pow<y - 1ull, T>::pow(x); }
};

template <typename T> class Pow<1ull, T> {
public:
  static T pow(const T &x) { return x; }
};
}

template <unsigned long long y, typename T> T pow(const T &x) {
  return Pow<y, T>::pow(x);
}
