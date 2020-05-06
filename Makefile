SRCS:=$(wildcard *.cc)
TARGETS:=$(SRCS:%.cc=%)
CFLAGS:=-Wall
all:$(TARGETS)
	@for i in $(TARGETS);do g++ -o $${i} $${i}.cc;done
.PYONY:clean
clean:
	rm -rf $(TARGETS)
