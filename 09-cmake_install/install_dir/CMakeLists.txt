# 503install_dir/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)

project(install_dir)

file(WRITE doc/index.html "")
file(WRITE doc/doc.html "")
file(WRITE doc/doc2.htm "")
file(WRITE doc/doc.cc "")
file(WRITE doc/doc.c "")
file(WRITE doc/sub/doc.html "")
file(WRITE doc/include/doc.h "")
file(WRITE doc/.svn/config "")
file(WRITE doc/.git/config "")

# 
# doc 类型 指定安装路径 share/doc
# 安装doc目录下所有文件，包含子目录中 空子目录也创建
install(DIRECTORY doc TYPE DOC)
install(DIRECTORY doc DESTINATION doc2)

# 过滤只复制 *.html 并且创建所有子目录
install(DIRECTORY doc DESTINATION html_doc
FILES_MATCHING
PATTERN "*.html"
PATTERN "*.html"
)

# 排除.git 和 .svn
install(DIRECTORY doc DESTINATION no_git_doc
PATTERN ".git" EXCLUDE

)

install(DIRECTORY doc DESTINATION src 
FILES_MATCHING
PATTERN "*.cc"
PATTERN "*.c"
PATTERN ".git" EXCLUDE
PATTERN ".svn" EXCLUDE
)