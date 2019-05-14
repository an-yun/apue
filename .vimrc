
" 编译运行
nnoremap <F5> :w<CR> :call CompileRun()<CR>
func! CompileRun()
    if &filetype == 'c'
        let l:run_cmd = "clang % -o ./build/%:t:r -ansi -DLINUX -D_GNU_SOURCE -I./include && ./build/%:t:r"
    elseif &filetype == 'cpp'
        let l:run_cmd = "clang++ % -o ./build/%:t:r -DLINUX -D_GNU_SOURCE -I./include -std=c++17 && ./build/%:t:r"
    endif
    exec "!echo '" . l:run_cmd . "' && " l:run_cmd
endfunc

