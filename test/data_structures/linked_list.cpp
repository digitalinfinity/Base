#include "stdafx.h"
#include "data_structures\linked_list.h"

class IntLinkedListTest : public ::testing::Test {
 protected:
  LinkedList<int> m_list;
};

TEST_F(IntLinkedListTest, IsEmptyInitially) {
	EXPECT_EQ(0, m_list.Count());
}

TEST_F(IntLinkedListTest, AddWorks) {
	EXPECT_EQ(0, m_list.Count());
	m_list.AddToFront(0);
	EXPECT_EQ(1, m_list.Count());

	m_list.AddToFront(1);
	EXPECT_EQ(2, m_list.Count());

	m_list.AddToFront(2);
	EXPECT_EQ(3, m_list.Count());

	ASSERT_TRUE(m_list.Contains(0));
	ASSERT_TRUE(m_list.Contains(1));
	ASSERT_TRUE(m_list.Contains(2));
	ASSERT_FALSE(m_list.Contains(3));
	ASSERT_FALSE(m_list.Contains(4));
	ASSERT_FALSE(m_list.Contains(5));
}

TEST_F(IntLinkedListTest, RemoveWorks) {
    EXPECT_EQ(0, m_list.Count());
	m_list.AddToFront(0);
	EXPECT_EQ(1, m_list.Count());

	m_list.AddToFront(1);
	EXPECT_EQ(2, m_list.Count());

	m_list.AddToFront(2);
	EXPECT_EQ(3, m_list.Count());

	ASSERT_TRUE(m_list.Contains(1));
	m_list.RemoveOne(1);
	ASSERT_FALSE(m_list.Contains(1));
	EXPECT_EQ(2, m_list.Count());

	ASSERT_TRUE(m_list.Contains(2));
	m_list.RemoveOne(2);
	ASSERT_FALSE(m_list.Contains(2));
	EXPECT_EQ(1, m_list.Count());

	ASSERT_TRUE(m_list.Contains(0));
	m_list.RemoveOne(0);
	ASSERT_FALSE(m_list.Contains(0));
	EXPECT_EQ(0, m_list.Count());
}