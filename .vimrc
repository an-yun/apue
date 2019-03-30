
" 编译运行
nnoremap <F5> :w<CR> :call CompileRun()<CR>
func! CompileRun()
    if &filetype == 'c'
        exec "!echo 'clang % -o ./build/%:t:r -I./include && ./build/%:t:r' && clang % -o ./build/%:t:r -I./include && ./build/%:t:r" 
    elseif &filetype == 'cpp'
        exec "!echo 'clang++ % -o ./build/%:t:r -I./include -std=c++17 && ./build/%:t:r' && clang++ % -o ./build/%:t:r -I./include -std=c++17 && ./build/%:t:r" 
    endif
endfunc

