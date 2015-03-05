## Process this file with automake to produce Makefile.in
CFLAGS = -Wall -Werror -std=c99

TESTS = check_test
check_PROGRAMS = check_test
check_magic_square_SOURCES = check_test.c $(top_builddir)/src/treenode.h
check_magic_square_CFLAGS = @CHECK_CFLAGS@
check_magic_square_LDADD = $(top_builddir)/src/practical_c2.la @CHECK_LIBS@