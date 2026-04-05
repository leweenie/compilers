t = main

$(t): main.c lexer.c lexer.h
	gcc main.c lexer.c -o $(t)

run: $(t)
	./$(t)

nv: $(t)
	./$(t) main.nv

clean:
	rm -f $(t)
