#pragma once

#include <cstddef>
#include <optional>
#include <stdexcept>
#include <vector>

template <typename Tp> class Picker {
private:
  const std::vector<Tp> _vec;
  const size_t _size;
  size_t _i = 0;
  Tp _tp;

public:
  inline explicit Picker<Tp>(const std::vector<Tp> &vec) : _vec(vec), _size(vec.size()) {
    if (!pick().has_value())
      throw std::runtime_error("There are no items into vector!");
  };

  inline std::vector<Tp> vec() const { return _vec; };
  inline size_t index() const { return _i; };
  inline size_t size() const { return _size; };
  inline Tp data() const { return _tp; };

  inline void jump(size_t i = 1) { _i += i; };
  inline void back(size_t i = 1) { _i -= i; };

  inline std::optional<Tp> pick(size_t i) {
    if (i >= _size)
      return std::nullopt;
    _tp = _vec[i];
    return _tp;
  }

  inline std::optional<Tp> pick() { return pick(_i); }

  inline std::optional<Tp> next(size_t i = 1) {
    jump(i);
    return pick();
  };

  inline std::optional<Tp> previous(size_t i = 1) {
    back(i);
    return pick();
  };
};