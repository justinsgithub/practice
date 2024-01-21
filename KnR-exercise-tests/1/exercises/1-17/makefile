LIBS = -lm

CFLAGS  = -std=c99
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror
CFLAGS += -Wmissing-declarations
CFLAGS += -DUNITY_SUPPORT_64 -DUNITY_OUTPUT_COLOR

ASANFLAGS  = -fsanitize=address
ASANFLAGS += -fno-common
ASANFLAGS += -fno-omit-frame-pointer


# runs memcheck, tests, and cleans up after.
.PHONY: test
test: memcheck dirty_test clean

# runs test with no memcheck or clean up (hence dirty)
.PHONY: dirty_test
dirty_test: tests.out
	@echo '*** Test begin ***'
	@./tests.out
	@echo '*** Test end ***'
	@echo ""

# tests for memory leaks
.PHONY: memcheck
memcheck: ./*.c ./*.h
	@echo '*** Memory check begin ***'
	@$(CC) $(ASANFLAGS) $(CFLAGS) ../../../test-framework/unity.c ./*.c -o memcheck.out $(LIBS)
	@./memcheck.out
	@echo '*** Memory check end ***'
	@echo ""

# cleans up output / object files
.PHONY: clean
clean:
	rm -rf *.o *.out *.out.dSYM

# compiles test
tests.out: ./*.c ./*.h
	@$(CC) $(CFLAGS) ../../../test-framework/unity.c ./*.c -o tests.out $(LIBS)
