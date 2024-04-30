#making dirs
mkdir -p ~/.vim/pack/completion/start/

#getting plugins
git clone https://github.com/xavierd/clang_complete.git ~/.vim/pack/completion/start/clang_complete -q 
git clone https://github.com/preservim/nerdtree.git ~/.vim/pack/vendor/start/nerdtree -q
git clone --depth=1 https://github.com/bfrg/vim-cpp-modern ~/.vim/pack/cpp_syntax_highlighting/start/vim_cpp_modern -q
git clone --depth=1 https://github.com/ervandew/supertab.git ~/.vim/pack/plugins/start/supertab -q
git clone https://tpope.io/vim/fugitive.git ~/.vim/pack/tpope/start/fugitive -q
git clone --depth=1 https://github.com/ervandew/supertab.git ~/.vim/pack/plugins/start/supertab -q

#config
cp .vimrc ~/.vimrc
NE -c "helptags fugitive/doc" -c q
vim -u none -c "helptags ~/.vim/pack/vendor/start/nerdtree/doc" -c q

