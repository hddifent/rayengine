#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <stdexcept>

class index_out_of_range_exception : public std::runtime_error {
public:
    explicit index_out_of_range_exception()
        : runtime_error("Index out of range.") {
    }

    ~index_out_of_range_exception() noexcept override;

    [[nodiscard]] const char * what() const noexcept override;
};

#endif //EXCEPTIONS_H
