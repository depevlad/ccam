#pragma once

#include <array>
#include <algorithm>

#include "BException.h"

template <typename Key, typename Value, std::size_t Size>
struct Map {
  std::array<std::pair<Key, Value>, Size> data;

  [[nodiscard]] constexpr Value at(const Key key) const {
    const auto it = 
      std::find_if(begin(data), end(data),
        [&key](const auto &v) { return v.first == key; });
    if (it != end(data)) {
      return it->second;
    } else {
      throw std::range_error("Key not found");
    }
  }

  [[nodiscard]] constexpr std::size_t size() const { 
    return data.size(); 
  }
};