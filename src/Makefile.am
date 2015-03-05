## Process this file with automake to produce Makefile.in
# whatever flags you want to pass to the C compiler & linker
CFLAGS = -Wall -Werror -std=c99


###################
lib_LTLIBRARIES = practical_c2.la
practical_c2_la_SOURCES = treenode.h treenode.c main.c

bin_PROGRAMS = $(top_builddir)/bin/tree_programm
main_SOURCES = main.c
main_LDADD = practical_c2.la