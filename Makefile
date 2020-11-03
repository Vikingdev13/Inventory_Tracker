repl-build.out: inventory-system_template.c
	gcc -o $@ $^

.PHONY: run
run: repl-build.out input-small.txt
	./$^

.PHONY: clean

clean:
	rm -f repl-build.out