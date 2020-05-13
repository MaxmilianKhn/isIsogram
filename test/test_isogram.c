#include "vendor/unity.h"
#include "../src/isogram.h"
#include "vendor/unity_internals.h"
#include <stdlib.h>

void test_false_isogram(void)
{
   TEST_ASSERT_FALSE(is_isogram("wow"));
    TEST_ASSERT_FALSE(is_isogram("zzu"));
   TEST_ASSERT_FALSE(is_isogram("hdaa"));
}
void test_true_isogram(void){
   TEST_ASSERT_TRUE(is_isogram("Abcdefg"));
}
void test_word_with_upper_and_lower_letter(void){
   TEST_ASSERT_FALSE(is_isogram("Aal"));
   TEST_ASSERT_FALSE(is_isogram("zZl"));
}
void spaces_should_not_count(void){
    TEST_ASSERT_TRUE(is_isogram("Hi das funkt."))
}
void long_non_isograms(void){
    TEST_ASSERT_FALSE(is_isogram("griechisch"));
    TEST_ASSERT_FALSE(is_isogram("Hausaufgaben"));
}
void long_isograms(void){
    TEST_ASSERT_TRUE(is_isogram("Dialogschwerpunkt"));
    TEST_ASSERT_TRUE(is_isogram("Pokalbeschriftung"));
}
void specialSymbols_isograms(void){
    TEST_ASSERT_TRUE(is_isogram("abs!!"));
    TEST_ASSERT_TRUE(is_isogram("?!sgbd?!"));
}
void number_isograms(void){
    TEST_ASSERT_TRUE(is_isogram("0123456789abcdefg"));
    TEST_ASSERT_TRUE(is_isogram("0123456789abcdefg9"));
}
void threeTimesDoubleLetters(void){
    TEST_ASSERT_TRUE(is_isogram("aabbcc"));
    TEST_ASSERT_TRUE(is_isogram("aAbBcC"));
}

int main(void)
{
   UnityBegin("isIsogram");

   RUN_TEST(test_false_isogram);
   RUN_TEST(test_true_isogram);
   RUN_TEST(test_word_with_upper_and_lower_letter);
   RUN_TEST(spaces_should_not_count);
   RUN_TEST(long_non_isograms);
   RUN_TEST(long_isograms);
   RUN_TEST(specialSymbols_isograms);
   RUN_TEST(number_isograms);
   RUN_TEST(threeTimesDoubleLetters);

   UnityEnd();
   return 0;
}
