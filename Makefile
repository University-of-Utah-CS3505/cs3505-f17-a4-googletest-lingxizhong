# Osama Kergaye and Ling
# 3505
# u0767339
# Testing and Travis
GOOGLETEST ?= ../googletest/googletest
CC = g++
CFLAGS = -Wall -std=c++11
TrieTest : Trie.o Node.o TrieTest.cpp
	$(CC) -g $(CFLAGS) -o TrieTest Node.o Trie.o TrieTest.cpp
#
Trie.o :  Trie.cpp
	$(CC) -g $(CFLAGS) -c Trie.cpp
#
Node.o :  Node.cpp
	$(CC) -g $(CFLAGS) -c Node.cpp
# add a make clean and make test option
clean:
	rm TrieTest *.o
#
 test: TrieTest
	./TrieTest "$(FILEONE)" "$(FILETWO)"
