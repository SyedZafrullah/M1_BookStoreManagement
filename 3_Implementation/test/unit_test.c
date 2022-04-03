#include "inc.h"
#include "unity.h"
#include "unity_internals.h"
#include "unity.c"
#include "adminfunction.c"
#include "customerfunction.c"

#define PASS 1
#define FAIL 0

extern void manual_test();

/**
 * @brief required by unit test framework
 *
 */
void setup()
{

}
/**
 * @brief required by unit test framework
 *
 */
void teardown()
{

}


/**
 * @brief test function to test the structure members
 *
 */


 void test_addBook(void)
 {
     TEST_ASSERT_EQUAL(PASS,addBook());
 }
 void test_showAllBooks(void)
 {
     TEST_ASSERT_EQUAL(PASS,showAllBooks());
 }
 void test_eraseBooks(void)
 {
     TEST_ASSERT_EQUAL(PASS,eraseBooks());
 }
 void test_requestBook(void)
 {
     TEST_ASSERT_EQUAL(PASS,requestBook());
 }
 void test_seeRequest(void)
 {
     TEST_ASSERT_EQUAL(PASS,seeRequest());
 }

 int main()
 {
    manual_test_checking();
    manual_test_pass();
    manual_test_login();
    UnityBegin(NULL);
    RUN_TEST(test_addBook);
    RUN_TEST(test_showCheckMenu);
    RUN_TEST(test_eraseBooks);
    RUN_TEST(test_requestBook);
    RUN_TEST(test_seeRequest);
    return (UnityEnd());

 }
