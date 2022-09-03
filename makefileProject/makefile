vpath %.o objects
vpath %.h include
vpath %.c sources;sources/c
vpath %.cpp sources;sources/cpp; sources/cpp/leetcode; sources/exam \
		sources/cpp/multiThread/thread \
		sources/cpp/multiThread/atomic_mutex \
		sources/cpp/multiThread/async \
		sources/cpp/multiThread/future \
		sources/cpp/multiThread/promise \



cc = g++
suffix = .cpp
ifeq ($(cc), gcc)
	suffix := .c
endif

target = dj
rely = 
depends = $(target:%=%.o) $(rely:%=%.o)

$(target).exe : $(depends)
	$(cc) -o $@ $(depends:%=objects/%)
	@echo $@
	@echo $<
	@echo $^


$(depends) : %.o : %$(suffix)
	$(cc) -c $< -o objects/$@ -Iinclude
	$(cc) -MM $<


.PHONY : objs
objs : $(depends)

.PHONY : cleanall cleanexe cleanobj
cleanall : cleanexe cleanobj
cleanexe :
	del *.exe
cleanobj :
	del .\objects\*.o
