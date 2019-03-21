.PHONY: clean 
HTTPSPROXY = ../obj/hpy
PRODUCTS = $(HTTPSPROXY)
default: $(PRODUCTS)

OBJDIR = ../obj

include collections/makefile
include core/makefile
include utils/makefile
include utils/args/makefile
include logging/makefile

include unittest/makefile
include unittest/utils/makefile
include unittest/utils/args/makefile
include unittest/logging/makefile
include unittest/core/makefile

# OBJS can deal with either .cc or .c 
OBJS = $(OBJDIR)/hpy_threadsafe_queue.o 
OBJS += $(OBJDIR)/hpy_httpmessage.o $(OBJDIR)/hpy_handler.o $(OBJDIR)/hpy_proxy.o 
OBJS += $(OBJDIR)/hpy_encryption.o $(OBJDIR)/hpy_decryption.o  
OBJS += $(OBJDIR)/hpy_config.o $(OBJDIR)/hpy_logging.o 
OBJS += $(OBJDIR)/hpy_stringutil.o
OBJS += $(OBJDIR)/hpy_options.o $(OBJDIR)/hpy_args.o $(OBJDIR)/hpy_option_error.o
OBJS += $(OBJDIR)/hpy_main.o

JUNK = *~ $(OBJDIR)/*.o $(OBJDIR)/*.a  

# Define the tools we are going to use
CC= g++
LD = g++

CFLAGS = -g -Wall -Wno-unused -Wno-sign-compare -std=c++11 -I.

LIBS = -lm -lc -lpthread

$(OBJDIR)/hpy_main.o: hpy_main.cc
	$(CC) $(CFLAGS) -c -o $@ $<

$(PRODUCTS): $(OBJS)     
	$(LD) -o $@  $^  $(LIBS)
	cp $(PRODUCTS) ./

start-client: $(PRODUCTS)
	@nohup $(PRODUCTS) --run-as-client -i 144.202.122.84 &
	@netstat -lpn | grep "hpy" | grep "^tcp" 

stop-client: $(PRODUCTS)
	@for pid in `ps -ef | grep '../obj/hpy' | grep -v 'grep' | tr -s " " | cut -d " " -f 2`; do echo "kill "$${pid}; kill $${pid}; done

start-server: $(PRODUCTS)
	@nohup $(PRODUCTS) --run-as-server &
	@netstat -lpn | grep "hpy" | grep "^tcp" 

stop-server: $(PRODUCTS)
	@for pid in `ps -ef | grep '../obj/hpy' | grep -v 'grep' | tr -s " " | cut -d " " -f 2`; do echo "kill "$${pid}; kill $${pid}; done


#unittest,using googletest:https://github.com/google/googletest/blob/master/googletest/docs/Primer.md
#this make no sense, and just test googletest
UNITTEST = ut-utils-stringutil

ut-utils-stringutil: $(OBJDIR)/hpy_stringutil_ut
	./$(OBJDIR)/hpy_stringutil_ut

ut-utils-args: $(OBJDIR)/hpy_args_ut
	./$(OBJDIR)/hpy_args_ut

ut-logging-logging: $(OBJDIR)/hpy_logging_ut 
	./$(OBJDIR)/hpy_logging_ut  

ut-logging-config: $(OBJDIR)/hpy_config_ut
	./$(OBJDIR)/hpy_config_ut

ut-core-handler: $(OBJDIR)/hpy_handler_ut
	./$(OBJDIR)/hpy_handler_ut

ut-core-httpmessage: $(OBJDIR)/hpy_httpmessage_ut
	./$(OBJDIR)/hpy_httpmessage_ut

ut-core-encryption: $(OBJDIR)/hpy_encryption_ut
	./$(OBJDIR)/hpy_encryption_ut

clean:
	@rm -rf $(JUNK) $(PRODUCTS) ./hpy $(OBJDIR)


