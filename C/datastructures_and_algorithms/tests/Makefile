export HEADERDIR = $(abspath ../headers/)
vpath %.h $(HEADERDIR) # Set search directory for header files for Make
export LIBDIR = $(abspath ../lib) # Specify directory for shared libraries
export CFLAGS += -Wall -Wl,-rpath=$(LIBDIR) -L$(LIBDIR) -iquote$(HEADERDIR)
# -Wall:	Display all warnings
#  -Wl,-rpath=	Set shared library dir for linker
#  -L		Set shared library dir for compiler
#  -I		Set header dir

SUBDIRS = data_structures_tests #graphs_tests sorting_and_searching_tests
.PHONY: subdirs $(SUBDIRS)

subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@
