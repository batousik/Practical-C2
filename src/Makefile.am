# Source Makefile.am
# Process this file with automake to produce Makefile.in
# Whatever flags you want to pass to the C compiler & linker
CFLAGS = -Wall -Werror -std=c99


###################
lib_LTLIBRARIES = libpractical_trees.la
libpractical_trees_la_SOURCES = treenode.h treenode.c main.c practical_trees.c

bin_PROGRAMS = $(top_builddir)/bin/practical_trees
practical_trees_SOURCES = practical_trees.c
practical_trees_LDADD = libpractical_trees.la