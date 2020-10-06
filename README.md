# tictoc

Matlab inspired time measurement for C. Simply include *timemeasure.h*, put `tic()` where measurement should start and `toc()` where it ends. You will get a print to *stdout* containing file, function, line and the time elapsed (real and cpu) between `tic()` and `toc()`.

`tic()`and `toc()`can be nested and the nesting level is included in the *stdout* output.

You can also use a variant of these functions called `tic_msg(`*char**`)` and `toc_msg(`*char**`)` to add an optional text string to tag your measurements. These functions work togeather with `tic()` and `toc()` too in any combination.
