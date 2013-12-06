set autoindent
set shiftwidth=2
set number
set cindent
syntax on
set showmatch
set smartindent



map <F9> :call CompileRunGpp()<CR>
func! CompileRunGpp()
exec "w"
exec "!g++ % -o %<"
exec "! ./%<"
endfunc
