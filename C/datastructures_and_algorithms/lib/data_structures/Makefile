objects = queue.o stack.o

$(LIBDIR)/libdata_structures.so: $(objects) | $(LIBDIR)/libwrappers.so
	cc -shared -o $@ $(objects) -lwrappers

$(objects): %.o : %.c data_structures.h wrappers.h
	cc -c -fPIC -o $@ $<

.PHONY: $(LIBDIR)/libwrappers.so
$(LIBDIR)/libwrappers.so:
	$(MAKE) -C $(LIBDIR)/wrappers/
