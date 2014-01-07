# weizili@360.cn 

CC=gcc
CXX=g++
CFLAGS= -g -c -D_DEBUG -fPIC -Wshadow -Wcast-qual -Wcast-align -Wwrite-strings -Wsign-compare -Winvalid-pch -fms-extensions -Wall -MMD
CPPFLAGS=$(CFLAGS) -Woverloaded-virtual -Wsign-promo -fno-gnu-keywords 

SRCS := $(wildcard *.cc) $(wildcard proxy_url/*.cc)
OBJS := $(patsubst %.cc, %.o, $(SRCS))
DEPS := $(patsubst %.o, %.d, $(OBJS))

TARGET=unittest_proxy_url

all : $(TARGET) 

check : $(TARGET)
	./$^

$(TARGET) : $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

-include $(DEPS)

%.o : %.cc
	$(CXX) $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	rm -rf *.o *.d $(OBJS) $(DEPS) $(TARGET) 

