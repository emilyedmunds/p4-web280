// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "List.h"
#include "unit_test_framework.h"

using namespace std;

// Add your test cases here
//either going to be working with beginning of a list, end of a list,or somewhere in between
//call insert at begining or edge at the end of list
//consider list of size 1 (because first and last are the same)
//consider list of size 2 (because first and last are the only two nodes in the list
//iterators are very helpful here because you can get access to any node you want and call functions on it
//want to see if you are deleting properly? create an iterator for a node, erase it, and then see what it points to
//iterate thru a list to test size
//insert an element, iterate until you find it
//RUN VALGRIND!!!
//declaring iterator in test case: List<T>::Iterator i;
TEST(test_stub) {
    // Add test code here
    ASSERT_TRUE(true);
}
TEST(test_ctor) {
    List<int> empty;
    ASSERT_TRUE(empty.empty());
    ASSERT_EQUAL(0,empty.size());
}
TEST(test_ctor_nonEmpty){
    List<int> lst;
    lst.push_front(1);
    lst.push_front(2);
    lst.push_front(3);
    ASSERT_TRUE(lst.size() == 3);
}
TEST(test_iterator) {
    List<int> lst;
    lst.push_front(1);
    lst.push_front(2);
    lst.push_front(3);
    List<int>::Iterator i = lst.begin();
    lst.insert(i, 9);
    ASSERT_EQUAL(lst.front(),9);
}

TEST_MAIN()
