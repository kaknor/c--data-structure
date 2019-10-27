#include <stdexcept>

class EmptyListException: public std::exception {
  std::string what_message;
public:
  EmptyListException(const char* msg): what_message(msg) {};
  EmptyListException(const std::string& msg): what_message(msg) {};
  const char* what() const throw() override {
    return what_message.c_str();
  }
};
