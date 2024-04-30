#making dirs
mkdir -p ~/.vim/pack/completion/start/

#getting plugins
git clone https://github.com/xavierd/clang_complete.git ~/.vim/pack/completion/start/clang_complete -q 
git clone https://github.com/preservim/nerdtree.git ~/.vim/pack/vendor/start/nerdtree -q

#config
cp .vimrc ~/.vimrc
vim -u NONE -c "helptags ~/.vim/pack/vendor/start/nerdtree/doc" -c q

