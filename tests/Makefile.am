## Process this file with automake to produce Makefile.in
CFLAGS = -Wall -Werror -std=c99

TESTS = check_test
check_PROGRAMS = check_test
check_test_SOURCES = check_test.c $(top_builddir)/src/treenode.h
check_test_CFLAGS = @CHECK_CFLAGS@
check_test_LDADD = $(top_builddir)/src/tree_programm.la @CHECK_LIBS@