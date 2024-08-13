.DEFAULT_GOAL := all
BUILD_DIR=build
SSBUILD_DIR=ss_build
BINARY_NAME=top_pipelined
SUPERSCALAR_NAME=top_superscalar
BSC_FLAGS=--aggressive-conditions --show-schedule -vdir $(BUILD_DIR) -bdir $(BUILD_DIR) -simdir $(BUILD_DIR) -o 

.PHONY: clean all $(BINARY_NAME) $(SSBUILD_DIR)

$(BINARY_NAME):
	mkdir -p $(BUILD_DIR)
	bsc $(BSC_FLAGS) $@ -sim -g mk$@ -u $@.bsv
	bsc $(BSC_FLAGS) $@ -sim -e mk$@

$(SUPERSCALAR_NAME):
	mkdir -p $(SSBUILD_DIR)
	bsc $(BSC_FLAGS) $@ -sim -g mk$@ -u $@.bsv
	bsc $(BSC_FLAGS) $@ -sim -e mk$@

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(SSBUILD_DIR)
	rm -f $(BINARY_NAME)
	rm -f $(SUPERSCALAR_NAME)
	rm -f *.so
	rm -f *.sched

all: clean $(BINARY_NAME) $(SUPERSCALAR_NAME)

submit:
	make all
	./test_all_pipelined.sh 2>&1 | tee output_submit.txt 
	git add -A
	git commit -am "Save Changes & Submit"
	git push
