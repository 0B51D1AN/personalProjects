#!/usr/bin/julia

function fact(n)
   if ( n < 0 )
     return -1
   elseif ( n == 0 || n == 1 )
     return 1
   else
     return n*fact(n-1)
   end
end

# Here is the main program, note I have to convert the
# string command line argument to an Int64

println(fact(parse(Int64,ARGS[1])))
exit(0)

