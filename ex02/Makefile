CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

VECTOR_NAME = ex02_vector
VECTOR_SRC = main_vector.cpp PmergeMe_vector.cpp
VECTOR_OBJ = $(VECTOR_SRC:.cpp=.o)


DEQUE_NAME = ex02_deque
DEQUE_SRC = main_deque.cpp PmergeMe_deque.cpp
DEQUE_OBJ = $(DEQUE_SRC:.cpp=.o)





all: $(VECTOR_NAME) $(DEQUE_NAME)

$(VECTOR_NAME): $(VECTOR_OBJ)
	$(CXX) $(CXXFLAGS) $(VECTOR_OBJ) -o $(VECTOR_NAME)

$(DEQUE_NAME): $(DEQUE_OBJ)
	$(CXX) $(CXXFLAGS) $(DEQUE_OBJ) -o $(DEQUE_NAME)




%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(VECTOR_OBJ)
	rm -f $(DEQUE_OBJ)

fclean: clean
	rm -f $(VECTOR_NAME)
	rm -f $(DEQUE_NAME)
re: fclean all

.PHONY: all clean fclean re
